#pragma once

#include <QFile>
#include <QMap>

class lyReadSiteInfo
{
public:
	~lyReadSiteInfo();
	static lyReadSiteInfo* getInstance();

	void readData(const QString& fileName);
	QMap<QString, QVector<QString>> m_datas;
	void deleteReadSiteInfo();

protected:
	lyReadSiteInfo();
	void analysesJson();
	QString m_data;
	QByteArray m_byteArray;
	static lyReadSiteInfo* m_sReadSiteInfo;
};