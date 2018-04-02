#include "lyExcelTableModel.h"

#include <QColor>
#include <QDebug>
#include "lyExcelDataManager.h"
#include "lyOperatorExcelFile.h"
#include "lyWidgetManager.h"
#include "lyCommon.h"

const char* g_ExcelTableModelName[] =
{
	QT_TRANSLATE_NOOP("lyExcelTableModel", "WriteTime"),
	QT_TRANSLATE_NOOP("lyExcelTableModel", "MesSection"),
	QT_TRANSLATE_NOOP("lyExcelTableModel", "MesType"),
	QT_TRANSLATE_NOOP("lyExcelTableModel", "MesContent"),
	QT_TRANSLATE_NOOP("lyExcelTableModel", "DateSite"),
	QT_TRANSLATE_NOOP("lyExcelTableModel", "BeginTime"),
	QT_TRANSLATE_NOOP("lyExcelTableModel", "EndTime"),
	QT_TRANSLATE_NOOP("lyExcelTableModel", "DatePrioritization"),
	QT_TRANSLATE_NOOP("lyExcelTableModel", "DatePlan"),
	QT_TRANSLATE_NOOP("lyExcelTableModel", "Remark"),
	QT_TRANSLATE_NOOP("lyExcelTableModel", "Conflict"),
};


lyExcelTableModel::lyExcelTableModel(QObject *parent)
	: QAbstractTableModel(parent)
{
	for (int i = 0; i < ly_Head_Count; i++)
	{
		m_columnList << tr(g_ExcelTableModelName[i]);
	}
	QPixmap l_pixMap("");
}

lyExcelTableModel::~lyExcelTableModel()
{
}

Qt::ItemFlags lyExcelTableModel::flags(const QModelIndex &index) const
{
	Qt::ItemFlags theFlags = QAbstractTableModel::flags(index);
	if (index.isValid())
		theFlags |= Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
	return theFlags;
}

int lyExcelTableModel::rowCount(const QModelIndex &parent) const
{
	return parent.isValid() ? 0 : (*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle].count();
}

int lyExcelTableModel::columnCount(const QModelIndex &parent) const
{
	return parent.isValid() ? 0 : m_columnList.count();
}

QVariant lyExcelTableModel::data(const QModelIndex &index, int role /*= Qt::DisplayRole*/) const
{
	QVector<DateTableMes>* l_data = &(*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle];


	if (!index.isValid() || index.row() < 0 || index.row() >= l_data->count() ||
		index.column() < 0 || index.column() >= m_columnList.size())
		return QVariant();

	int curRow = index.row();
//	qDebug() <<"row:"<< curRow;
	QVariant  theResult;
	QString l_onlineStatus;
	const DateTableMes &dataItem = l_data->at(index.row());
	if (role == Qt::DisplayRole)
	{
		switch (index.column())
		{
		case ly_WriteTime:
		{
			theResult = dataItem.m_writeTime.toString(g_dateFormat);
			break;
		}
		case ly_MesSection:
		{
			theResult = dataItem.m_mesSection;
			break;
		}
		case ly_MesType:
		{
			theResult = dataItem.m_mesType;
			break;
		}
		case ly_MesContent:
		{
			theResult = dataItem.m_mesContent;
			break;
		}
		case ly_DateSite:
		{
			theResult = dataItem.m_dateSite;
			break;
		}
		case ly_BeginTime:
		{
			theResult = dataItem.m_beginTime;
			break;
		case ly_EndTime:
		{
			theResult = dataItem.m_endTime;
			break;
		}
		case ly_DatePrioritization:
		{
			//theResult = dataItem.m_datePrioritization;
			break;
		}
		case ly_DatePlan:
		{
			theResult = dataItem.m_datePlan;
			break;
		}
		case ly_Remark:
		{
			theResult = dataItem.m_remark;
			break;
		}
		case ly_Conflict:
		{
			theResult = dataItem.m_bConflict;
			break;
		}
		}
		default:
			break;
		}
	}
	else if (role == Qt::TextAlignmentRole)
	{
		theResult = (Qt::AlignCenter);
		//return value;
	}
	else if (role == Qt::BackgroundColorRole)
	{
		if (dataItem.m_bConflict)
		{
			return QColor(Qt::red);
		}
		else
		{
			if(index.column() == ly_DatePrioritization)
			{ 
				if (dataItem.m_datePrioritization == ly_RedLight)
				{
					return QColor(Qt::red);
				}
				else if (dataItem.m_datePrioritization == ly_YellowLight)
				{
					return QColor(Qt::yellow);
				}
				else if (dataItem.m_datePrioritization == ly_GreenLight)
				{
					return QColor(Qt::green);
				}
			}
			else if (index.column() == ly_DatePlan)
			{
				if (dataItem.m_writeTime.isValid()&&(dataItem.m_datePlan == QStringLiteral("未选择")||dataItem.m_datePlan.isEmpty()))
				{
					return QColor(Qt::red);
				}
			}
			return QVariant();
		}
	}
	else if (role == Qt::DecorationRole)
	{
		/*QImage l_image("drag.png");
		switch (index.column())
		{
		case P_NAME:
		{
			theResult = QVariant(l_image);
			break;
		}
		}*/
	}
	else
	{
		return QVariant();
	}

	return theResult;
}

