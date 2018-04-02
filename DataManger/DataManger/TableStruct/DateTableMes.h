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

	QDateTime m_writeTime;												//�ճ���Ϣ¼��ʱ��
	QString m_mesSection;													//�ճ���Ϣ��������
	QString m_mesType;														//�ճ���Ϣ����
	QString m_mesContent;												//�ճ���Ϣ����
	QString m_dateSite;														//�ճ���Ϣ�ص�
	QDateTime m_beginTime;												//�ճ̿�ʼʱ��
	QDateTime m_endTime;												//�ճ̽���ʱ��
	int m_datePrioritization;												//�ճ̻����̶�
	QString m_datePlan;														//�ճ̽���
	QString m_remark;															//��ע
	bool m_bConflict;															//�ճ��Ƿ��г�ͻ
};
