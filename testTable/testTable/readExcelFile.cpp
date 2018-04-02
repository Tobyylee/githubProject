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
	m_excel->setProperty("Visible", false);//�Ƿ���ʾ����
	m_workBooks = m_excel->querySubObject("WorkBooks");
	m_workBooks->dynamicCall("Open (const QString&)", fileName);
}

void readExcelFile::analysisExcelFile()
{
	QVariant title_value = m_excel->property("Caption");  //��ȡ����  
	qDebug() << QString("excel title : ") << title_value;
	QAxObject * workBook = m_excel->querySubObject("ActiveWorkBook");
	m_workSheets = workBook->querySubObject("Sheets");  //SheetsҲ�ɻ���WorkSheets
	int sheet_count = m_workSheets->property("Count").toInt();  //��ȡ��������Ŀ  
	qDebug() << QString("sheet count : ") << sheet_count;

	for (int i = 1; i <= sheet_count; i++)
	{
		QAxObject *work_sheet = workBook->querySubObject("Sheets(int)", i);  //Sheets(int)Ҳ�ɻ���Worksheets(int)  
		QString work_sheet_name = work_sheet->property("Name").toString();  //��ȡ����������  
		QString message = QString("sheet ") + QString::number(i, 10) + QString(" name");
		qDebug() << message << work_sheet_name;
	}
	if (sheet_count > 0)
	{
		QAxObject *work_sheet = workBook->querySubObject("Sheets(int)", 1);
		QAxObject *used_range = work_sheet->querySubObject("UsedRange");
		QAxObject *rows = used_range->querySubObject("Rows");
		QAxObject *columns = used_range->querySubObject("Columns");
		int row_start = used_range->property("Row").toInt();  //��ȡ��ʼ��     
		int column_start = used_range->property("Column").toInt();  //��ȡ��ʼ��  
		int row_count = rows->property("Count").toInt();  //��ȡ����  
		int column_count = columns->property("Count").toInt();  //��ȡ���� 
		qDebug() << "begin row:" << row_start << "column_start:" << column_start
			<< "row_count:" << row_count << "column_count:" << column_count;

		for (int i = row_start; i <row_start+row_count; i++)
		{
			for (int j = column_start; j < column_start+column_count; j++)
			{
				QAxObject *cell = work_sheet->querySubObject("Cells(int,int)", i, j);
				QVariant cell_value = cell->property("Value");  //��ȡ��Ԫ������
				QString message = QString("row-") + QString::number(i, 10) + QString("-column-") + QString::number(j, 10) + QString(":");
				qDebug() << message << cell_value;
			}
		}
	}
	workBook->dynamicCall("Close(Boolen)", false);    // �ر��ļ�
	m_excel->dynamicCall("Quit(void)");    // �˳�
}

void readExcelFile::onError(int code, const QString &source, const QString &desc, const QString &help)
{
	qDebug() << "code:" << code << "source:" << source << "desc:" << desc << "help:" << help;
}
