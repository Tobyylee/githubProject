#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QDragMoveEvent>
#include "ui_lyDialog.h"
#include "testTableModel.h"

class lyDialog : public QWidget
{
	Q_OBJECT

public:
	lyDialog(QWidget *parent = Q_NULLPTR);
	~lyDialog();

	void initWidget();

	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void resizeEvent(QResizeEvent *event);

	void paintCloseBtn(QPainter* painter);
private:
	Ui::lyDialog ui;
	QPoint m_currentPos;
	testTableModel* m_testTableModel;
};
