#include "lyExcelDataManager.h"
#include <QDebug>

QMap<QString, QVector<DateTableMes>>* lyExcelDataManager::m_ExcelData = nullptr;
QString lyExcelDataManager::m_SelectedTitle = "default";
const int g_newPageCount = 10;

lyExcelDataManager::lyExcelDataManager()
{
	

}

lyExcelDataManager::~lyExcelDataManager()
{

}

void lyExcelDataManager::initData()
{
	if (!m_ExcelData)
	{
		m_ExcelData = new QMap<QString, QVector<DateTableMes>>;
	}
}

void lyExcelDataManager::appendData(const DateTableMes& data)
{
	(*m_ExcelData)[m_SelectedTitle].append(data);
}

void lyExcelDataManager::deleteData(const DateTableMes& data)
{
	for (int i = 0; i < (*m_ExcelData)[m_SelectedTitle].size(); i++)
	{
		if ((*m_ExcelData)[m_SelectedTitle].at(i).m_writeTime == data.m_writeTime)
		{
			(*m_ExcelData)[m_SelectedTitle].remove(i);
			return;
		}
	}
}

void lyExcelDataManager::updateData(const DateTableMes& data)
{
	for (int i = 0; i < (*m_ExcelData)[m_SelectedTitle].size(); i++)
	{
		if ((*m_ExcelData)[m_SelectedTitle].at(i).m_writeTime == data.m_writeTime)
		{
			(*m_ExcelData)[m_SelectedTitle].replace(i, data);
			return;
		}
	}
}

void lyExcelDataManager::insertData(int index, const DateTableMes& data)
{
	if(index<(*m_ExcelData)[m_SelectedTitle].size())
	{ 
		(*m_ExcelData)[m_SelectedTitle].insert(index, data);
	}
}

const QStringList lyExcelDataManager::getAllExcelTitle()
{
	QMap<QString, QVector<DateTableMes>>::iterator it = m_ExcelData->begin();
	QStringList l_list;
	while (it != m_ExcelData->end())
	{
		l_list.append(it.key());
		it++;
	}
	return l_list;
}

void lyExcelDataManager::deleteTitle(const QString& title)
{
	QMap<QString, QVector<DateTableMes>>::iterator it = m_ExcelData->find(title);
	if (it != m_ExcelData->end())
	{	
		if (m_SelectedTitle == it.key())
		{
			auto itNext = m_ExcelData->erase(it);
			if(itNext != m_ExcelData->end())
			{ 
				m_SelectedTitle = itNext.key();
			}
			else
			{
				m_SelectedTitle = "default";
			}
		}
	}
}

void lyExcelDataManager::judgeDateConflict()
{
	QMap<QString, QVector<DateTableMes>>::iterator it = m_ExcelData->begin();
	while (it != m_ExcelData->end())
	{
//		QString l_name = it.key();
		QVector<DateTableMes>& l_data = (*m_ExcelData)[it.key()];
		for (int i = 0; i < l_data.size(); i++)
		{
			for (int j = i+1; j < l_data.size(); j++)
			{
				if (l_data.at(i).m_beginTime.isValid()&&l_data.at(i).m_endTime.isValid()
					&& l_data.at(j).m_beginTime.isValid() && l_data.at(j).m_endTime.isValid())
				{
					if (!(l_data.at(i).m_endTime <= l_data.at(j).m_beginTime ||
						l_data.at(i).m_beginTime >= l_data.at(j).m_endTime))
					{
						DateTableMes l_dateTableMes1 = l_data.at(i);
						l_dateTableMes1.m_bConflict = true;
						DateTableMes l_dateTableMes2 = l_data.at(j);
						l_dateTableMes2.m_bConflict = true;
						l_data.replace(i, l_dateTableMes1);
						l_data.replace(j, l_dateTableMes2);
					//	qDebug() << "i" << i << "j" << j;
					}
				}
				else
				{
				//	qDebug() << "noValid" << l_data.at(i).m_beginTime << l_data.at(i).m_endTime;
				}
			
			}
		}
		it++;
	}
}

