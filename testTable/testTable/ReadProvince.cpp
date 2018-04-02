#include "ReadProvince.h"
#include <QTextStream>
#include <QTextCodec>
#include <qDebug>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>

#define FILENAME "province.txt"


readProvince::readProvince()
{
}

readProvince::~readProvince()
{

}

void readProvince::readData()
{
	QFile file(FILENAME);

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return;
	}
	//while (!file.atEnd()) {
	//	QByteArray line = file.readLine();
	//	line = line + "\n";
	//	m_byteArray = m_byteArray + line;
	//}
	
	QTextStream in(&file);
	in.setCodec("GBK");
	while (!in.atEnd())
	{
		QString line = in.readLine();
		line = line + "\n";
		m_data = m_data + line;
	//	qDebug() << m_data;
	}
	file.close();
}

void readProvince::analysesJson()
{
	QTextCodec* pCodec = QTextCodec::codecForName("gb2312");
	QJsonParseError jsonError;
	QJsonDocument doucment = QJsonDocument::fromJson(m_data.toUtf8(), &jsonError);  // ת��Ϊ JSON �ĵ�
	if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError))
	{  // ����δ��������
		if (doucment.isObject()) { // JSON �ĵ�Ϊ����
			QJsonObject object = doucment.object();  // ת��Ϊ����
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
							//��ȡһ������
							QJsonValue val = value.toObject().value("provinceName");
							QString l_provinceName = val.toString();
							qDebug() << "province:" << val.toString();
							//m_datas.insert(l_provinceName);

							//��ȡ��������
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
										qDebug() << cityNameValue.toString();
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
