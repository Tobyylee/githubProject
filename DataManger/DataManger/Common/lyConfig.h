#pragma once

#include <QtCore/QSettings>

class lyConfig
{
public:
	lyConfig(const QString& path, QSettings::Format format = QSettings::IniFormat, QObject* parent = NULL);
	virtual ~lyConfig(void);
	void CreateConfigFile();
	QString GetPath() const { return m_pSettings->fileName(); }

	bool GetValue(const QString& type, QString& value);
	bool GetValue(const QString& type, double& value);
	bool GetValue(const QString& type, int& value);
	bool GetValue(const QString& type, float& value);

	bool SetValue(const QString& type, const QVariant &value);

protected:


private:
	QSettings* m_pSettings;
	QString m_path;
};