QVariant lyExcelTableModel::headerData(int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole*/) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			if (section < 0 || section >= m_columnList.size())
				return QVariant();
			else
				return m_columnList[section];
		}
		else if(orientation ==  Qt::Vertical)
		{
			return QVariant(section + 1);
		}
	}

	return QAbstractTableModel::headerData(section, orientation, role);
}

bool lyExcelTableModel::setData(const QModelIndex &index, const QVariant &value, int role /*= Qt::EditRole*/)
{
	QVector<DateTableMes>* l_data = &(*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle];
	if (index.row() > l_data->size()) return true;
	int l_row = index.row();
	int l_column = index.column();

	QModelIndex l_modelIndex = this->index(l_row, ly_WriteTime);
	QString l_dateTime = l_modelIndex.data().toString();

	DateTableMes l_value = l_data->at(l_row);
	if (!l_value.m_writeTime.isValid())
	{
		l_value.m_writeTime = QDateTime::currentDateTime();
	}
	/*bool l_flag = false;
	for (int i = 0; i < l_data->size(); i++)
	{
		if (l_data->at(i).m_writeTime.toString(g_dateFormat) == l_dateTime && !l_dateTime.isEmpty())
		{
			l_value = l_data->at(i);
			l_flag = true;
			break;
		}
	}
	if (!l_flag)
	{
		l_value.m_writeTime = QDateTime::currentDateTime();
	}*/
	switch (l_column)
	{
	case ly_WriteTime:
	{
		l_value.m_writeTime = value.toDateTime();
		break;
	}
	case ly_MesSection:
	{
		l_value.m_mesSection = value.toString();
		break;
	}
	case ly_MesContent:
	{
		l_value.m_mesContent = value.toString();
		break;
	}
	case	ly_Remark:
	{
		l_value.m_remark = value.toString();
		break;
	}
	case ly_MesType:
	{
		l_value.m_mesType = value.toString();
		break;
	}
	case ly_DatePrioritization:
	{
		//DateTableMes l_value = l_data->at(l_row);
		/*l_value.m_datePrioritization = value.toString();
		l_data->replace(l_row, l_value);*/
		break;
	}
	case ly_DatePlan:
	{
		l_value.m_datePlan = value.toString();
		break;
	}
	case ly_DateSite:
	{
		l_value.m_dateSite = value.toString();
		break;
	}
	case ly_BeginTime:
	{
		l_value.m_beginTime = value.toDateTime();
		break;
	}
	case ly_EndTime:
	{
		l_value.m_endTime = value.toDateTime();
		break;
	}
	case ly_Conflict:
	{
		break;
	}
	default:
		break;
	}
	l_data->replace(l_row, l_value);
	if (index.isValid() && role == Qt::EditRole) {
		emit dataChanged(index, index);
		return true;
	}
	if (!index.isValid() || role != Qt::DisplayRole || index.row() < 0 ||
		index.row() >= l_data->count() || index.column() < 0)
		return false;
	emit dataChanged(index, index);
	return true;
}

