#pragma once

#include "readPNG.h"

#include <QFile>

readPNG::readPNG()
{

}

readPNG::~readPNG()
{

}

void readPNG::readFile(const QString& fileName)
{
	QFile l_file(fileName);
	if (!l_file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return;
	}
	while (!l_file.atEnd()) {
		m_byteArray = l_file.readAll();
	}
}
