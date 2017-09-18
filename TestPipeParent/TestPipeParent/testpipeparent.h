#ifndef TESTPIPEPARENT_H
#define TESTPIPEPARENT_H

#include <QtWidgets/QMainWindow>
#include "ui_testpipeparent.h"
#include "ParentProcess.h"

class TestPipeParent : public QMainWindow
{
	Q_OBJECT

public:
	TestPipeParent(QWidget *parent = 0);
	~TestPipeParent();

public slots:
	void onSendBtn();
	void onReceiveBtn();

private:
	Ui::TestPipeParentClass ui;
	ParentProcess m_process;
};

#endif // TESTPIPEPARENT_H