QStringList lyExcelTableModel::getColumnList()
{
	return m_columnList;
}

void lyExcelTableModel::updateStatus()
{

}

bool lyExcelTableModel::editRows(int position, int rows, const QModelIndex &index, DateTableMes dateMes)
{
	QVector<DateTableMes>* l_data = &(*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle];
	layoutAboutToBeChanged();
	if (position < 0)
	{
		position = 0;
	}
	l_data->replace(index.row(), dateMes);
	layoutChanged();
	return true;
}

bool lyExcelTableModel::insertRows(int position, int rows, const QModelIndex &index, DateTableMes dateMes)
{
	QVector<DateTableMes>* l_data = &(*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle];	
	if (position < 0)
	{
		position = 0;
	}
	beginInsertRows(QModelIndex(), position, position);
	if (l_data->size() > index.row() && index.row()>0)
	{
		l_data->insert(index.row(), dateMes);
	}
	else
	{
		l_data->append(dateMes);
	}

	endInsertRows();
	return true;
}

bool lyExcelTableModel::removeRows(int position, int rows, const QModelIndex &index)
{
	QVector<DateTableMes>* l_data = &(*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle];
	QModelIndex l_modelIndex = this->index(position, ly_WriteTime);
	QString l_dateTime = l_modelIndex.data().toString();
	if (position < 0)
	{
		return true;
	}
	DateTableMes l_value;
	bool l_flag = false;
	int l_index = -1;
	for (int i = 0; i < l_data->size(); i++)
	{
		if (l_data->at(i).m_writeTime.toString(g_dateFormat) == l_dateTime && !l_dateTime.isEmpty())
		{
			l_value = l_data->at(i);
			l_flag = true;
			break;
		}
	}
	if (l_index < 0)
	{
		l_index = position;
	}
	beginRemoveRows(QModelIndex(), position, position);
	l_data->remove(l_index);
	endRemoveRows();
	return true;
}

void lyExcelTableModel::setExcelTableData(const QString&fileName)
{
	qDebug() << QStringLiteral("读取Excel文件之前");
	lyOperatorExcelFile l_lyOperatorExcelFile;
	l_lyOperatorExcelFile.readExcelFile(fileName);
	QMap<QString, QMap<int, QVector<QVariant>>>& datas= l_lyOperatorExcelFile.getReadExcelFileData();
	qDebug() << QStringLiteral("读取Excel文件完成");

//	emit layoutAboutToBeChanged();
	lyExcelDataManager::judgeDateConflict();																				//判断是否冲突
	QMap<QString, QMap<int, QVector<QVariant>>>::iterator it = datas.begin();				//行
	QStringList l_list;
	while (it != datas.end())
	{
		QString l_sheetTitle = it.key();
		QMap<int, QVector<QVariant>> l_secondData = datas[it.key()];
		QVector<QVariant>& l_title = l_secondData[0];
		QMap<int, int> l_titleMap;
		//excel文件title和表格title映射
		for (int i = 0; i < l_title.size(); i++)
		{
			for (int j = 0; j < ly_Head_Count; j++)
			{
				if (l_title.at(i).toString() == tr(g_ExcelTableModelName[j]))
				{
					l_titleMap[i] = j;
					break;
				}
			}
		}
		lyExcelDataManager::m_SelectedTitle = l_sheetTitle;
		QMap<int, QVector<QVariant>>::iterator l_itSecond = l_secondData.begin();
		while (l_itSecond != l_secondData.end())
		{
			if (l_itSecond.key() != 0)
			{
				QVector<QVariant>& l_date = l_secondData[l_itSecond.key()];
				DateTableMes l_value;
				for (int i = 0; i < l_date.size(); i++)
				{
					int l_index = l_titleMap[i];
					switch (l_index)
					{
						/*case ly_WriteTime:
						{
						l_value = dataItem.m_dateTime.toString(g_dateFormat);
						break;
						}*/
					case ly_MesSection:
					{
						l_value.m_mesSection = l_date.at(i).toString();
						break;
					}
					case ly_MesType:
					{
						l_value.m_mesType = l_date.at(i).toString();
						break;
					}
					case ly_MesContent:
					{
						l_value.m_mesContent = l_date.at(i).toString();
						break;
					}
					case ly_DateSite:
					{
						l_value.m_dateSite = l_date.at(i).toString();
						break;
					}
					case ly_BeginTime:
					{
						l_value.m_beginTime = QDateTime::fromString(l_date.at(i).toString(), g_dateFormat);
						break;
					case ly_EndTime:
					{
						l_value.m_endTime = QDateTime::fromString(l_date.at(i).toString(), g_dateFormat);
						break;
					}
					case ly_DatePrioritization:
					{
						l_value.m_datePrioritization = 0;
						break;
					}
					case ly_DatePlan:
					{
						l_value.m_datePlan = l_date.at(i).toString();
						break;
					}
					case ly_Remark:
					{
						l_value.m_remark = l_date.at(i).toString();
						break;
					}
					}
					default:
						break;
					}
				}
				lyExcelDataManager::appendData(l_value);
			}
			l_itSecond++;
		}
		it++;
	}
	qDebug() << QStringLiteral("读取Excel文件导入完成");
	emit setExcelTitle(lyExcelDataManager::getAllExcelTitle());
//	layoutChanged();
//	lyWidgetManager::m_sTipTranWidget->hide();
	emit readFinished();
}

