#ifndef READPROVINCE_H_
#define READPROVINCE_H_

#include <QFile>
#include <QMap>

class readProvince
{
public:
	readProvince();
	virtual ~readProvince();

	void readData();
	void analysesJson();

	QMap<QString, QVector<QString>> m_datas;
protected:
	QString m_data;
	QByteArray m_byteArray;
	
};
#endif