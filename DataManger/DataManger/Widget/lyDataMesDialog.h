#pragma once

#include <QDialog>
#include "ui_lyDataMesDialog.h"
#include "DateTableMes.h"
#include "lyCityWidget.h"

class lyDataMesDialog : public QDialog
{
	Q_OBJECT

public:
	lyDataMesDialog(QWidget *parent = Q_NULLPTR);
	~lyDataMesDialog();

	void initDate();
	void initSlot();
	void setDataMes(const DateTableMes&  dateMes) { m_dateTableMes = dateMes; }
	DateTableMes getDateMes() { return m_dateTableMes; }
	bool isConfirm() { return m_isConfirm; }

public slots:
	void onDateTypeSelect(int index);
	void onDateSiteClicked();
	void onBeginDateFinishEdit();
	void onEndTDateFinishEdit();
	void onConfirm();
	void onCancle();
	void onFinishDataSiteSelect(const QString& cityName);
	void onMeetSiteSelect(int index);

protected:
	bool judgeFormat(const DateTableMes& data);

private:
	Ui::lyDataMesDialog ui;
	DateTableMes m_dateTableMes;
	bool m_isConfirm;
	lyCityWidget* m_cityWidget;
};
