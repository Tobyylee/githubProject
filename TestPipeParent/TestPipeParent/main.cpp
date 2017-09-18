#include "testpipeparent.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestPipeParent w;
	w.show();
	return a.exec();
}