void lyExcelTableModel::writeExcelTableData(const QString&fileName)
{
	qDebug() << QStringLiteral("导出Excel文件之前");
	lyOperatorExcelFile l_lyOperatorExcelFile;
	l_lyOperatorExcelFile.writeExcelFile(fileName, lyExcelDataManager::m_SelectedTitle, lyExcelDataManager::m_ExcelData, m_columnList);
	qDebug() << QStringLiteral("导出Excel文件完成");
	emit writeFinished();
	//	lyWidgetManager::m_sTipTranWidget->hide();
}

void lyExcelTableModel::refreshTableData()
{
	emit layoutAboutToBeChanged();
	lyExcelDataManager::judgeDateConflict();
	layoutChanged();
}

void lyExcelTableModel::dataSort(const QModelIndex &index, int sort)
{
	emit layoutAboutToBeChanged();
	QVector<DateTableMes>* l_data = &(*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle];
	switch (index.column())
	{
	case ly_WriteTime:
	{
		if(sort == ly_descending)
		{
			qSort(l_data->begin(), l_data->end(), lyExcelDataManager::writeSortDe);
		}
		else
		{
			qSort(l_data->begin(), l_data->end(), lyExcelDataManager::writeSortAs);
		}
		break;
	}
	case ly_BeginTime:
	{
		if (sort == ly_descending)
		{
			qSort(l_data->begin(), l_data->end(), lyExcelDataManager::beginTimeSortDe);
		}
		else
		{
			qSort(l_data->begin(), l_data->end(), lyExcelDataManager::beginTimeSortAs);
		}
		break;
	}
	case ly_EndTime:
	{
		if (sort == ly_descending)
		{
			qSort(l_data->begin(), l_data->end(), lyExcelDataManager::endTimeSortDe);
		}
		else
		{
			qSort(l_data->begin(), l_data->end(), lyExcelDataManager::endTimeSortAs);
		}
		break;
	}
	case ly_DatePrioritization:
	{
		if (sort == ly_descending)
		{
			qSort(l_data->begin(), l_data->end(), lyExcelDataManager::PrioritizationSortDe);
		}
		else
		{
			qSort(l_data->begin(), l_data->end(), lyExcelDataManager::PrioritizationSortAs);
		}
		break;
	}
	}
	layoutChanged();
}
