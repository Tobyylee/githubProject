#ifndef TESTPIPECHILD_H
#define TESTPIPECHILD_H

#include <QtWidgets/QMainWindow>
#include "ui_testpipechild.h"
#include "PipeChild.h"
class TestPipeChild : public QMainWindow
{
	Q_OBJECT

public:
	TestPipeChild(QWidget *parent = 0);
	~TestPipeChild();

public slots:
	void onSendBtn();
	void onReceiveBtn();
	void onShowReadData(std::string data);
private:
	Ui::TestPipeChildClass ui;
	PipeChild m_pipeChild;
};

#endif // TESTPIPECHILD_H
