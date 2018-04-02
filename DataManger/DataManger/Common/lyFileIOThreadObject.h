#pragma once

#include <QObject>
class lyExcelTableModel;

class lyFileIOThreadObject : public QObject
{
	Q_OBJECT

public:
	lyFileIOThreadObject(QObject *parent = nullptr);
	~lyFileIOThreadObject();

	void setDataModel(lyExcelTableModel* model) { m_excelTableModel = model;  }
public slots:
	void writeExcelData(const QString& fileName);
	void readExcelData(const QString& fileName);

protected:
	lyExcelTableModel* m_excelTableModel;
};
