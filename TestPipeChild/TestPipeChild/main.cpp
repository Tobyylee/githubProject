#include "testpipechild.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestPipeChild w;
	w.show();
	return a.exec();
}
