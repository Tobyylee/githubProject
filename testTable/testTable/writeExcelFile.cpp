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
	//�����ļ�
	QAxObject excel("Excel.Application");
	
	excel.setProperty("Visible", false);//�Ƿ���ʾ����
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
	QAxObject *work_sheets = work_book->querySubObject("Sheets");  //SheetsҲ�ɻ���WorkSheets

																   //ɾ��������ɾ����һ����
	QAxObject *first_sheet = work_sheets->querySubObject("Item(int)", 1);
	first_sheet->dynamicCall("delete");

	//���빤�������������һ�У�
	int sheet_count = work_sheets->property("Count").toInt();  //��ȡ��������Ŀ
	QAxObject *last_sheet = work_sheets->querySubObject("Item(int)", sheet_count);
	QAxObject *work_sheet = work_sheets->querySubObject("Add(QVariant)", last_sheet->asVariant());
	last_sheet->dynamicCall("Move(QVariant)", work_sheet->asVariant());

	work_sheet->setProperty("Name", "Qt Sheet");  //���ù���������

												  //������Ԫ�񣨵�2�е�2�У�
	QAxObject *cell = work_sheet->querySubObject("Cells(int,int)", 2, 2);
	cell->setProperty("Value", "Java C++ C# PHP Perl Python Delphi Ruby");  //���õ�Ԫ��ֵ
	cell->setProperty("RowHeight", 50);  //���õ�Ԫ���и�
	cell->setProperty("ColumnWidth", 30);  //���õ�Ԫ���п�
	cell->setProperty("HorizontalAlignment", -4108); //����루xlLeft����-4131  ���У�xlCenter����-4108  �Ҷ��루xlRight����-4152
	cell->setProperty("VerticalAlignment", -4108);  //�϶��루xlTop��-4160 ���У�xlCenter����-4108  �¶��루xlBottom����-4107
	cell->setProperty("WrapText", true);  //���ݹ��࣬�Զ�����
										  //cell->dynamicCall("ClearContents()");  //��յ�Ԫ������

	QAxObject* interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(0, 255, 0));   //���õ�Ԫ�񱳾�ɫ����ɫ��

	QAxObject* border = cell->querySubObject("Borders");
	border->setProperty("Color", QColor(0, 0, 255));   //���õ�Ԫ��߿�ɫ����ɫ��

	QAxObject *font = cell->querySubObject("Font");  //��ȡ��Ԫ������
	font->setProperty("Name", QStringLiteral("���Ĳ���"));  //���õ�Ԫ������
	font->setProperty("Bold", true);  //���õ�Ԫ������Ӵ�
	font->setProperty("Size", 20);  //���õ�Ԫ�������С
	font->setProperty("Italic", true);  //���õ�Ԫ������б��
	font->setProperty("Underline", 2);  //���õ�Ԫ���»���
	font->setProperty("Color", QColor(255, 0, 0));  //���õ�Ԫ��������ɫ����ɫ��

	//���õ�Ԫ�����ݣ����ϲ���Ԫ�񣨵�5�е�3��-��8�е�5�У�
	QAxObject *cell_5_6 = work_sheet->querySubObject("Cells(int,int)", 5, 3);
	cell_5_6->setProperty("Value", "Java");  //���õ�Ԫ��ֵ
	QAxObject *cell_8_5 = work_sheet->querySubObject("Cells(int,int)", 8, 5);
	cell_8_5->setProperty("Value", "C++");

	QString merge_cell;
	merge_cell.append(QChar(3 - 1 + 'A'));  //��ʼ��
	merge_cell.append(QString::number(5));  //��ʼ��
	merge_cell.append(":");
	merge_cell.append(QChar(5 - 1 + 'A'));  //��ֹ��
	merge_cell.append(QString::number(8));  //��ֹ��
	QAxObject *merge_range = work_sheet->querySubObject("Range(const QString&)", merge_cell);
	merge_range->setProperty("HorizontalAlignment", -4108);
	merge_range->setProperty("VerticalAlignment", -4108);
	merge_range->setProperty("WrapText", true);
	merge_range->setProperty("MergeCells", true);  //�ϲ���Ԫ��
												   //merge_range->setProperty("MergeCells", false);  //��ֵ�Ԫ��
	//QAxObject *first_sheet = work_sheets->querySubObject("Item(int)", 1);
	first_sheet->dynamicCall("delete");

	work_book->dynamicCall("Save()");  //�����ļ���Ϊ�˶Ա�test�������test2�ļ������ﲻ����������� work_book->dynamicCall("SaveAs(const QString&)", "E:\\test2.xlsx");  //���Ϊ��һ���ļ� 
	work_book->dynamicCall("Close(Boolean)", false);  //�ر��ļ�
	excel.dynamicCall("Quit(void)");  //�˳�
}
