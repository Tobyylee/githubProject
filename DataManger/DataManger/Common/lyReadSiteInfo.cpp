#pragma once

#include "lyReadSiteInfo.h"
#include <QTextStream>
#include <QTextCodec>
#include <qDebug>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>

lyReadSiteInfo* lyReadSiteInfo::m_sReadSiteInfo = nullptr;

lyReadSiteInfo::lyReadSiteInfo()
{

}

lyReadSiteInfo::~lyReadSiteInfo()
{

}

lyReadSiteInfo* lyReadSiteInfo::getInstance()
{
	if (m_sReadSiteInfo == nullptr)
	{
		m_sReadSiteInfo = new lyReadSiteInfo();
	}
	return m_sReadSiteInfo;
}

void lyReadSiteInfo::readData(const QString& fileName)
{
	QFile file(fileName);

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return;
	}

	QTextStream in(&file);
	in.setCodec("GBK");
	while (!in.atEnd())
	{
		QString line = in.readLine();
		line = line + "\n";
		m_data = m_data + line;
	}
	file.close();
	analysesJson();
}

void lyReadSiteInfo::deleteReadSiteInfo()
{
	if (m_sReadSiteInfo)
	{
		delete m_sReadSiteInfo;
		m_sReadSiteInfo = nullptr;
	}
}

void lyReadSiteInfo::analysesJson()
{
	QTextCodec* pCodec = QTextCodec::codecForName("gb2312");
	QJsonParseError jsonError;
	QJsonDocument doucment = QJsonDocument::fromJson(m_data.toUtf8(), &jsonError);  // 转化为 JSON 文档
	if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError))
	{  // 解析未发生错误
		if (doucment.isObject()) { // JSON 文档为对象
			QJsonObject object = doucment.object();  // 转化为对象
			if (object.contains("provinces"))
			{
				QJsonValue val = object.value("provinces");
				if (val.isArray())
				{
					QJsonArray arr = val.toArray();
					for (int i = 0; i < arr.size(); i++)
					{
						QJsonValue value = arr.at(i);
						//	qDebug() << arr.size();
						if (value.isObject())
						{
							//获取一级城市
							QJsonValue val = value.toObject().value("provinceName");
							QString l_provinceName = val.toString();
					//		qDebug() << "province:" << val.toString();
							//m_datas.insert(l_provinceName);

							//获取二级城市
							QJsonValue cityNamesValues = value.toObject().value("citys");
							if (cityNamesValues.isArray())
							{
								QJsonArray cityNamesArray = cityNamesValues.toArray();
								QVector<QString> l_citys;
								for (int j = 0; j < cityNamesArray.size(); j++)
								{
									QJsonValue cityNameValues = cityNamesArray.at(j);
									//qDebug() << arr2.size();
									if (cityNameValues.isObject())
									{
										QJsonValue cityNameValue = cityNameValues.toObject().value("citysName");
										QString l_cityName = cityNameValue.toString();
										l_citys.append(l_cityName);
								//		qDebug() << cityNameValue.toString();
									}
								}
								m_datas[l_provinceName] = l_citys;
								//m_datas.insert(l_provinceName, l_citys);
							}
						}
					}
				}
			}
		}
	}
}
