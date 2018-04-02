#include "lyDialog.h"

#include <QPainter>
#include <QDebug>
#include <QPolygon>
#include <QPalette>

const int g_concer = 15;

lyDialog::lyDialog(QWidget *parent)
	: QWidget(parent)
{
	setFixedSize(1000, 600);
	ui.setupUi(this);
	setWindowOpacity(1);//设置窗体不透明  
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);//设置窗体无边框,允许任务栏按钮右键菜单  
	setAttribute(Qt::WA_TranslucentBackground);//设置背景透明 

	initWidget();
	ui.confirmBtn->setAutoFillBackground(true);
	QPalette l_palette = ui.confirmBtn->palette();
	l_palette.setBrush(ui.confirmBtn->backgroundRole(), QBrush(QColor(51, 51, 51)));
	l_palette.setColor(QPalette::ButtonText, Qt::red);
	l_palette.setColor(QPalette::Window, QColor(51, 51, 51));
	ui.confirmBtn->setPalette(l_palette);
}

lyDialog::~lyDialog()
{
}

void lyDialog::initWidget()
{
	m_testTableModel = new testTableModel(this);
	ui.tableView->setModel(m_testTableModel);
	ui.tableView->verticalHeader()->setVisible(false);
//	ui.tableView->setAlternatingRowColors(true);
	ui.tableView->setMouseTracking(false);
	ui.tableView->setFocusPolicy(Qt::NoFocus);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView->setContextMenuPolicy(Qt::CustomContextMenu);
	ui.tableView->setSortingEnabled(true);
}

void lyDialog::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.save();
	painter.setPen(QColor(43, 97, 133));
	painter.setBrush(QColor(43, 97, 133));
	int l_width = width();
	int l_height = height();
	QPoint l_point[21] =
	{
		QPoint(0,0), QPoint(l_width / 4, 0), QPoint(l_width / 4 + g_concer, g_concer), QPoint(l_width - 10, g_concer),
		QPoint(l_width, g_concer+10), QPoint(l_width, 40), QPoint(l_width - 10, 50), QPoint(l_width - 10, l_height / 4),
		QPoint(l_width - g_concer-10, l_height / 4 + g_concer), QPoint(l_width - g_concer-10, 3 * l_height / 4), QPoint(l_width - 10, 3 * l_height / 4 + g_concer),
		QPoint(l_width - 5, l_height), QPoint(3 * l_width / 4, l_height), QPoint(3 * l_width / 4 - g_concer, l_height - g_concer), QPoint(l_width / 4 + g_concer, l_height - g_concer),
		QPoint(l_width / 4, l_height), QPoint(0, l_height), QPoint(0, 3 * l_height / 4), QPoint(g_concer, 3 * l_height / 4 - g_concer), QPoint(g_concer, l_height / 4 + g_concer),
		QPoint(0, l_height / 4)
	};
	QPolygon l_polygon;
	for (int i = 0; i < 21; i++)
	{
		l_polygon.append(l_point[i]);
	}
	painter.drawPolygon(l_polygon);

	painter.drawLine(QPoint(g_concer, g_concer * 2), QPoint(l_width - g_concer, g_concer * 2));
	paintCloseBtn(&painter);

	painter.restore();
}

void lyDialog::mousePressEvent(QMouseEvent *event)
{
	//qDebug() << "press" << event->pos();
	m_currentPos = event->pos();
	QPoint l_begin(width() - g_concer - 10, 25);
	QPolygon l_polygon;
	QPoint l_point[6] =
	{
		QPoint(0, 0), QPoint(15, 0), QPoint(17, 2), QPoint(17, 17), QPoint(2, 17), QPoint(0, 15)
	};
	for (int i = 0; i < 6; i++)
	{
		l_polygon.append(l_point[i] + l_begin);
	}
	if (l_polygon.containsPoint(event->pos(), Qt::OddEvenFill))
	{
		hide();
	}
}

void lyDialog::mouseMoveEvent(QMouseEvent *event)
{
	QPoint l_point = mapToGlobal(QPoint(0, 0));
	l_point = event->pos() -  m_currentPos + l_point;
	move(l_point);
	//m_beforeMove = event->pos();
	qDebug() << "mouseMoveEvent" "pos()"<< pos() << l_point << "move" << event->pos() - m_currentPos;
}

void lyDialog::resizeEvent(QResizeEvent *event)
{
	qDebug() << ui.tableView->width();
	for (int i = 0; i < 6; i++)
	{
		ui.tableView->setColumnWidth(i, ui.tableView->width() / 6);
	}
}

void lyDialog::paintCloseBtn(QPainter* painter)
{
	painter->save();
	painter->setPen(Qt::red);
	painter->setBrush(Qt::red);
	painter->translate(QPoint(width() - g_concer - 10, 25));
	QPolygon l_polygon;
	QPoint l_point[6] =
	{
		QPoint(0, 0), QPoint(15, 0), QPoint(17, 2), QPoint(17, 17), QPoint(2, 17), QPoint(0, 15)
	};
	for (int i = 0; i < 6; i++)
	{
		l_polygon.append(l_point[i]);
	}
	painter->drawPolygon(l_polygon);

	painter->setPen(Qt::white);
	painter->setBrush(Qt::white);
	painter->drawLine(QPoint(2, 2), QPoint(13, 13));
	painter->drawLine(QPoint(2, 13), QPoint(13, 2));
	painter->restore();
}
