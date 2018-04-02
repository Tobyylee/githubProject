#pragma once

#include <QWidget>
#include "ui_lyCityWidget.h"

class lyCityWidget : public QWidget
{
	Q_OBJECT

public:
	lyCityWidget(QWidget *parent = Q_NULLPTR);
	~lyCityWidget();

	void initData();
	void initSlot();
	const QString getCurrentCity() { return m_currentCity;  }

public slots:
	void onSelectCity(const QString& city);

signals:
	void finishSelect(const QString&);

private:
	Ui::lyCityWidget ui;
	QString m_currentCity;
	int m_count;
};
