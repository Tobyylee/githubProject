#include "readExcelFile.h"

#include <QDebug>

readExcelFile::readExcelFile(QObject* object) : QObject(object)
{
	m_excel = new QAxObject("Excel.Application");
	connect(m_excel, SIGNAL(exception(int, const QString&, const QString&, const QString&)), this, 
		SLOT(onError(int, const QString&, const QString&, const QString&)));
}

readExcelFile::~readExcelFile()
{
	if (m_excel)
	{
		delete m_excel;
		m_excel = nullptr;
	}
}

void readExcelFile::openExcelFile(const QString& fileName)
{
	m_excel->setProperty("Visible", false);//是否显示窗体
	m_workBooks = m_excel->querySubObject("WorkBooks");
	m_workBooks->dynamicCall("Open (const QString&)", fileName);
}

void readExcelFile::analysisExcelFile()
{
	QVariant title_value = m_excel->property("Caption");  //获取标题  
	qDebug() << QString("excel title : ") << title_value;
	QAxObject * workBook = m_excel->querySubObject("ActiveWorkBook");
	m_workSheets = workBook->querySubObject("Sheets");  //Sheets也可换用WorkSheets
	int sheet_count = m_workSheets->property("Count").toInt();  //获取工作表数目  
	qDebug() << QString("sheet count : ") << sheet_count;

	for (int i = 1; i <= sheet_count; i++)
	{
		QAxObject *work_sheet = workBook->querySubObject("Sheets(int)", i);  //Sheets(int)也可换用Worksheets(int)  
		QString work_sheet_name = work_sheet->property("Name").toString();  //获取工作表名称  
		QString message = QString("sheet ") + QString::number(i, 10) + QString(" name");
		qDebug() << message << work_sheet_name;
	}
	if (sheet_count > 0)
	{
		QAxObject *work_sheet = workBook->querySubObject("Sheets(int)", 1);
		QAxObject *used_range = work_sheet->querySubObject("UsedRange");
		QAxObject *rows = used_range->querySubObject("Rows");
		QAxObject *columns = used_range->querySubObject("Columns");
		int row_start = used_range->property("Row").toInt();  //获取起始行     
		int column_start = used_range->property("Column").toInt();  //获取起始列  
		int row_count = rows->property("Count").toInt();  //获取行数  
		int column_count = columns->property("Count").toInt();  //获取列数 
		qDebug() << "begin row:" << row_start << "column_start:" << column_start
			<< "row_count:" << row_count << "column_count:" << column_count;

		for (int i = row_start; i <row_start+row_count; i++)
		{
			for (int j = column_start; j < column_start+column_count; j++)
			{
				QAxObject *cell = work_sheet->querySubObject("Cells(int,int)", i, j);
				QVariant cell_value = cell->property("Value");  //获取单元格内容
				QString message = QString("row-") + QString::number(i, 10) + QString("-column-") + QString::number(j, 10) + QString(":");
				qDebug() << message << cell_value;
			}
		}
	}
	workBook->dynamicCall("Close(Boolen)", false);    // 关闭文件
	m_excel->dynamicCall("Quit(void)");    // 退出
}

void readExcelFile::onError(int code, const QString &source, const QString &desc, const QString &help)
{
	qDebug() << "code:" << code << "source:" << source << "desc:" << desc << "help:" << help;
}
