#ifndef  WRITEEXCELFILE_H_
#define WRITEEXCELFILE_H_

#include <QObject>
#include <QAxObject>

class writeExcelFile : public QObject 
{
	Q_OBJECT
public:
	writeExcelFile(QObject* object = nullptr);
	virtual ~writeExcelFile();

	void writeDataToFile(const QString& fileName);
protected:

};
#pragma once
#endif //  WRITEEXCELFILE_H_
