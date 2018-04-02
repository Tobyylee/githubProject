#include "lyThemeManager.h"
#include <QDir>
#include <QDirIterator>

map<std::string, std::string>* lyThemeManager::m_sThemes = nullptr;

lyThemeManager::lyThemeManager()
{

}

lyThemeManager::~lyThemeManager()
{

}

std::string lyThemeManager::ReadAllQssFile(const string& dir)
{
	ThemeInit();

	string l_allQssStr = "";
	QDir l_dir(QString::fromStdString(dir));
	if (!l_dir.exists())
	{
		return "";
	}

	QStringList l_filters;
	l_filters << QString("*.qss");

	QDirIterator l_dirIterator(QString::fromStdString(dir), l_filters, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
	QStringList l_fileDirList;
	while (l_dirIterator.hasNext())
	{
		l_dirIterator.next();
		QFileInfo l_fileInfo = l_dirIterator.fileInfo();
		QString l_fileDir = l_fileInfo.absoluteFilePath();
		l_fileDirList.append(l_fileDir);
	}

	if (l_fileDirList.isEmpty())
	{
		return "";
	}

	for (int i = 0; i < l_fileDirList.size(); i++)
	{
		QString l_strPath = l_fileDirList.at(i);

		QFile l_file(l_strPath);

		if (l_file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QByteArray l_data = l_file.readAll();

			string l_style = l_data.data();
			l_allQssStr += l_style;
			l_file.close();
		}
	}
	return l_allQssStr;
}

bool lyThemeManager::AddTheme(const string& qss, const string& mark)
{
	ThemeInit();
	string l_egist = GetTheme(mark);
	if (l_egist.empty())
	{
		(*m_sThemes)[mark] = qss;
		return true;
	}

	return false;
}

std::string lyThemeManager::GetTheme(const string& mark)
{
	ThemeInit();
	map<string, string>::iterator it = m_sThemes->find(mark);
	if (it != m_sThemes->end())
	{
		return it->second;
	}

	return "";
}

void lyThemeManager::DeleteTheme(const string& mark)
{
	ThemeInit();
	map<string, string>::iterator it = m_sThemes->find(mark);
	if (it != m_sThemes->end())
	{
		m_sThemes->erase(it);
	}
}

void lyThemeManager::DeleteAllTheme()
{
	if (m_sThemes != NULL)
	{
		m_sThemes->clear();
		delete m_sThemes;
		m_sThemes = NULL;
	}
}

void lyThemeManager::ThemeInit()
{
	if (m_sThemes == NULL)
	{
		m_sThemes = new map<string, string>;
	}
}



