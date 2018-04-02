#pragma once

#include <QItemDelegate>

class lyExcelItemDelegate : public QItemDelegate
{
	Q_OBJECT

public:
	lyExcelItemDelegate(QObject *parent);
	~lyExcelItemDelegate();

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const QModelIndex &index) const;

	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
		const QModelIndex &index) const;
	//调整初始化Item的位置
	void updateEditorGeometry(QWidget *editor,
		const QStyleOptionViewItem &option, const QModelIndex &index) const;

//	bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
};
