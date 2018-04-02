#include "lyFileIOThreadObject.h"
#include "lyExcelTableModel.h"

lyFileIOThreadObject::lyFileIOThreadObject(QObject *parent)
	: QObject(parent)
{
}

lyFileIOThreadObject::~lyFileIOThreadObject()
{
}

void lyFileIOThreadObject::writeExcelData(const QString& fileName)
{
	m_excelTableModel->writeExcelTableData(fileName);
}

void lyFileIOThreadObject::readExcelData(const QString& fileName)
{
	m_excelTableModel->setExcelTableData(fileName);
}
