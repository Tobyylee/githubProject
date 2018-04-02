#include "lyMainWidget.h"
#include <QDebug>
#include <QDateTime>
#include <QFileDialog>
#include <QHeaderView>
#include <QModelIndex>
#include <QMetaType>    

#include "DateTableMes.h"
#include "lyExcelDataManager.h"
#include "lyOperatorExcelFile.h"
#include "lyFileIOThreadObject.h"
#include "lyTipTranWidget.h"
#include "lyWidgetManager.h"
#include "lyDataBase.h"


const char* g_sMenuActions[]
{
	QT_TRANSLATE_NOOP("lyMainWidget", "editRow"),
	QT_TRANSLATE_NOOP("lyMainWidget", "insertRow"),
	QT_TRANSLATE_NOOP("lyMainWidget", "deleteRow"),
	QT_TRANSLATE_NOOP("lyMainWidget", "refreshList"),
	QT_TRANSLATE_NOOP("lyMainWidget", "sortDesColumn"),
	QT_TRANSLATE_NOOP("lyMainWidget", "sortAscColumn"),
};

const char* g_sfFindComboBoxItems[]
{
	QT_TRANSLATE_NOOP("lyMainWidget", "writeTime"),
	QT_TRANSLATE_NOOP("lyMainWidget", "dateType"),
	QT_TRANSLATE_NOOP("lyMainWidget", "dateSite"),
	QT_TRANSLATE_NOOP("lyMainWidget", "beginTime"),
	QT_TRANSLATE_NOOP("lyMainWidget", "endTime"),
};

//const QString g_sfFindComboBoxItems[ly_FindComboBoxItem_count] =
//{
//		QStringLiteral("录入时间"),
//		QStringLiteral("信息分类"),
//		QStringLiteral("日程地点"),
//		QStringLiteral("发生日期"),
//		QStringLiteral("结束日期"),
//};

const int g_timer = 5000;

lyMainWidget::lyMainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	initWidget();
	initData();
	initSlot();
}

lyMainWidget::~lyMainWidget()
{
	m_fileIOThread.quit();
	m_fileIOThread.wait();
	if (m_fileIOThreadObject)
	{
		delete m_fileIOThreadObject;
		m_fileIOThreadObject = nullptr;
	}
}

void lyMainWidget::initWidget()
{
	m_excelTableModel = new lyExcelTableModel(this);
	/*m_excelItemProxyModel = new lyExcelItemProxyModel(this);
	m_excelItemProxyModel->setSourceModel(m_excelTableModel);*/
	m_excelItemDelegate = new lyExcelItemDelegate(this);
	ui.tableView->setItemDelegate(m_excelItemDelegate);
	ui.tableView->setModel(m_excelTableModel);
	ui.tableView->setAlternatingRowColors(true);
	ui.tableView->setMouseTracking(false);
	//	ui.tableView->setFocusPolicy(Qt::NoFocus);
	//	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView->setContextMenuPolicy(Qt::CustomContextMenu);
	ui.tableView->setSortingEnabled(true);
	ui.tableView->verticalHeader()->show();
	//ui.tableView->openPersistentEditor(QModelIndex());
	for (int i = 0; i < ly_FindComboBoxItem_count; i++)
	{
		ui.findComboBox->addItem(tr(g_sfFindComboBoxItems[i]));
	}

	m_fileIOThreadObject = new lyFileIOThreadObject();
	m_fileIOThreadObject->setDataModel(m_excelTableModel);
	m_fileIOThreadObject->moveToThread(&m_fileIOThread);
	m_fileIOThread.start();

	m_menu = new QMenu();
	for (int i = 0; i < ly_menuAction_Count; i++)
	{
		m_actions[i] = m_menu->addAction(tr(g_sMenuActions[i]));
	}
	m_menu->hide();

	m_checkTime.start(g_timer);
}

void lyMainWidget::initData()
{
	ui.beginTimeEdit->setDateTime(QDateTime::currentDateTime());
	ui.beginTimeEdit->setCalendarPopup(true);
	ui.endTimeEdit->setDateTime(QDateTime::currentDateTime());
	ui.endTimeEdit->setCalendarPopup(true);
	m_findComboBoxIndex = 0;
	ui.comboBox->addItems(lyExcelDataManager::getAllExcelTitle());
	ui.renameEdit->setText(lyExcelDataManager::m_SelectedTitle);
}

