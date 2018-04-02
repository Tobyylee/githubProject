#include "writeExcelFile.h"

#include <QDebug>
#include <QColor>
#include <QFile>

writeExcelFile::writeExcelFile(QObject* object /*= nullptr*/)
{

}

writeExcelFile::~writeExcelFile()
{

}

void writeExcelFile::writeDataToFile(const QString& fileName)
{
	//创建文件
	QAxObject excel("Excel.Application");
	
	excel.setProperty("Visible", false);//是否显示窗体
	QAxObject *work_books = excel.querySubObject("WorkBooks");

	QFile file(fileName);
	if (!file.exists())
	{
		work_books->dynamicCall("Add");
		QAxObject* work_book = excel.querySubObject("ActiveWorkBook");
		work_book->dynamicCall("SaveAs(const QString&)", fileName);
	}

	work_books->dynamicCall("Open(const QString&)", fileName);
	excel.setProperty("Caption", "Qt Excel");
	QAxObject *work_book = excel.querySubObject("ActiveWorkBook");
	QAxObject *work_sheets = work_book->querySubObject("Sheets");  //Sheets也可换用WorkSheets

																   //删除工作表（删除第一个）
	QAxObject *first_sheet = work_sheets->querySubObject("Item(int)", 1);
	first_sheet->dynamicCall("delete");

	//插入工作表（插入至最后一行）
	int sheet_count = work_sheets->property("Count").toInt();  //获取工作表数目
	QAxObject *last_sheet = work_sheets->querySubObject("Item(int)", sheet_count);
	QAxObject *work_sheet = work_sheets->querySubObject("Add(QVariant)", last_sheet->asVariant());
	last_sheet->dynamicCall("Move(QVariant)", work_sheet->asVariant());

	work_sheet->setProperty("Name", "Qt Sheet");  //设置工作表名称

												  //操作单元格（第2行第2列）
	QAxObject *cell = work_sheet->querySubObject("Cells(int,int)", 2, 2);
	cell->setProperty("Value", "Java C++ C# PHP Perl Python Delphi Ruby");  //设置单元格值
	cell->setProperty("RowHeight", 50);  //设置单元格行高
	cell->setProperty("ColumnWidth", 30);  //设置单元格列宽
	cell->setProperty("HorizontalAlignment", -4108); //左对齐（xlLeft）：-4131  居中（xlCenter）：-4108  右对齐（xlRight）：-4152
	cell->setProperty("VerticalAlignment", -4108);  //上对齐（xlTop）-4160 居中（xlCenter）：-4108  下对齐（xlBottom）：-4107
	cell->setProperty("WrapText", true);  //内容过多，自动换行
										  //cell->dynamicCall("ClearContents()");  //清空单元格内容

	QAxObject* interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(0, 255, 0));   //设置单元格背景色（绿色）

	QAxObject* border = cell->querySubObject("Borders");
	border->setProperty("Color", QColor(0, 0, 255));   //设置单元格边框色（蓝色）

	QAxObject *font = cell->querySubObject("Font");  //获取单元格字体
	font->setProperty("Name", QStringLiteral("华文彩云"));  //设置单元格字体
	font->setProperty("Bold", true);  //设置单元格字体加粗
	font->setProperty("Size", 20);  //设置单元格字体大小
	font->setProperty("Italic", true);  //设置单元格字体斜体
	font->setProperty("Underline", 2);  //设置单元格下划线
	font->setProperty("Color", QColor(255, 0, 0));  //设置单元格字体颜色（红色）

	//设置单元格内容，并合并单元格（第5行第3列-第8行第5列）
	QAxObject *cell_5_6 = work_sheet->querySubObject("Cells(int,int)", 5, 3);
	cell_5_6->setProperty("Value", "Java");  //设置单元格值
	QAxObject *cell_8_5 = work_sheet->querySubObject("Cells(int,int)", 8, 5);
	cell_8_5->setProperty("Value", "C++");

	QString merge_cell;
	merge_cell.append(QChar(3 - 1 + 'A'));  //初始列
	merge_cell.append(QString::number(5));  //初始行
	merge_cell.append(":");
	merge_cell.append(QChar(5 - 1 + 'A'));  //终止列
	merge_cell.append(QString::number(8));  //终止行
	QAxObject *merge_range = work_sheet->querySubObject("Range(const QString&)", merge_cell);
	merge_range->setProperty("HorizontalAlignment", -4108);
	merge_range->setProperty("VerticalAlignment", -4108);
	merge_range->setProperty("WrapText", true);
	merge_range->setProperty("MergeCells", true);  //合并单元格
												   //merge_range->setProperty("MergeCells", false);  //拆分单元格
	//QAxObject *first_sheet = work_sheets->querySubObject("Item(int)", 1);
	first_sheet->dynamicCall("delete");

	work_book->dynamicCall("Save()");  //保存文件（为了对比test与下面的test2文件，这里不做保存操作） work_book->dynamicCall("SaveAs(const QString&)", "E:\\test2.xlsx");  //另存为另一个文件 
	work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
	excel.dynamicCall("Quit(void)");  //退出
}
