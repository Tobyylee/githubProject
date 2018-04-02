#pragma once

#include <QObject>
#include <QDateTime>

enum TableHeader
{
	ly_WriteTime = 0,
	ly_MesSection,
	ly_MesType,
	ly_MesContent,
	ly_DateSite,
	ly_BeginTime,
	ly_EndTime,
	ly_DatePrioritization,
	ly_DatePlan,
	ly_Remark,
	ly_Conflict,
	ly_Head_Count,
};

const QString g_dateFormat = "yyyy-MM-dd hh:mm:ss";

enum MesType
{
	ly_Conference = 0,
	ly_Assignment,
	ly_Incident,
	ly_Train,
	ly_MesTpye_Count
};


enum DatePrioritization
{
	ly_RedLight = 2,
	ly_YellowLight = 5,
	ly_GreenLight,
	ly_DatePrioritization_Count,
};

enum DatePlan
{
	ly_NoSelect = 0,
	ly_NoHappen,
	ly_Going,
	ly_Finished,
	ly_DatePlan_Count,
};


class DateTableMes
{
public:
	DateTableMes(const QDateTime& dateTime = QDateTime(), const QString& mesSection = "",
		const QString& mesClassigy = "", const QString& mesContent = "", 
		const QString& dateSite = "", const QDateTime& beginTime = QDateTime(),
		const QDateTime& endTime = QDateTime(),  int datePrioritization = 0, 
		const QString& datePlan = "", const QString& remark = "", bool bConflict = false);
	~DateTableMes();

	QDateTime m_writeTime;												//日程信息录入时间
	QString m_mesSection;													//日程信息归属部门
	QString m_mesType;														//日程信息分类
	QString m_mesContent;												//日程信息内容
	QString m_dateSite;														//日程信息地点
	QDateTime m_beginTime;												//日程开始时间
	QDateTime m_endTime;												//日程结束时间
	int m_datePrioritization;												//日程缓急程度
	QString m_datePlan;														//日程进度
	QString m_remark;															//备注
	bool m_bConflict;															//日程是否有冲突
};
