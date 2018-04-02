#pragma once

#include <QDialog>
#include "ui_lyEditMesTypeRoom.h"

class lyEditMesTypeRoom : public QDialog
{
	Q_OBJECT

public:
	lyEditMesTypeRoom(QWidget *parent = Q_NULLPTR);
	~lyEditMesTypeRoom();

	void initData();
	void initSlot();

	public slots:
	void onSelectCurrentMeetSite(int index);
	void onAddMeetSite();
	void onDelMeetSite();
	void onEditMeetSite();

private:
	Ui::lyEditMesTypeRoom ui;
};