void lyMainWidget::initSlot()
{
	connect(ui.tableView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(onActivated(const QModelIndex&)));
	connect(ui.tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(onContextMenu(QPoint)));
	for (int i = 0; i < ly_menuAction_Count; i++)
	{
		connect(m_actions[i], SIGNAL(triggered()), this, SLOT(onAction()));
	}

	connect(m_excelTableModel, SIGNAL(setExcelTitle(const QStringList&)), this, SLOT(onAddExcelTitle(const QStringList&)));
	connect(m_excelTableModel, SIGNAL(readFinished()), this, SLOT(onOperatorFinished()));
	connect(m_excelTableModel, SIGNAL(writeFinished()), this, SLOT(onOperatorFinished()));
	connect(ui.comboBox, SIGNAL(activated(int)), this, SLOT(onComboBox(int)));
	connect(ui.findComboBox, SIGNAL(activated(int)), this, SLOT(onFindComboBox(int)));
	connect(ui.deleteBtn, SIGNAL(clicked()), this, SLOT(onDeletePage()));
	connect(ui.buildPageBtn, SIGNAL(clicked()), this, SLOT(onBuildPage()));
	connect(ui.findBtn, SIGNAL(clicked()), this, SLOT(onQueryData()));
	connect(ui.renameBtn, SIGNAL(clicked()), this, SLOT(onRename()));

	connect(&m_checkTime, SIGNAL(timeout()), this, SLOT(onCheckTImer()));
	
	connect(this, SIGNAL(readExcelFile(const QString&)), m_fileIOThreadObject, SLOT(readExcelData(const QString&)));
	connect(this, SIGNAL(writeExcelFile(const QString&)), m_fileIOThreadObject, SLOT(writeExcelData(const QString&)));
	
}

void lyMainWidget::setExcelTableData(const QString& fileName)
{
	lyWidgetManager::m_sTipTranWidget->show();
	lyWidgetManager::m_sTipTranWidget->setContent(QStringLiteral("文件读取中，请稍后"));
	m_excelTableModel->layoutAboutToBeChanged();
	emit readExcelFile(fileName);
//	m_excelTableModel->setExcelTableData(fileName);
}

void lyMainWidget::writeExcelTableData(const QString&fileName)
{
	lyWidgetManager::m_sTipTranWidget->show();
	lyWidgetManager::m_sTipTranWidget->setContent(QStringLiteral("文件写入中，请稍后"));
	m_excelTableModel->layoutAboutToBeChanged();
	emit writeExcelFile(fileName);
//	m_excelTableModel->writeExcelTableData(fileName);
}

void lyMainWidget::resizeEvent(QResizeEvent *event)
{
	for (int i = 0; i < ly_Head_Count; i++)
	{
		ui.tableView->setColumnWidth(i, ui.tableView->width() / ly_Head_Count);
	}
}

void lyMainWidget::onActivated(const QModelIndex &index)
{

}

void lyMainWidget::onContextMenu(QPoint point)
{
	QModelIndex l_index = ui.tableView->indexAt(point);
	QPoint l_point = ui.tableView->mapToGlobal(point);
	m_menu->move(l_point);
	m_menu->show();
	m_rightPressed = point;
}

void lyMainWidget::onAction()
{
	int l_indexRow = -1;
	QAction* l_action = qobject_cast<QAction*>(sender());
	for (int i = 0; i < ly_menuAction_Count; i++)
	{
		if (m_actions[i] == l_action)
		{
			l_indexRow = i;
			break;
		}
	}
	QVector<DateTableMes>* l_data = &(*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle];
	QModelIndex l_index = ui.tableView->indexAt(m_rightPressed);
	switch (l_indexRow)
	{
	case ly_Edit_row:
	{
		if (l_index.row() < 0) return;
		lyDataMesDialog l_dataMesDialog;
		l_dataMesDialog.setDataMes(l_data->at(l_index.row()));
		l_dataMesDialog.initDate();
		l_dataMesDialog.show();
		l_dataMesDialog.exec();
		if (l_dataMesDialog.isConfirm())
		{
			m_excelTableModel->editRows(l_index.row(), 1, l_index, l_dataMesDialog.getDateMes());
			lyDataBase::getInstance()->insertExcelData(l_dataMesDialog.getDateMes());
		}
		/*m_dataMesDialog->initDate();
		m_dataMesDialog->show();*/
	//	m_dataMesDialog->exec();
	//m_excelTableModel->addRows(l_index.row(), 1, l_index);
		break;
	}
	case ly_insert_row:
	{
		lyDataMesDialog l_dataMesDialog;
		l_dataMesDialog.setDataMes(DateTableMes(QDateTime::currentDateTime(), "", "", "", "", QDateTime::currentDateTime(), QDateTime::currentDateTime()));
		l_dataMesDialog.initDate();
		l_dataMesDialog.show();
		l_dataMesDialog.exec();
		if (l_dataMesDialog.isConfirm())
		{
			m_excelTableModel->insertRows(l_index.row(), 1, l_index, l_dataMesDialog.getDateMes());
		}
	//	m_dataMesDialog->exec();
	//	m_excelTableModel->insertRows(l_index.row(), 1, l_index);
		break;
	}
	case ly_delete_row:
	{
		if (l_index.row() > 0)
		{
			m_excelTableModel->removeRows(l_index.row(), 1, l_index);
		}
		break;
	}
	case ly_refresh_list:
	{
		m_excelTableModel->refreshTableData();
		break;
	}
	case ly_sort_Des:
	{
		m_excelTableModel->dataSort(l_index, ly_descending);
		break;
	}
	case ly_sort_Asc:
	{
		m_excelTableModel->dataSort(l_index, ly_sort_Asc);
		break;
	}
	default:
		break;
	}
	ui.tableView->update();
}

