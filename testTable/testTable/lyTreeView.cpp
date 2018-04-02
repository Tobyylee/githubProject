#include "lyTreeView.h"
#include <QDebug>
#include <QDropEvent>

lyTreeView::lyTreeView(QWidget *parent)
	: QTreeView(parent)
{
	setDragEnabled(true);
	setDragDropMode(QAbstractItemView::DragDrop);
}

lyTreeView::~lyTreeView()
{
}

void lyTreeView::dragEnterEvent(QDragEnterEvent *event)
{
	qDebug() << "dragEnterEvent";
	QTreeView::dragEnterEvent(event);
}

void lyTreeView::dragMoveEvent(QDragMoveEvent *event)
{
	qDebug() << "dragMoveEvent";
	QTreeView::dragMoveEvent(event);
}

void lyTreeView::dropEvent(QDropEvent *event)
{
	qDebug() << "dropEvent";
	QTreeView::dropEvent(event);
	/*if (event->source() != this || !(event->possibleActions() & Qt::MoveAction))
	{

		return;
	}

	QModelIndex index = indexAt(event->pos());
	QModelIndex curIndex = this->currentIndex();
	if (this->rect().contains(event->pos()))
	{
		if (!index.isValid() || !visualRect(index).contains(event->pos()))
		{
			return;
		}
		if (index.isValid() && curIndex.isValid() && curIndex.parent() == index.parent())
		{
			QRect rect = visualRect(index);
			const int margin = 2;
			if (event->pos().y() - rect.top() < margin)
			{
				 QTreeView::dropEvent(event);
			}
			else if (rect.bottom() - event->pos().y() < margin)
			{
				QTreeView::dropEvent(event);
			}
		}
	}*/
}
