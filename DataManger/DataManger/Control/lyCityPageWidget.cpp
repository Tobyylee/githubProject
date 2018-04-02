#include "lyCityPageWidget.h"
#include <QGridLayout>
#include <QDebug>

const int g_pushButtonHeight = 40;
const int g_pushButtonWidth = 150;

lyCityPageWidget::lyCityPageWidget(QWidget *parent)
	: QFrame(parent)
{
	initWidget();
}

lyCityPageWidget::~lyCityPageWidget()
{
}

void lyCityPageWidget::initWidget()
{
	QGridLayout* l_mainLayout = new QGridLayout;
	for (int i = 0; i < g_sCityMaxCont; i++)
	{
		m_pushButton[i] = new QPushButton("", this);
		m_pushButton[i]->setFixedSize(g_pushButtonWidth, g_pushButtonHeight);
		l_mainLayout->addWidget(m_pushButton[i], i / 5, i % 5);
		connect(m_pushButton[i], SIGNAL(clicked()), this, SLOT(onClicked()));
	}
	l_mainLayout->setSpacing(5);
	setLayout(l_mainLayout);
	
}

void lyCityPageWidget::initSlot()
{

}

void lyCityPageWidget::setData(const QVector<QString>& data)
{
	for (int i = 0; i < g_sCityMaxCont; i++)
	{
		if (i < data.size())
		{
			m_pushButton[i]->setText(data.at(i));
			qDebug() << "i" << data.at(i);
			m_pushButton[i]->show();
		}
		else
		{
			m_pushButton[i]->setText("");
			//m_pushButton[i]->hide();
		}
	}
}

void lyCityPageWidget::onClicked()
{
	QPushButton* l_pushButton = qobject_cast<QPushButton*>(sender());
	m_cityName = l_pushButton->text();
	emit currentCity(m_cityName);
}
