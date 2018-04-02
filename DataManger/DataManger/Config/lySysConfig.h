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
	QString m_languageName;			//��������
	QString m_languageRoot;			//���Եĸ�Ŀ¼

	QString m_themeName;			//��������		
	QString m_themeRoot;			//����ĸ�Ŀ¼

	QString m_dataBasePath;			//���ݿ�·��
	QString m_cityConfigPath;		//��������·��
};