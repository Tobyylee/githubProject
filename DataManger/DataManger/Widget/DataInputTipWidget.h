#pragma once

#include <QDialog>
#include "ui_DataInputTipWidget.h"

class DataInputTipWidget : public QDialog
{
	Q_OBJECT

public:
	DataInputTipWidget(QWidget *parent = Q_NULLPTR);
	~DataInputTipWidget();

	void setTipText(const QString& text);
private:
	Ui::DataInputTipWidget ui;
};
