#include "testpipechild.h"

TestPipeChild::TestPipeChild(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_pipeChild.OnInitialUpdate();
	connect(&m_pipeChild, SIGNAL(sendReadData(std::string)), this, SLOT(onSendBtn()));

	connect(ui.m_sendBtn, SIGNAL(clicked()), this, SLOT(onSendBtn()));
	connect(ui.m_receiveBtn, SIGNAL(clicked()), this, SLOT(onReceiveBtn()));
}

TestPipeChild::~TestPipeChild()
{

}

void TestPipeChild::onSendBtn()
{
	QString l_text = ui.m_sendText->toPlainText();
	m_pipeChild.onPipeWrite(l_text.toLatin1().data());
}

void TestPipeChild::onReceiveBtn()
{
	ui.m_receiveText->setText(QString::fromStdString(m_pipeChild.onPipeRead()));
}

void TestPipeChild::onShowReadData( std::string data )
{

}
