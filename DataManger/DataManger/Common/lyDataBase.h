#pragma once

#include <QSqlDatabase>
#include "DateTableMes.h"

class lyDataBase
{
public:
	~lyDataBase();

	static lyDataBase* getInstance();

	bool initDataBase(const QString& dataPath);
	void deleteDataBase();

	bool insertExcelData(const DateTableMes& datas);
	bool getExcelData(const QDateTime& beginTime, const QDateTime& endTime, QVector<DateTableMes>& datas, int index);
	bool deleteExcelData(const DateTableMes& data);

	bool getExcelData(const QString& dateSite, QVector<DateTableMes>& datas, int index);


private:
	lyDataBase();

	static lyDataBase* m_dataBase;
	QSqlDatabase m_db;
};

