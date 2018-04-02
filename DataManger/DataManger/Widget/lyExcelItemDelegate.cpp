#include "lyExcelItemDelegate.h"

#include <QComboBox>
#include <QDateTimeEdit>
#include <QLineEdit>
#include <QDebug>

#include "lyExcelDataManager.h"
#include "lyExcelTableModel.h"
#include "DateTableMes.h"
#include "lyCityWidget.h"
#include "lyConfigManager.h"


const char* g_sMesType[]
{
	QT_TRANSLATE_NOOP("lyExcelItemDelegate", "Conference"),
	QT_TRANSLATE_NOOP("lyExcelItemDelegate", "Assignment"),
	QT_TRANSLATE_NOOP("lyExcelItemDelegate", "Incident"),
	QT_TRANSLATE_NOOP("lyExcelItemDelegate", "Train"),
};

const char* g_sDatePrioritization[]
{
	QT_TRANSLATE_NOOP("lyExcelItemDelegate", "redLight"),
	QT_TRANSLATE_NOOP("lyExcelItemDelegate", "yellowLight"),
	QT_TRANSLATE_NOOP("lyExcelItemDelegate", "GreenLight"),
};

const  char* g_sDatePlan[]
{
	QT_TRANSLATE_NOOP("lyExcelItemDelegate", "NoSelected"),
	QT_TRANSLATE_NOOP("lyExcelItemDelegate", "NoHappen"),
	QT_TRANSLATE_NOOP("lyExcelItemDelegate", "Going"),
	QT_TRANSLATE_NOOP("lyExcelItemDelegate", "Finished"),
};

lyExcelItemDelegate::lyExcelItemDelegate(QObject *parent)
	: QItemDelegate(parent)
{
}

lyExcelItemDelegate::~lyExcelItemDelegate()
{
}

QWidget * lyExcelItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	switch (index.column())
	{
		case ly_WriteTime:
		{
			QDateTimeEdit* l_dateEdit = new QDateTimeEdit(parent);
			l_dateEdit->setDateTime(QDateTime::currentDateTime());
			l_dateEdit->setCalendarPopup(true);
			return l_dateEdit;
		}
		case ly_MesSection:
		case ly_MesContent:
		case	ly_Remark:
		{
			QLineEdit* l_lineEdit = new QLineEdit(parent);
			return l_lineEdit;
			break;
		}
		case ly_MesType:
		{
			QComboBox* l_comboBox = new QComboBox(parent);
			for (int i = 0; i < lyConfigManager::m_sParConfig->m_MesTypes_Assign.size(); i++)
			{
				l_comboBox->addItem(lyConfigManager::m_sParConfig->m_MesTypes_Assign.at(i));
			}
			return l_comboBox;
			break;
		}
		case ly_DateSite:
		{
			QVector<DateTableMes>* l_data = &(*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle];
			if (l_data->at(index.row()).m_mesType == QStringLiteral("出差"))
			{
				lyCityWidget* l_cityWidget = new lyCityWidget(parent);
				l_cityWidget->setFixedSize(800, 300);
				return l_cityWidget;
			}
			else if(l_data->at(index.row()).m_mesType == QStringLiteral("会议"))
			{
				QComboBox* l_comboBox = new QComboBox(parent);
				for (int i = 0; i < lyConfigManager::m_sParConfig->m_MesTypes_Meet.size(); i++)
				{
					l_comboBox->addItem(lyConfigManager::m_sParConfig->m_MesTypes_Meet.at(i));
				}
				return l_comboBox;
			}
			else
			{
				QLineEdit* l_lineEdit = new QLineEdit(parent);
				return l_lineEdit;
			}
			break;
		}
		case ly_BeginTime:
		case ly_EndTime:
		{
			QDateTimeEdit* l_dateEdit = new QDateTimeEdit(parent);
			l_dateEdit->setDateTime(QDateTime::currentDateTime());
			l_dateEdit->setCalendarPopup(true);
			return l_dateEdit;
			break;
		}
		case ly_DatePrioritization:
		{
			//QComboBox* l_comboBox = new QComboBox(parent);
			/*for (int i = 0; i < ly_DatePrioritization_Count; i++)
			{
				l_comboBox->addItem(tr(g_sDatePrioritization[i]));
			}
			return l_comboBox;*/
			break;
		}
		case ly_DatePlan:
		{
			QComboBox* l_comboBox = new QComboBox(parent);
			for (int i = 0; i < ly_DatePlan_Count; i++)
			{
				l_comboBox->addItem(tr(g_sDatePlan[i]));
			}
			return l_comboBox;
			break;
		}
	}
	return nullptr;
}

void lyExcelItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
	switch (index.column())
	{
	case ly_WriteTime:
	{
		QDateTime value = index.model()->data(index, Qt::DisplayRole).toDateTime();
		QDateTimeEdit* l_dateEdit = static_cast<QDateTimeEdit*>(editor);
		l_dateEdit->setDateTime(value);
		break;
	}
	case ly_MesSection:
	case ly_MesContent:
	case	ly_Remark:
	{
		QString value = index.model()->data(index, Qt::DisplayRole).toString();
		QLineEdit* l_lineEdit = static_cast<QLineEdit*>(editor);
		l_lineEdit->setText(value);
		break;
	}
	case ly_MesType:
	case ly_DatePrioritization:
	case ly_DatePlan:
	{
		QString value = index.model()->data(index, Qt::DisplayRole).toString();
		QComboBox* l_comboBox = static_cast<QComboBox*>(editor);
		l_comboBox->setCurrentText(value);
		break;
	}
	case ly_DateSite:
	{
		/*lyCityWidget* l_cityWidget = static_cast<lyCityWidget*>(editor);
		l_cityWidget->show();*/
		break;
	}
	case ly_BeginTime:
	{
		QVector<DateTableMes>* l_data = &(*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle];
		QDateTime l_endTime = l_data->at(index.row()).m_endTime;
		QDateTime value = index.model()->data(index, Qt::DisplayRole).toDateTime();
		if (l_endTime.isValid())
		{
			if (l_endTime < value)
			{
				DateTableMes l_dateTableMes = l_data->at(index.row());
				l_dateTableMes.m_endTime = value;
				l_data->replace(index.row(), l_dateTableMes);
			}
		}
		QDateTimeEdit* l_dateEdit = static_cast<QDateTimeEdit*>(editor);
		l_dateEdit->setDateTime(value);
		break;
	}
	case ly_EndTime:
	{
		QVector<DateTableMes>* l_data = &(*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle];
		QDateTime l_beginTime = l_data->at(index.row()).m_beginTime;
		QDateTime value = index.model()->data(index, Qt::DisplayRole).toDateTime();
		if (l_beginTime.isValid())
		{
			if (l_beginTime > value)
			{
				value = l_beginTime;
			}
		}
		QDateTimeEdit* l_dateEdit = static_cast<QDateTimeEdit*>(editor);
		l_dateEdit->setDateTime(value);
		break;
	}
	case ly_Conflict:
	{
		break;
	}
	default:
		break;
	}
	qDebug() << "setEdier";
}

void lyExcelItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
	qDebug() << "setModelData";
	switch (index.column())
	{
	case ly_WriteTime:
	{
		QDateTimeEdit* l_dateEdit = static_cast<QDateTimeEdit*>(editor);
		QDateTime l_dateTime = l_dateEdit->dateTime();
		model->setData(index, l_dateTime);
		break;
	}
	case ly_MesSection:
	case ly_MesContent:
	case	ly_Remark:
	{
		//QString value = index.model()->data(index, Qt::DisplayRole).toString();
		QLineEdit* l_lineEdit = static_cast<QLineEdit*>(editor);
		//l_lineEdit->setText(value);
		QString value  =  l_lineEdit->text();
		model->setData(index, value);
		break;
	}
	case ly_MesType:
	case ly_DatePrioritization:
	case ly_DatePlan:
	{
		//QString value = index.model()->data(index, Qt::DisplayRole).toString();
		QComboBox* l_comboBox = static_cast<QComboBox*>(editor);
		QString value = l_comboBox->currentText();
		model->setData(index, value);
		break;
	}
	case ly_DateSite:
	{
		QVector<DateTableMes>* l_data = &(*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle];
		if (l_data->at(index.row()).m_mesType == QStringLiteral("出差"))
		{
			lyCityWidget* l_cityWidget = static_cast<lyCityWidget*>(editor);
			QString value = l_cityWidget->getCurrentCity();
			model->setData(index, value);
		}
		else if (l_data->at(index.row()).m_mesType == QStringLiteral("会议"))
		{
			QComboBox* l_comboBox = static_cast<QComboBox*>(editor);
			QString l_data = l_comboBox->currentText();
			model->setData(index, l_data);
		}
		else
		{
			QLineEdit* l_lineEdit = static_cast<QLineEdit*>(editor);
			QString l_data = l_lineEdit->text();
			model->setData(index, l_data);
		}
		break;
	}
	case ly_BeginTime:
	case ly_EndTime:
	{
		//QDateTime value = index.model()->data(index, Qt::DisplayRole).toDateTime();
		QDateTimeEdit* l_dateEdit = static_cast<QDateTimeEdit*>(editor);
		QDateTime l_dateTime = l_dateEdit->dateTime();
		model->setData(index, l_dateTime);
		break;
	}
	case ly_Conflict:
	{
		break;
	}
	default:
		break;
	}
}

void lyExcelItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	editor->setGeometry(option.rect);
}

//bool lyExcelItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
//{
//	/*if (index.column() == ly_DateSite&&event->type() == QEvent::MouseButtonDblClick)
//	{
//		return true;
//	}*/
//	//bool l_flag = QItemDelegate::editorEvent(event, model, option, index);
//	//qDebug() << "editorEvent" << index.row() << index.column()<< l_flag;
////	if()
////	return l_flag;
//}
