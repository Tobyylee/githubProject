#include "DataInputTipWidget.h"

DataInputTipWidget::DataInputTipWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

DataInputTipWidget::~DataInputTipWidget()
{
}

void DataInputTipWidget::setTipText(const QString& text)
{
	ui.label->setText(text);
}
