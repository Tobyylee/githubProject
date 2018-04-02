#include "lyParConfig.h"
#include <QDebug>
#include <QTextCodec>

lyParConfig::lyParConfig(const QString& path, QSettings::Format format /*= QSettings::IniFormat*/, QObject* parent /*= NULL*/)
	: lyConfig(path, format, parent)
{

}

lyParConfig::~lyParConfig(void)
{

}

void lyParConfig::ReadConfig()
{
	QString l_str_Assign;
	GetValue("/MesTpye_Assign/Name", l_str_Assign);
	m_MesTypes_Assign = l_str_Assign.split(QRegExp("[/]"));
	for (int i = 0; i < m_MesTypes_Assign.size(); i++)
	{
		if (m_MesTypes_Assign.at(i).isEmpty())
		{
			m_MesTypes_Assign.removeAt(i);
		}
	}
	QString l_str_Meet;
	GetValue("/MesTpye_Meet/Name", l_str_Meet);
	m_MesTypes_Meet = l_str_Meet.split(QRegExp("[/]"));
	for (int i = 0; i < m_MesTypes_Meet.size(); i++)
	{
		if (m_MesTypes_Meet.at(i).isEmpty())
		{
			m_MesTypes_Meet.removeAt(i);
		}
	}
}

void lyParConfig::WriteConfig()
{
	QString l_str_Assign;
	for (int i = 0; i < m_MesTypes_Assign.size(); i++)
	{
		l_str_Assign += m_MesTypes_Assign.at(i) + QString("/");
	}
	SetValue("/MesTpye_Assign/Name", l_str_Assign);
	QString l_str_Meet;
	for (int i = 0; i < m_MesTypes_Meet.size(); i++)
	{
		l_str_Meet += m_MesTypes_Meet.at(i) + QString("/");
	}
	SetValue("/MesTpye_Meet/Name", l_str_Meet);
}

