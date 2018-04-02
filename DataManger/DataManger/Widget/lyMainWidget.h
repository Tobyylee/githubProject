#pragma once

#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QThread>
#include <QTimer>

#include "ui_lyMainWidget.h"
#include "lyExcelTableModel.h"
#include "lyExcelItemDelegate.h"
#include "lyExcelItemProxyModel.h"
#include "lyDataMesDialog.h"

class lyFileIOThreadObject;

enum ly_MenuAction
{
	ly_Edit_row = 0,
	ly_insert_row,
	ly_delete_row,
	ly_refresh_list,
	ly_sort_Des,
	ly_sort_Asc,
	ly_menuAction_Count,
};

enum ly_FindComboBoxItem
{
	ly_find_WriteTime = 0,
	ly_find_MesType,
	ly_find_DataSite,
	ly_find_BeginTime,
	ly_find_EndTime,
	ly_FindComboBoxItem_count,
};

class lyMainWidget : public QWidget
{
	Q_OBJECT

public:
	lyMainWidget(QWidget *parent = Q_NULLPTR);
	~lyMainWidget();

	void initWidget();
	void initData();
	void initSlot();

	void setExcelTableData(const QString& fileName);
	void writeExcelTableData(const QString&fileName);
	void resizeEvent(QResizeEvent *event);

public slots:
	void onActivated(const QModelIndex &index);
	void onContextMenu(QPoint point);
	void onAction();
	void onAddExcelTitle(const QStringList& list);
	void onComboBox(int index);
	void onFindComboBox(int index);
	void onDeletePage();
	void onBuildPage();
	void onOperatorFinished();
	void onCheckTImer();
	void onQueryData();
	void onRename();

signals:
	void readExcelFile(const QString&);
	void writeExcelFile(const QString&);

private:
	Ui::lyMainWidget ui;
	lyExcelTableModel* m_excelTableModel;
	lyExcelItemDelegate* m_excelItemDelegate;
	lyExcelItemProxyModel* m_excelItemProxyModel;
	QMenu* m_menu;
	QAction* m_actions[ly_menuAction_Count];
	QPoint m_rightPressed;
	lyFileIOThreadObject* m_fileIOThreadObject;
	QThread m_fileIOThread;
	QTimer m_checkTime;

	int m_findComboBoxIndex;
};
