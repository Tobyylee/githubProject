#pragma once

#include <QString>

class readPNG
{
public:
	readPNG();
	virtual ~readPNG();

	void readFile(const QString& fileName);

	QByteArray m_byteArray;
};