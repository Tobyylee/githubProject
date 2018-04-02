#include "lyOperatorExcelFile.h"

#include <QDebug>
#include <QFile>
#include <QColor>

#include "lyExcelDataManager.h"
#include "lyTipTranWidget.h"

lyOperatorExcelFile::lyOperatorExcelFile()
{
	m_excel = new QAxObject("Excel.Application");
}


lyOperatorExcelFile::~lyOperatorExcelFile()
{
}

void lyOperatorExcelFile::readExcelFile(const QString& fileName)
{
	//yTipTranWidget l_tipTranWidget(nullptr, QStringLiteral("导入中，请稍后"));
	m_excel->setProperty("Visible", false);//是否显示窗体
	m_readWorkBooks = m_excel->querySubObject("WorkBooks");
	m_readWorkBooks->dynamicCall("Open (const QString&)", fileName);
	ReadAnalysisExcelFile();
}

void lyOperatorExcelFile::writeExcelFile(const QString& fileName, const QString& tableName, QMap<QString, QVector<DateTableMes>>* datas, 
	const QStringList& head)
{
	QAxObject excel("Excel.Application");

	excel.setProperty("Visible", false);//是否显示窗体
	QAxObject *work_books = excel.querySubObject("WorkBooks");

	QString l_fileName = fileName + "\\" + tableName+QString(".xlsx");
	l_fileName = l_fileName.replace(QString("/"), QString("\\"));
	QFile file(l_fileName);
	if (!file.exists())
	{
		work_books->dynamicCall("Add");//添加工作簿
		QAxObject* work_book = excel.querySubObject("ActiveWorkBook");//获取活动工作簿
		work_book->dynamicCall("SaveAs(const QString&)", l_fileName);
	}
	

	work_books->dynamicCall("Open(const QString&)", l_fileName);
	excel.setProperty("Caption", "Qt Excel");
	QAxObject *work_book = excel.querySubObject("ActiveWorkBook");
	QAxObject *work_sheets = work_book->querySubObject("Sheets");  //Sheets也可换用WorkSheets，获取所有工作表

																   //删除工作表（删除第一个）
	QAxObject *first_sheet = work_sheets->querySubObject("Item(int)", 1);
	first_sheet->dynamicCall("delete");

	//插入工作表（插入至最后一行）
	int sheet_count = work_sheets->property("Count").toInt();  //获取工作表数目
	QAxObject *last_sheet = work_sheets->querySubObject("Item(int)", sheet_count);
	QAxObject *work_sheet = work_sheets->querySubObject("Add(QVariant)", last_sheet->asVariant());
	last_sheet->dynamicCall("Move(QVariant)", work_sheet->asVariant());

	work_sheet->setProperty("Name", tableName);  //设置工作表名称

												  //操作单元格（第2行第2列）
	QVector<DateTableMes> l_dataTableMes = (*datas)[tableName];

	for (int i = 0; i < ly_Head_Count-1; i++)
	{
		QAxObject* cell = work_sheet->querySubObject("Cells(int,int)", 1, i+1);
		cell->setProperty("Value", head.at(i));
	}
	for (int i = 0; i < l_dataTableMes.size(); i++)
	{
		int l_count = 0;
		for (int j = 0; j < ly_Head_Count-1; j++)
		{
			QAxObject* cell = work_sheet->querySubObject("Cells(int,int)", i + 2, j + 1);
			if (l_dataTableMes.at(i).m_bConflict)
			{
				QAxObject* interior = cell->querySubObject("Interior");
				interior->setProperty("Color", QColor(255, 0, 0));   //设置单元格背景色（绿色）
			}
			switch (j)
			{
			case ly_WriteTime:
			{
				cell->setProperty("Value", l_dataTableMes.at(i).m_writeTime.toString(g_dateFormat));
				break;
			}
			case ly_MesSection:
			{
				cell->setProperty("Value", l_dataTableMes.at(i).m_mesSection);
				break;
			}
			case ly_MesType:
			{
				cell->setProperty("Value", l_dataTableMes.at(i).m_mesType);
				break;
			}
			case ly_MesContent:
			{
				cell->setProperty("Value", l_dataTableMes.at(i).m_mesContent);
				break;
			}
			case ly_DateSite:
			{
				cell->setProperty("Value", l_dataTableMes.at(i).m_dateSite);
				break;
			}
			case ly_BeginTime:
			{
				cell->setProperty("Value", l_dataTableMes.at(i).m_beginTime.toString(g_dateFormat));
				break;
			case ly_EndTime:
			{
				cell->setProperty("Value", l_dataTableMes.at(i).m_endTime.toString(g_dateFormat));
				break;
			}
			case ly_DatePrioritization:
			{
				cell->setProperty("Value", l_dataTableMes.at(i).m_datePrioritization);
				break;
			}
			case ly_DatePlan:
			{
				cell->setProperty("Value", l_dataTableMes.at(i).m_datePlan);
				break;
			}
			case ly_Remark:
			{
				cell->setProperty("Value", l_dataTableMes.at(i).m_remark);
				break;
			}
			}
			//	cell->setProperty("Value", "Java C++ C# PHP Perl Python Delphi Ruby");  //设置单元格值
			}
			
		}
	}
		first_sheet->dynamicCall("delete");

		work_book->dynamicCall("Save()");  //保存文件（为了对比test与下面的test2文件，这里不做保存操作） work_book->dynamicCall("SaveAs(const QString&)", "E:\\test2.xlsx");  //另存为另一个文件 
		work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
		excel.dynamicCall("Quit(void)");  //退出
}


