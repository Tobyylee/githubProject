#include "pixmapDraw.h"
#include <QPainter>
#include <QPixmap>
#include <QNetworkInterface>
#include <QDebug>
#include "readPNG.h"

QString getHostMacAddress()
{
	QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表  
	int nCnt = nets.count();
	QString strMacAddr = "";
	for (int i = 0; i < nCnt; i++)
	{
		// 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址  
		if (nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
		{
			strMacAddr = nets[i].hardwareAddress();
			break;
		}
	}
	return strMacAddr;
}

pixmapDraw::pixmapDraw(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_readPNG = new readPNG;
	m_readPNG->readFile(QString("3D.png"));
	qDebug() << getHostMacAddress();

}

pixmapDraw::~pixmapDraw()
{
}

void pixmapDraw::paintEvent(QPaintEvent *event)
{
	QPainter l_painter(this);
	QImage l_image0("drag.png");
	QImage l_image(l_image0.bits(), 22, 22, QImage::Format_ARGB32);// = QImage::fromData(m_readPNG->m_byteArray);
	QImage l_image3(100, 100, QImage::Format_ARGB32);
	for (int i = 0; i < 50; i++)
	{
		l_image0.setPixelColor(QPoint(i, i), QColor(255, 0, 0));
	}
//	l_image0 = l_image0.scaled(QSize(10, 10));
	//	QPixmap::from(m_readPNG->m_byteArray);
	l_image3 = l_image0.copy(QRect(3, 3, 15, 15));
	l_painter.drawPixmap(QPoint(10,10), QPixmap::fromImage(l_image0));
	l_painter.drawPixmap(QPoint(210, 210), QPixmap::fromImage(l_image3));
}