QString lyExcelDataManager::getTitleName(const QString& name)
{
	QMap<QString, QVector<DateTableMes>>::iterator it = m_ExcelData->find(name);
	if (it != m_ExcelData->end())
	{
		for (int i = 0; i < (*m_ExcelData).size(); i++)
		{
			QString l_name = name + QString("(%1)").arg(QString::number(i));
			QMap<QString, QVector<DateTableMes>>::iterator itFind = m_ExcelData->find(name);
			if (itFind != m_ExcelData->end())
			{
				return l_name;
			}
		}
	}
	else
	{
		return name;
	}
	return name;
}

void lyExcelDataManager::creatNewPage(const QString& pageName)
{
	m_SelectedTitle = pageName;
	QVector<DateTableMes> l_datas;
	for (int i = 0; i < g_newPageCount; i++)
	{
		DateTableMes l_dateTableMes;
		l_datas.append(l_dateTableMes);
	}
	(*m_ExcelData)[pageName] = l_datas;
}

void lyExcelDataManager::checkDataUrgency()
{
	QMap<QString, QVector<DateTableMes>>::iterator it = m_ExcelData->begin();
	while (it != m_ExcelData->end())
	{
		QVector<DateTableMes>& l_data = (*m_ExcelData)[it.key()];
		for (int i = 0; i < l_data.size(); i++)
		{
			DateTableMes l_dateTabeMes = l_data.at(i);
			if (l_dateTabeMes.m_beginTime.isValid())
			{
				if (l_dateTabeMes.m_beginTime <= QDateTime::currentDateTime().addDays(ly_RedLight))
				{
					l_dateTabeMes.m_datePrioritization = ly_RedLight;
				}
				else if (l_dateTabeMes.m_beginTime > QDateTime::currentDateTime().addDays(ly_RedLight)
					&& l_dateTabeMes.m_beginTime <= QDateTime::currentDateTime().addDays(ly_YellowLight))
				{
					l_dateTabeMes.m_datePrioritization = ly_YellowLight;
				}
				else
				{
					l_dateTabeMes.m_datePrioritization = ly_GreenLight;
				}
				l_data.replace(i, l_dateTabeMes);
			}

		}
		it++;
	}
}

void lyExcelDataManager::isSelectDataPlan()
{
	QMap<QString, QVector<DateTableMes>>::iterator it = m_ExcelData->begin();
	while (it != m_ExcelData->end())
	{
		QVector<DateTableMes>& l_data = (*m_ExcelData)[it.key()];
		for (int i = 0; i < l_data.size(); i++)
		{
			DateTableMes l_dateTabeMes = l_data.at(i);
		}
		it++;
	}
}

void lyExcelDataManager::renameTable(const QString& oldName, const QString& newName)
{
	QMap<QString, QVector<DateTableMes>>::iterator it = m_ExcelData->find(oldName);
	if (it != m_ExcelData->end())
	{
		QVector<DateTableMes> l_data = it.value();
		(*m_ExcelData)[newName] = l_data;
		m_ExcelData->remove(oldName);
	}
}

bool lyExcelDataManager::writeSortDe(const DateTableMes& p1, const DateTableMes& p2)
{
	return p1.m_writeTime > p2.m_writeTime;
}

bool lyExcelDataManager::writeSortAs(const DateTableMes& p1, const DateTableMes& p2)
{
	return p1.m_writeTime < p2.m_writeTime;
}

bool lyExcelDataManager::beginTimeSortDe(const DateTableMes& p1, const DateTableMes& p2)
{
	return p1.m_writeTime > p2.m_writeTime;
}

bool lyExcelDataManager::beginTimeSortAs(const DateTableMes& p1, const DateTableMes& p2)
{
	return p1.m_beginTime < p2.m_beginTime;
}

bool lyExcelDataManager::endTimeSortDe(const DateTableMes& p1, const DateTableMes& p2)
{
	return p1.m_endTime > p2.m_endTime;
}

bool lyExcelDataManager::endTimeSortAs(const DateTableMes& p1, const DateTableMes& p2)
{
	return p1.m_beginTime < p2.m_beginTime;
}

bool lyExcelDataManager::PrioritizationSortDe(const DateTableMes& p1, const DateTableMes& p2)
{
	return p1.m_datePrioritization < p2.m_datePrioritization;
}

bool lyExcelDataManager::PrioritizationSortAs(const DateTableMes& p1, const DateTableMes& p2)
{
	return p1.m_datePrioritization > p2.m_datePrioritization;
}

void lyExcelDataManager::clearData()
{
	m_ExcelData->clear();
}
