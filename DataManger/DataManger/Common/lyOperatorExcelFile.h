#pragma once

#include <QString>
#include <QAxObject>
#include <QVector>
#include <QMap>
#include "DateTableMes.h"
#include "lyExcelTableModel.h"

class lyOperatorExcelFile
{
public:
	lyOperatorExcelFile();
	~lyOperatorExcelFile();

	void readExcelFile(const QString& fileName);
	void writeExcelFile(const QString& fileName, const QString& tableName, QMap<QString, QVector<DateTableMes>>* datas, 
		const QStringList& head);

	QMap<QString, QMap<int, QVector<QVariant>>>& getReadExcelFileData() { return m_inputData;  }
//	QVector<QString>& getReadExcelFileTitle() { return m_inputExcelTitle;  }

	void clearDatas();

protected:
	void ReadAnalysisExcelFile();
	void AddDate();

	QAxObject* m_excel;
	QAxObject* m_readWorkBooks;
	QAxObject* m_readWorkSheets;

	QMap<QString, QMap<int, QVector<QVariant>>> m_inputData;
//	QVector<QString> m_inputExcelTitle;
};

