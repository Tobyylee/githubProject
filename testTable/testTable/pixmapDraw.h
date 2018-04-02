#pragma once

#include <QWidget>
#include "ui_pixmapDraw.h"

class readPNG;

class pixmapDraw : public QWidget
{
	Q_OBJECT

public:
	pixmapDraw(QWidget *parent = Q_NULLPTR);
	~pixmapDraw();

	void paintEvent(QPaintEvent *event);
private:
	Ui::pixmapDraw ui;
	readPNG* m_readPNG;
};
