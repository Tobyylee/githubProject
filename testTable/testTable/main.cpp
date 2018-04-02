#include "testTable.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	testTable w;
	w.show();
	return a.exec();
}
