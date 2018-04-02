#ifndef  TESTDELEGATE_H_
#define   TESTDELEGATE_H_

#include <QStyledItemDelegate>
#include <QPen>

class testDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	testDelegate(QObject *parent = 0);
	virtual ~testDelegate();

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const QModelIndex &index) const;

	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
		const QModelIndex &index) const;

	void updateEditorGeometry(QWidget *editor,
		const QStyleOptionViewItem &option, const QModelIndex &index) const;

	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

//	bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

private:
	QPen  pen;
	QIcon* m_icon;
};

#pragma once
#endif //  TESTDELEGATE_H_
