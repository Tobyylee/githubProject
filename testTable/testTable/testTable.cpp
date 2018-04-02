#include "testTable.h"
#include <QDebug>

#include "ReadProvince.h"
#include "readExcelFile.h"
#include "writeExcelFile.h"
#include "pixmapDraw.h"

QVector<personData>* testTable::m_personData = NULL;
const QString g_ExcelFileName = "D:\\project\\testTable\\testTable\\test.xlsx";
const QString g_WriteExcelFileName = "D:\\project\\testTable\\testTable\\test2.xlsx";

testTable::testTable(QWidget *parent)
	: QMainWindow(parent)
{
	m_personData = new QVector<personData>;
	personData l_personData1(QStringLiteral("李扬"), 25, 185, 75, "man");
	personData l_personData2("cyg", 25, 174, 65, "man");
	personData l_personData3("lss", 25, 175, 68, "man");
	personData l_personData4("dzy", 24, 170, 85, "man");
	personData l_personData5("yy", 23, 165, 55, "man");
	personData l_personData6("hwl", 29, 170, 68, "man", false);
	personData l_personData7("sdg", 29, 170, 68, "man", false);
	personData l_personData8("xfd", 29, 170, 68, "man", true);
	personData l_personData9("mht", 29, 170, 68, "man", true);
	personData l_personData10("xtm", 29, 170, 68, "man", true);

	m_personData->append(l_personData1);
	m_personData->append(l_personData2);
	m_personData->append(l_personData3);
	m_personData->append(l_personData4);
	m_personData->append(l_personData5);
	m_personData->append(l_personData6);
	m_personData->append(l_personData7);
	m_personData->append(l_personData8);
	m_personData->append(l_personData9);
	m_personData->append(l_personData10);
	
	int i = 0;
	i = i++;
	qDebug() << "i" << i;
	ui.setupUi(this);
	initTable();
	initSlot();
	m_dialog = new lyDialog;
	m_dialog->hide();

	m_pixmapDraw = new pixmapDraw;
	m_pixmapDraw->hide();
	//readProvince l_read;
	//l_read.readData();
	//l_read.analysesJson();
	//auto it = l_read.m_datas.begin();
	//while (it != l_read.m_datas.end())
	//{
	//	QString l_province = it->first();
	//	ui.label->setText(l_province);
	//	break;
	//}
	////读取excel文件
	//readExcelFile l_readExcelFile;
	//l_readExcelFile.openExcelFile(g_ExcelFileName);
	//l_readExcelFile.analysisExcelFile();

	//writeExcelFile l_writeExcelFile;
	//l_writeExcelFile.writeDataToFile(g_WriteExcelFileName);
	
}

testTable::~testTable()
{
	if (m_dialog)
	{
		delete m_dialog;
		m_dialog = nullptr;
	}
}

void testTable::initTable()
{
	m_testTableModel = new testTableModel(this);
	m_testSortTableModel = new testSortTableModel(this);
	m_testSortTableModel->setSourceModel(m_testTableModel);
	m_testDelegate = new testDelegate(this);
	ui.tableView->setItemDelegate(m_testDelegate);
	ui.tableView->setModel(m_testSortTableModel);
	ui.tableView->verticalHeader()->setVisible(false);
	ui.tableView->setAlternatingRowColors(true);
	ui.tableView->setMouseTracking(false);
	ui.tableView->setFocusPolicy(Qt::NoFocus);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView->setContextMenuPolicy(Qt::CustomContextMenu);
	ui.tableView->setSortingEnabled(true);
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);



	m_HasbeenreadModel = new gtrHasbeenreadModel(this);
	ui.treeView->setModel(m_HasbeenreadModel);

	m_HasbeenreadModel_2 = new gtrHasbeenreadModel(this);
	ui.treeView_2->setModel(m_HasbeenreadModel_2);
}

void testTable::initSlot()
{
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(onClicked()));
}

void testTable::onClicked()
{
	ui.tableView->update();
	m_dialog->show();
	m_pixmapDraw->show();
	//m_testTableModel->layoutAboutToBeChanged();
	/*QString l_str = ui.label->text();
	ui.tableView->selectRow(7);
	if (l_str == QStringLiteral("上海市"))
	{
		qDebug() << "suc";
	}
	else
	{
		qDebug() << "fail";
	}*/
	//m_testTableModel->layoutChanged();
}
