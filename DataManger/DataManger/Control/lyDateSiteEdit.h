#pragma once

#include <QLineEdit>

class lyDateSiteEdit : public QLineEdit
{
	Q_OBJECT

public:
	lyDateSiteEdit(QWidget *parent);
	~lyDateSiteEdit();

	void mousePressEvent(QMouseEvent * event);

signals:
	void lyClicked();
};
