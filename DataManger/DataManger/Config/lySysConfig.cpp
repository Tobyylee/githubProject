#include "lySysConfig.h"

lySysConfig::lySysConfig(const QString& path, QSettings::Format format /*= QSettings::IniFormat*/, QObject* parent /*= NULL*/)
	: lyConfig(path, format, parent)
{

}

lySysConfig::~lySysConfig(void)
{

}

void lySysConfig::ReadConfig()
{
	GetValue("/Language/Name", m_languageName);
	GetValue("/Language/Root", m_languageRoot);

	GetValue("/Theme/Name", m_themeName);
	GetValue("/Theme/Root", m_themeRoot);

	GetValue("/CityConfig/Root", m_cityConfigPath);
	GetValue("/DatabasePath/Root", m_dataBasePath);
}

void lySysConfig::WriteConfig()
{
	CreateConfigFile();
	SetValue("/Language/Name", m_languageName);
	SetValue("/Language/Root", m_languageRoot);

	SetValue("/Theme/Name", m_themeName);
	SetValue("/Theme/Root", m_themeRoot);

	SetValue("/CityConfig/Root", m_cityConfigPath);
	SetValue("/DatabasePath/Root", m_dataBasePath);
}
