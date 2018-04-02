#pragma once

#include <QDialog>
#include "ui_lyTipTranWidget.h"

class lyTipTranWidget : public QDialog
{
	Q_OBJECT

public:
	lyTipTranWidget(QWidget *parent = Q_NULLPTR);
	~lyTipTranWidget();

	void setContent(const QString& content);
private:
	Ui::lyTipTranWidget ui;
};
