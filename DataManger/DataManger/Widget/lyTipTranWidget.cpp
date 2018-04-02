#include "lyTipTranWidget.h"

lyTipTranWidget::lyTipTranWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

lyTipTranWidget::~lyTipTranWidget()
{
}

void lyTipTranWidget::setContent(const QString& content)
{
	ui.label->setText(content);
}
