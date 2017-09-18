#include "testpipeparent.h"

TestPipeParent::TestPipeParent(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_process.onCreatPipe();
	connect(ui.m_sendBtn, SIGNAL(clicked()), this, SLOT(onSendBtn()));
	connect(ui.m_receiveBtn, SIGNAL(clicked()), this, SLOT(onReceiveBtn()));
}

TestPipeParent::~TestPipeParent()
{

}

void TestPipeParent::onSendBtn()
{
	QString l_text = ui.m_sendText->toPlainText();
	m_process.onPipeWrite(l_text.toLatin1().data());
}
void TestPipeParent::onReceiveBtn()
{
	ui.m_receiveText->setText(QString::fromStdString(m_process.onPipeRead()));
}
