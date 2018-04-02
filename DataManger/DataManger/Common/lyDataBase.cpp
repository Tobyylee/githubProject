#include "lyDataBase.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

lyDataBase* lyDataBase::m_dataBase = nullptr;

lyDataBase::lyDataBase()
{
}


lyDataBase::~lyDataBase()
{
}

lyDataBase* lyDataBase::getInstance()
{
	if (m_dataBase == nullptr)
	{
		m_dataBase = new lyDataBase();
	}
	return m_dataBase;
}

bool lyDataBase::initDataBase(const QString& dataPath)
{
	m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName(dataPath);

	if (!m_db.open())
	{
		qDebug() << "Database open fail";
		return false;
	}
	qDebug() << "Database open suc";
	return true;
}

void lyDataBase::deleteDataBase()
{
	if (m_dataBase)
	{
		m_db.close();
		delete m_dataBase;
		m_dataBase = nullptr;
	}
}

bool lyDataBase::insertExcelData(const DateTableMes& data)
{
	QSqlQuery query(m_db);
	query.prepare("INSERT OR REPLACE INTO DateMgr(writeTime, mesSection, mesType, mesContent, dateSite, beginTime, endTime, datePrioritization, datePlan, remark, bConflict) "
		"VALUES (:writeTime, :mesSection, :mesType, :mesContent, :dateSite, :beginTime, :endTime, :datePrioritization, :datePlan, :remark, :bConflict)");
	query.bindValue(":writeTime", data.m_writeTime.toString("yyyy/MM/dd hh:mm:ss"));
	query.bindValue(":mesSection", data.m_mesSection);
	query.bindValue(":mesType", data.m_mesType);
	query.bindValue(":mesContent", data.m_mesContent);
	query.bindValue(":dateSite", data.m_dateSite);
	query.bindValue(":beginTime", data.m_beginTime.toString("yyyy/MM/dd hh:mm:ss"));
	query.bindValue(":endTime", data.m_endTime.toString("yyyy/MM/dd hh:mm:ss"));
	query.bindValue(":datePrioritization", data.m_datePrioritization);
	query.bindValue(":datePlan", data.m_datePlan);
	query.bindValue(":remark", data.m_remark);
	query.bindValue(":bConflict", data.m_bConflict);
	
	bool  b = query.exec();
	if (!b)
	{
		qDebug() << query.lastError() << endl;
		return b;
	}
	return true;
}

bool lyDataBase::getExcelData(const QDateTime& beginTime, const QDateTime& endTime, QVector<DateTableMes>& datas, int index)
{
	QSqlQuery query(m_db);
	QString l_sColumn = "";
	if (index == ly_WriteTime)
	{
		l_sColumn = "writeTime";
	}
	else if(index == ly_BeginTime)
	{
		l_sColumn = "beginTime";
	}
	else if (index == ly_EndTime)
	{
		l_sColumn = "endTime";
	}
	QString sql = QString("SELECT *  FROM DateMgr where %1 Between '%2' And '%3';").
		arg(l_sColumn).arg(beginTime.toString("yyyy/MM/dd hh:mm:ss")).arg(endTime.toString("yyyy/MM/dd hh:mm:ss"));
	if (!query.exec(sql))
	{
		qDebug() << query.lastError();
		return false;
	}

	while (query.next())
	{
		bool l_bConflict = false;
		DateTableMes l_data;
		l_data.m_writeTime = query.value(ly_WriteTime).toDateTime();
		for (int i = 0; i < datas.size(); i++)
		{
			if (datas.at(i).m_writeTime == l_data.m_writeTime)
			{
				l_bConflict = true;
				break;
			}
		}
		if (!l_bConflict)
		{
			l_data.m_mesSection = query.value(ly_MesSection).toString();
			l_data.m_mesType = query.value(ly_MesType).toString();
			l_data.m_mesContent = query.value(ly_MesContent).toString();
			l_data.m_dateSite = query.value(ly_DateSite).toString();
			l_data.m_beginTime = query.value(ly_BeginTime).toDateTime();
			l_data.m_endTime = query.value(ly_EndTime).toDateTime();
			l_data.m_datePrioritization = query.value(ly_DatePrioritization).toInt();
			l_data.m_datePlan = query.value(ly_DatePlan).toString();
			l_data.m_remark = query.value(ly_Remark).toString();
			l_data.m_bConflict = query.value(ly_Conflict).toBool();
			datas.append(l_data);
		}
	}
	return true;
}

bool lyDataBase::getExcelData(const QString& dateSite, QVector<DateTableMes>& datas, int index)
{
	QSqlQuery query(m_db);
	QString l_dateSite;
	if (index == ly_MesType)
	{
		l_dateSite = "mesType";
		
	}
	else if (index == ly_DateSite)
	{
		l_dateSite = "dateSite";
	}
	QString sql = QString("SELECT *  FROM DateMgr where %1 LIKE '%%2%'").arg(l_dateSite).arg(dateSite);
		
	if (!query.exec(sql))
	{
		qDebug() << query.lastError();
		return false;
	}

	while (query.next())
	{
		bool l_bConflict = false;															//日程是否有冲突
		DateTableMes l_data;
		l_data.m_writeTime = query.value(ly_WriteTime).toDateTime();
		for (int i = 0; i < datas.size(); i++)
		{
			if (datas.at(i).m_writeTime == l_data.m_writeTime)
			{
				l_bConflict = true;
				break;
			}
		}
		if (!l_bConflict)
		{
			l_data.m_mesSection = query.value(ly_MesSection).toString();
			l_data.m_mesType = query.value(ly_MesType).toString();
			l_data.m_mesContent = query.value(ly_MesContent).toString();
			l_data.m_dateSite = query.value(ly_DateSite).toString();
			l_data.m_beginTime = query.value(ly_BeginTime).toDateTime();
			l_data.m_endTime = query.value(ly_EndTime).toDateTime();
			l_data.m_datePrioritization = query.value(ly_DatePrioritization).toInt();
			l_data.m_datePlan = query.value(ly_DatePlan).toString();
			l_data.m_remark = query.value(ly_Remark).toString();
			l_data.m_bConflict = query.value(ly_Conflict).toBool();
			datas.append(l_data);
		}
	}

	return true;
}

bool lyDataBase::deleteExcelData(const DateTableMes& data)
{
	return true;
}
