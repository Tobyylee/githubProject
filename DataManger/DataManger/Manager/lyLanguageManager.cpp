#pragma once
#include "lyLanguageManager.h"
#include <QDir>

map<string, vector<QTranslator*>*>* lyLanguageManager::m_sLanguages = NULL;

lyLanguageManager::lyLanguageManager()
{

}

lyLanguageManager::~lyLanguageManager()
{

}

std::vector<QTranslator*>* lyLanguageManager::ReadAllTranslatorFile(const string& dir)
{
	LanguageInit();
	QDir l_dir(QString::fromStdString(dir));
	if (!l_dir.exists())
	{
		return NULL;
	}

	QStringList l_filters;
	l_filters << QString("*.qm");
	l_dir.setFilter(QDir::Files | QDir::NoSymLinks);
	l_dir.setNameFilters(l_filters);

	QFileInfoList l_list = l_dir.entryInfoList();
	int l_fileCount = l_list.count();
	if (l_fileCount <= 0)
	{
		return NULL;
	}

	vector<QTranslator*>*l_pTranslator = new vector<QTranslator*>;
	for (int i = 0; i < l_fileCount; i++)
	{
		QFileInfo l_fileInfo = l_list.at(i);
		QTranslator* l_pItem = new QTranslator();
		QString l_strPath = l_fileInfo.absoluteFilePath();
		l_pItem->load(l_strPath);
		l_pTranslator->push_back(l_pItem);
	}

	return l_pTranslator;
}

bool lyLanguageManager::AddTranslator(vector<QTranslator*>* list, const string& mark)
{
	LanguageInit();
	if (list != NULL)
	{
		vector<QTranslator*>*l_pTranslator = GetTranslator(mark);
		if (l_pTranslator == NULL)
		{
			(*m_sLanguages)[mark] = list;
			return true;
		}
	}
	return false;
}

std::vector<QTranslator*>* lyLanguageManager::GetTranslator(const string& mark)
{
	LanguageInit();
	map<string, vector<QTranslator*>*>::iterator it = m_sLanguages->find(mark);
	if (it != m_sLanguages->end())
	{
		return it->second;
	}

	return NULL;
}

void lyLanguageManager::DeleteTranslator(const string& mark)
{
	LanguageInit();

	map<string, vector<QTranslator*>*>::iterator it = m_sLanguages->find(mark);
	if (it != m_sLanguages->end())
	{
		vector<QTranslator*>*  l_pValueVec = it->second;

		for (int i = 0; i < l_pValueVec->size(); i++)
		{
			QTranslator* l_pItem = l_pValueVec->at(i);
			if (l_pItem != NULL)
			{
				delete l_pItem;
			}
		}
		delete l_pValueVec;

		m_sLanguages->erase(it);
	}
}

void lyLanguageManager::DeleteAllTranslator()
{
	LanguageInit();
	map<string, vector<QTranslator*>*>::iterator it;

	if (m_sLanguages->size())
	{
		for (it = m_sLanguages->begin(); it != m_sLanguages->end(); it++)
		{
			string l_mark = it->first;
			//DeleteTranslator(l_mark);

			vector<QTranslator*>*  l_pValueVec = it->second;
			for (int i = 0; i < l_pValueVec->size(); i++)
			{
				QTranslator* l_pItem = l_pValueVec->at(i);
				if (l_pItem != NULL)
				{
					delete l_pItem;
				}
			}
			l_pValueVec->clear();
			delete l_pValueVec;
			l_pValueVec = NULL;
		}
	}

	m_sLanguages->clear();
	delete m_sLanguages;
	m_sLanguages = NULL;
}

void lyLanguageManager::LanguageInit()
{
	if (m_sLanguages == NULL)
	{
		m_sLanguages = new map<string, vector<QTranslator*>*>;
	}
}

