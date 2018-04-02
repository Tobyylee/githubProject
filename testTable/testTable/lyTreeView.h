#pragma once

#include <QTreeView>

class lyTreeView : public QTreeView
{
	Q_OBJECT

public:
	lyTreeView(QWidget *parent = nullptr);
	~lyTreeView();

protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dragMoveEvent(QDragMoveEvent *event);
	void dropEvent(QDropEvent *event);
};
