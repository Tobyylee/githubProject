#include "DateTableMes.h"

DateTableMes::DateTableMes(const QDateTime& dateTime, const QString& mesSection,
	const QString& mesClassigy, const QString& mesContent, const QString& dateSite , 
	const QDateTime& beginTime, const QDateTime& endTime, int datePrioritization,
	const QString& datePlan,  const QString& remark, bool bConflict) : m_writeTime(dateTime), 
	m_mesSection(mesSection), m_mesType(mesClassigy), m_mesContent(mesContent), m_dateSite(dateSite),
	m_beginTime(beginTime), m_endTime(endTime), m_datePrioritization(datePrioritization),
	m_datePlan(datePlan), m_remark(remark), m_bConflict(bConflict)
{
}

DateTableMes::~DateTableMes()
{
}