void lyMainWidget::onAddExcelTitle(const QStringList& list)
{
	ui.comboBox->clear();
	ui.comboBox->addItems(list);
	for (int i = 0; i < list.size(); i++)
	{
		if (list.at(i) == lyExcelDataManager::m_SelectedTitle)
		{
			ui.comboBox->setCurrentIndex(i);//设置当前行
			break;
		}
	}
}

void lyMainWidget::onComboBox(int index)
{
	m_excelTableModel->layoutAboutToBeChanged();
	lyExcelDataManager::m_SelectedTitle = ui.comboBox->currentText();
	ui.renameEdit->setText(lyExcelDataManager::m_SelectedTitle);
	m_excelTableModel->layoutChanged();
}

void lyMainWidget::onFindComboBox(int index)
{
	m_findComboBoxIndex = ui.findComboBox->currentIndex();
	if (m_findComboBoxIndex == ly_find_DataSite)
	{
		ui.stackedWidget->setCurrentIndex(1);
	}
	else if (m_findComboBoxIndex == ly_find_MesType)
	{
		ui.stackedWidget->setCurrentIndex(2);
	}
	else
	{
		ui.stackedWidget->setCurrentIndex(0);
	}
}

void lyMainWidget::onDeletePage()
{
	m_excelTableModel->layoutAboutToBeChanged();
	QString l_deleteTitle = ui.comboBox->currentText();
	qDebug() << l_deleteTitle;
	lyExcelDataManager::deleteTitle(l_deleteTitle);
	m_excelTableModel->layoutChanged();
	ui.comboBox->clear();
	ui.comboBox->addItems(lyExcelDataManager::getAllExcelTitle());
	ui.comboBox->setCurrentText(lyExcelDataManager::m_SelectedTitle);
}

void lyMainWidget::onBuildPage()
{
	QString pageName = ui.pageNameLineEdit->text();
	if (pageName.isEmpty())
	{
		pageName = QString("default");
	}
	pageName = lyExcelDataManager::getTitleName(pageName);
	lyExcelDataManager::creatNewPage(pageName);
	ui.comboBox->clear();
	ui.comboBox->addItems(lyExcelDataManager::getAllExcelTitle());
	m_excelTableModel->refreshTableData();
	ui.comboBox->setCurrentText(lyExcelDataManager::m_SelectedTitle);
}

void lyMainWidget::onOperatorFinished()
{
	lyWidgetManager::m_sTipTranWidget->hide();
	m_excelTableModel->layoutChanged();
}

void lyMainWidget::onCheckTImer()
{
	m_excelTableModel->layoutAboutToBeChanged();
	lyExcelDataManager::judgeDateConflict();
	lyExcelDataManager::checkDataUrgency();
	m_excelTableModel->layoutChanged();
}

void lyMainWidget::onQueryData()
{
	switch (m_findComboBoxIndex)
	{
	case ly_find_WriteTime:
	{
		lyDataBase::getInstance()->getExcelData(ui.beginTimeEdit->dateTime(), ui.endTimeEdit->dateTime()
			, (*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle], ly_WriteTime);
		break;
	}
	case ly_find_MesType:
	{
		lyDataBase::getInstance()->getExcelData(ui.dateSiteEdit->text(), (*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle], ly_MesType);
		break;
	}
	case ly_find_DataSite:
	{
		lyDataBase::getInstance()->getExcelData(ui.dateSiteEdit->text(), (*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle], ly_DateSite);
		break;
	}
	case ly_find_BeginTime:
	{
		lyDataBase::getInstance()->getExcelData(ui.beginTimeEdit->dateTime(), ui.endTimeEdit->dateTime()
			, (*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle], ly_BeginTime);
		break;
	}
	case ly_find_EndTime:
	{
		lyDataBase::getInstance()->getExcelData(ui.beginTimeEdit->dateTime(), ui.endTimeEdit->dateTime()
			, (*lyExcelDataManager::m_ExcelData)[lyExcelDataManager::m_SelectedTitle], ly_EndTime);
		break;
	}
	default:
		break;
	}
	
}

void lyMainWidget::onRename()
{
	QString newName = ui.renameEdit->text();
	if (newName == lyExcelDataManager::m_SelectedTitle) return;
	if (newName.isEmpty())
	{
		newName = QString("default");
	}
	newName = lyExcelDataManager::getTitleName(newName);
	lyExcelDataManager::renameTable(lyExcelDataManager::m_SelectedTitle, newName);
//	lyExcelDateManager::creatNewPage(pageName);
	ui.comboBox->clear();
	ui.comboBox->addItems(lyExcelDataManager::getAllExcelTitle());
	m_excelTableModel->refreshTableData();
	ui.comboBox->setCurrentText(lyExcelDataManager::m_SelectedTitle);
}