void lyOperatorExcelFile::clearDatas()
{
	m_inputData.clear();
//	m_inputExcelTitle.clear();
}

void lyOperatorExcelFile::ReadAnalysisExcelFile()
{
	QVariant title_value = m_excel->property("Caption");  //获取标题  
	qDebug() << QString("excel title : ") << title_value;
	QAxObject * workBook = m_excel->querySubObject("ActiveWorkBook");
	m_readWorkSheets = workBook->querySubObject("Sheets");  //Sheets也可换用WorkSheets
	int sheet_count = m_readWorkSheets->property("Count").toInt();  //获取工作表数目  
	qDebug() << QString("sheet count : ") << sheet_count;

	for (int i = 1; i <= sheet_count; i++)
	{
		QAxObject *work_sheet = workBook->querySubObject("Sheets(int)", i);  //Sheets(int)也可换用Worksheets(int)  
		QString work_sheet_name = work_sheet->property("Name").toString();  //获取工作表名称  
		work_sheet_name = lyExcelDataManager::getTitleName(work_sheet_name);
		QString message = QString("sheet ") + QString::number(i, 10) + QString(" name");
	//	m_inputExcelTitle.append(work_sheet_name);
		qDebug() << message << work_sheet_name;

		//===========================
		QAxObject *work_sheet2 = workBook->querySubObject("Sheets(int)", i);
		QAxObject *used_range = work_sheet2->querySubObject("UsedRange");
		QAxObject *rows = used_range->querySubObject("Rows");
		QAxObject *columns = used_range->querySubObject("Columns");
		int row_start = used_range->property("Row").toInt();  //获取起始行     
		int column_start = used_range->property("Column").toInt();  //获取起始列  
		int row_count = rows->property("Count").toInt();  //获取行数  
		int column_count = columns->property("Count").toInt();  //获取列数 
		qDebug() << "begin row:" << row_start << "column_start:" << column_start
			<< "row_count:" << row_count << "column_count:" << column_count;
		QMap<int, QVector<QVariant>> l_datas;
		for (int i = row_start; i < row_start + row_count; i++)
		{
			QVector<QVariant> l_data;
			for (int j = column_start; j < column_start + column_count; j++)
			{
				QAxObject *cell = work_sheet->querySubObject("Cells(int,int)", i, j);
				QVariant cell_value = cell->property("Value");  //获取单元格内容
				QString message = QString("row-") + QString::number(i, 10) + QString("-column-") + QString::number(j, 10) + QString(":");
				qDebug() << message << cell_value.toString();
				l_data.append(cell_value);
			}
			l_datas[i - row_start] = l_data;
		}
		m_inputData[work_sheet_name] = l_datas;
	}

	workBook->dynamicCall("Close(Boolen)", false);    // 关闭文件
	m_excel->dynamicCall("Quit(void)");    // 退出
}

void lyOperatorExcelFile::AddDate()
{

}
