#include "lyConfig.h"
#include <QtCore/QDir>
#include <QTextCodec>

lyConfig::lyConfig(const QString& path, QSettings::Format format /*= QSettings::IniFormat*/, QObject* parent /*= NULL*/)
{
	m_pSettings = new QSettings(path, format, parent);
	m_pSettings->setIniCodec(QTextCodec::codecForName("GB2312"));
	m_path = path;
}

lyConfig::~lyConfig(void)
{
	if (m_pSettings)
	{
		delete m_pSettings;
		m_pSettings = NULL;
	}
}

void lyConfig::CreateConfigFile()
{
	QDir l_dir;
	QFile l_file(m_path);
	if (!l_file.exists())
	{
		l_file.open(QIODevice::ReadWrite);
		l_file.close();
		m_pSettings->setPath(m_pSettings->format(), m_pSettings->scope(), m_path);
	}
}

bool lyConfig::GetValue(const QString& type, QString& value)
{
	if (!type.isEmpty())
	{
		value = m_pSettings->value(type).toString();
		return true;
	}
	return false;
}

bool lyConfig::GetValue(const QString& type, double& value)
{
	if (!type.isEmpty())
	{
		value = m_pSettings->value(type).toString().toDouble();
		return true;
	}
	return false;
}

bool lyConfig::GetValue(const QString& type, int& value)
{
	if (!type.isEmpty())
	{
		value = m_pSettings->value(type).toString().toInt();
		return true;
	}
	return false;
}

bool lyConfig::GetValue(const QString& type, float& value)
{
	if (!type.isEmpty())
	{
		value = m_pSettings->value(type).toString().toFloat();
		return true;
	}
	return false;
}

bool lyConfig::SetValue(const QString& type, const QVariant &value)
{
	if (!type.isEmpty())
	{
		m_pSettings->setValue(type, value);
		return true;
	}
	return false;
}

