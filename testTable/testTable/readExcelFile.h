#ifndef READEXCELFILE_H_ 
#define READEXCELFILE_H_

#include <QObject>
#include <QAxObject>


class readExcelFile : public QObject
{
	Q_OBJECT
public:
	readExcelFile(QObject* object = nullptr);
	virtual ~readExcelFile();

	void openExcelFile(const QString& fileName);
	void analysisExcelFile();

public slots:
	void onError(int code, const QString &source, const QString &desc, const QString &help);

protected:
	QAxObject* m_excel;
	QAxObject* m_workBooks;
	QAxObject* m_workSheets;

};
#pragma once
#endif // 
