#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_testTable.h"
#include "testTableModel.h"
#include "testSortTableModel.h"
#include "testDelegate.h"
#include "lyDialog.h"
#include "gtrHasbeenreadModel.h"

class pixmapDraw;

class personData
{
public:
	personData(const QString& name = "", int age = 0, int height = 0, int weight = 0, const QString& sex = "", bool flag = true) :
		m_name(name), m_age(age), m_height(height), m_weight(weight), m_sex(sex), m_flag(flag)
	{
	}

	QString m_name;
	int m_age;
	int m_height;
	int m_weight;
	QString m_sex;
	bool m_flag;
};

enum citCCTVColumn {
	P_NAME = 0,
	P_AGE,
	P_HEIGHT,
	P_WEIGHT,
	P_SEX,
	P_FLAG,
	P_COUNT,
};
class testTable : public QMainWindow
{
	Q_OBJECT

public:
	testTable(QWidget *parent = Q_NULLPTR);
	virtual ~testTable();

	static QVector<personData>* m_personData;

	void initTable();
	void initSlot();

public slots:
	void onClicked();

private:
	Ui::testTableClass ui;
	testTableModel* m_testTableModel;
	testSortTableModel* m_testSortTableModel;
	testDelegate* m_testDelegate;
	lyDialog* m_dialog;
	gtrHasbeenreadModel* m_HasbeenreadModel;
	gtrHasbeenreadModel* m_HasbeenreadModel_2;

	pixmapDraw* m_pixmapDraw;
};
