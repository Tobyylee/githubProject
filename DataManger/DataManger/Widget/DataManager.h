#pragma once

#include <QtWidgets/QMainWindow>
#include <QMenu>
#include <QAction>

#include "ui_DataManager.h"
#include "lyExcelTableModel.h"
#include "lyExcelItemDelegate.h"
#include "lyExcelItemProxyModel.h"
//
//enum ly_MenuAction
//{
//	ly_insert_row = 0,
//	ly_delete_row,
//	ly_menuAction_Count,
//};

class DataManager : public QMainWindow
{
	Q_OBJECT

public:
	DataManager(QWidget *parent = Q_NULLPTR);
	virtual ~DataManager();

	void initWidget();
	void initSlot();


public slots:
	void onOpenFile();
	void onSaveFile();
	void onOutputFile();
	void onEditMesTpye();
	void onEditMeetSite();
private:
	Ui::DataMangerClass ui;

};
