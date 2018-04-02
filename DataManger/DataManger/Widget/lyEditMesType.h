#pragma once

#include <QDialog>
#include "ui_lyEditMesType.h"

class lyEditMesType : public QDialog
{
	Q_OBJECT

public:
	lyEditMesType(QWidget *parent = Q_NULLPTR);
	~lyEditMesType();

	void initData();
	void initSlot();

public slots:
	void onSelectCurrentMesType(int index);
	void onAddMesType();
	void onDelMesType();
	void onEditMesType();
	

private:
	Ui::lyEditMesType ui;
};
