#pragma once

#include "lyConfig.h"

class lySysConfig : public lyConfig
{
public:
	lySysConfig(const QString& path, QSettings::Format format = QSettings::IniFormat, QObject* parent = NULL);
	virtual ~lySysConfig(void);

	void ReadConfig();
	void WriteConfig();

public:
	QString m_languageName;			//语言名字
	QString m_languageRoot;			//语言的根目录

	QString m_themeName;			//主题名字		
	QString m_themeRoot;			//主题的根目录

	QString m_dataBasePath;			//数据库路径
	QString m_cityConfigPath;		//城市配置路径
};