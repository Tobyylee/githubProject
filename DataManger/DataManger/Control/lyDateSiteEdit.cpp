#include "lyDateSiteEdit.h"

lyDateSiteEdit::lyDateSiteEdit(QWidget *parent)
	: QLineEdit(parent)
{
}

lyDateSiteEdit::~lyDateSiteEdit()
{
}

void lyDateSiteEdit::mousePressEvent(QMouseEvent * event)
{
	emit lyClicked();
}

