#pragma once

#include "lyConfig.h"

class lyParConfig : public lyConfig
{
public:
	lyParConfig(const QString& path, QSettings::Format format = QSettings::IniFormat, QObject* parent = NULL);
	virtual ~lyParConfig(void);

	void ReadConfig();
	void WriteConfig();

public:
//	int m_MesType;
	QStringList m_MesTypes_Assign;
	QStringList m_MesTypes_Meet;
};