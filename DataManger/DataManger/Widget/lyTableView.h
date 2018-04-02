#pragma once

#include <QTableView>

class lyTableView : public QTableView
{
	Q_OBJECT

public:
	lyTableView(QWidget *parent);
	~lyTableView();

	void mousePressEvent(QMouseEvent *event);

};
