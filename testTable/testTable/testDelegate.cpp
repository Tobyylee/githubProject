#include "testDelegate.h"
#include <QCheckBox>
#include <QSpinBox>
#include <QApplication>
#include <QPainter>
#include <QMouseEvent>


static QRect CheckBoxRect(const QStyleOptionViewItem &view_item_style_options)
{
	QStyleOptionButton check_box_style_option;
	QRect check_box_rect = QApplication::style()->subElementRect(
		QStyle::SE_CheckBoxClickRect,
		&check_box_style_option);

	QPoint check_box_point(view_item_style_options.rect.x() /*	+
			view_item_style_options.rect.width() / 2 -
				check_box_rect.width() / 2*/,
		view_item_style_options.rect.y() /*+
		view_item_style_options.rect.height() / 2 -
		check_box_rect.height() / 2*/);
	return QRect(check_box_point, view_item_style_options.rect.size());
}

testDelegate::testDelegate(QObject *parent /*= 0*/) : QStyledItemDelegate(parent)
{
	m_icon = new QIcon("drag.png");
}

testDelegate::~testDelegate()
{

}

QWidget * testDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	if (index.column() == 2)
	{
		QSpinBox *editor = new QSpinBox(parent);
		editor->setMinimum(0);
		editor->setMaximum(100);
		/*	QCheckBox* editor = new QCheckBox(parent);
			editor->show();*/
		return editor;
	}
	return nullptr;
}

void testDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
	int value = index.model()->data(index, Qt::DisplayRole).toInt();

	QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
	spinBox->setValue(value);
}

void testDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
	QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
	spinBox->interpretText();
	int value = spinBox->value();

	model->setData(index, value);
}

void testDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	editor->setGeometry(option.rect);
}

void testDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	//如果是第2列'病人Id'  
	if (index.column() == 5)
	{
		//const QAbstractItemModel *itemModel = index.model();
		////获得索引对应Model中的数据  
		//int finishedSubTaskNum = itemModel->data(index, Qt::DisplayRole).toInt();
		//int subTaskNum = itemModel->data(itemModel->index(index.row(), 5), Qt::DisplayRole).toInt();
		////进度条的风格选项  
		//QStyleOptionProgressBarV2 *progressBarOption = new QStyleOptionProgressBarV2();
		//progressBarOption->rect = option.rect;
		//progressBarOption->minimum = 0;
		//progressBarOption->maximum = subTaskNum;
		//progressBarOption->progress = finishedSubTaskNum;
		////int t = finishedSubTaskNum / subTaskNum;
		//int t = 80;
		//progressBarOption->text = QString::number(t) + "%";
		//progressBarOption->textVisible = true;
		////绘制进度条  
		//QApplication::style()->drawControl(QStyle::CE_ProgressBar, progressBarOption, painter);
		bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
		//按钮的风格选项  
		QStyleOptionButton *checkBoxOption = new QStyleOptionButton();
		checkBoxOption->state |= QStyle::State_Enabled;
		checkBoxOption->icon = *m_icon;
		checkBoxOption->iconSize = QSize(22, 22);
		checkBoxOption->text = "flag";
	//	checkBoxOption->features = QStyleOptionButton::AutoDefaultButton;
		//根据值判断是否选中  
		if (checked)
		{
			checkBoxOption->state |= QStyle::State_On;
		}
		else
		{
			checkBoxOption->state |= QStyle::State_Off;
		}
		//返回QCheckBox几何形状  
		checkBoxOption->rect = CheckBoxRect(option);
		
		//绘制QCheckBox  
		QApplication::style()->drawControl(QStyle::CE_CheckBox, checkBoxOption, painter);

	}
	else
	{
		//否则调用默认委托  
		QStyledItemDelegate::paint(painter, option, index);
	}
}

//bool testDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
//{
//	/*if ((event->type() == QEvent::MouseButtonRelease) ||
//		(event->type() == QEvent::MouseButtonDblClick))
//	{
//		QMouseEvent *mouse_event = static_cast<QMouseEvent*>(event);
//		if (mouse_event->button() != Qt::LeftButton ||
//			!CheckBoxRect(option).contains(mouse_event->pos()))
//		{
//			return false;
//		}
//
//		if (event->type() == QEvent::MouseButtonDblClick)
//		{
//			return true;
//		}
//	}
//	else if (event->type() == QEvent::KeyPress)
//	{
//		if (static_cast<QKeyEvent*>(event)->key() != Qt::Key_Space &&
//			static_cast<QKeyEvent*>(event)->key() != Qt::Key_Select)
//		{
//			return false;
//		}
//	}
//	else
//	{
//		return false;
//	}
//
//	bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
//	return model->setData(index, !checked, Qt::EditRole);*/
//}
