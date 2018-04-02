#include "lyDataMesDialog.h"
#include <QDateTime>
#include <QDebug>
#include "lyParConfig.h"
#include "lyConfigManager.h"
#include "lyExcelDataManager.h"
#include "lyCommon.h"
#include "DataInputTipWidget.h"

const  char* g_sDatePlan_Dialog[]
{
	QT_TRANSLATE_NOOP("lyDataMesDialog", "NoSelected"),
	QT_TRANSLATE_NOOP("lyDataMesDialog", "NoHappen"),
	QT_TRANSLATE_NOOP("lyDataMesDialog", "Going"),
	QT_TRANSLATE_NOOP("lyDataMesDialog", "Finished"),
};

lyDataMesDialog::lyDataMesDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	m_dateTableMes = DateTableMes();
	m_cityWidget = new lyCityWidget();
	m_cityWidget->hide();
	ui.dateSiteComboBox->hide();
	initSlot();
//	initDate();
}

lyDataMesDialog::~lyDataMesDialog()
{
	if (m_cityWidget)
	{
		delete m_cityWidget;
		m_cityWidget = nullptr;
	}
}

void lyDataMesDialog::initDate()
{
	m_isConfirm = false;
	if (!m_dateTableMes.m_writeTime.isValid())
	{
		m_dateTableMes.m_writeTime = QDateTime::currentDateTime();
	}
	ui.writeTimeEdit->setDateTime(m_dateTableMes.m_writeTime);
	ui.mesSectionEdit->setText(m_dateTableMes.m_mesSection);

	ui.mesTypeComboBox->clear();
	for (int i = 0; i < lyConfigManager::m_sParConfig->m_MesTypes_Assign.size(); i++)
	{
		ui.mesTypeComboBox->addItem(lyConfigManager::m_sParConfig->m_MesTypes_Assign.at(i));
	}
	ui.mesTypeComboBox->setCurrentText(m_dateTableMes.m_mesType);
	ui.mesContentEdit->setText(m_dateTableMes.m_mesContent);
	ui.dateSiteEdit->setText(m_dateTableMes.m_dateSite);
	if (!m_dateTableMes.m_beginTime.isValid())
	{
		m_dateTableMes.m_beginTime = QDateTime::currentDateTime();
	}
	ui.beginTimeEdit->setDateTime(m_dateTableMes.m_beginTime);
	if (!m_dateTableMes.m_endTime.isValid())
	{
		m_dateTableMes.m_endTime = QDateTime::currentDateTime();
	}
	ui.endTimeEdit->setDateTime(m_dateTableMes.m_endTime);
	qDebug() << "m_dateTableMes.m_datePlan" << m_dateTableMes.m_datePlan;
	ui.datePlanComboBox->setCurrentText(m_dateTableMes.m_datePlan);

	for (int i = 0; i < ly_DatePlan_Count; i++)
	{
		ui.datePlanComboBox->addItem(tr(g_sDatePlan_Dialog[i]));
	}

	ui.remarkEdit->setText(m_dateTableMes.m_remark);
}

void lyDataMesDialog::initSlot()
{
	connect(ui.dateSiteComboBox, SIGNAL(activated(int)), this, SLOT(onMeetSiteSelect(int)));
	connect(ui.mesTypeComboBox, SIGNAL(activated(int)), this, SLOT(onDateTypeSelect(int)));
	connect(ui.dateSiteEdit, SIGNAL(lyClicked()), this, SLOT(onDateSiteClicked()));
	connect(ui.beginTimeEdit, SIGNAL(editingFinished()), this, SLOT(onBeginDateFinishEdit()));
	connect(ui.beginTimeEdit, SIGNAL(editingFinished()), this, SLOT(onEndTDateFinishEdit()));
	connect(ui.confirmBtn, SIGNAL(clicked()), this, SLOT(onConfirm()));
	connect(ui.cancleBtn, SIGNAL(clicked()), this, SLOT(onCancle()));
	connect(m_cityWidget, SIGNAL(finishSelect(const QString&)), this, SLOT(onFinishDataSiteSelect(const QString&)));
}

void lyDataMesDialog::onConfirm()
{
	DateTableMes l_date;
	l_date.m_writeTime = ui.writeTimeEdit->dateTime();
	l_date.m_mesSection = ui.mesSectionEdit->text();
	l_date.m_mesType = ui.mesTypeComboBox->currentText();
	l_date.m_mesContent = ui.mesContentEdit->text();
	l_date.m_dateSite = ui.dateSiteEdit->text();
	l_date.m_beginTime = ui.beginTimeEdit->dateTime();
	l_date.m_endTime = ui.endTimeEdit->dateTime();
	if (l_date.m_beginTime > l_date.m_endTime)
	{
		l_date.m_endTime = l_date.m_beginTime;
	}
	l_date.m_datePlan = ui.datePlanComboBox->currentText();
	l_date.m_remark = ui.remarkEdit->text();
	if (!judgeFormat(l_date))
	{
		return;
	}
	m_dateTableMes = l_date;
	m_isConfirm = true;
	hide();
}

void lyDataMesDialog::onCancle()
{
	m_isConfirm = false;
	hide();
}

void lyDataMesDialog::onFinishDataSiteSelect(const QString& cityName)
{
	ui.dateSiteEdit->setText(m_cityWidget->getCurrentCity());
}

void lyDataMesDialog::onMeetSiteSelect(int index)
{
	ui.dateSiteEdit->show();
	ui.dateSiteEdit->setText(ui.dateSiteComboBox->currentText());
	ui.dateSiteComboBox->hide();
}

bool lyDataMesDialog::judgeFormat(const DateTableMes& data)
{
	bool l_flag = false;
	DataInputTipWidget l_dataWidget;
	if (data.m_mesSection == "")
	{
		l_dataWidget.setTipText(QStringLiteral("请填写信息归属部门"));
	}
	else 	if (data.m_mesType == "")
	{
		l_dataWidget.setTipText(QStringLiteral("请填写信息分类"));
	}
	else 	if (data.m_mesContent == "")
	{
		l_dataWidget.setTipText(QStringLiteral("请填写信息内容"));
	}
	else 	if (data.m_mesType == "")
	{
		l_dataWidget.setTipText(QStringLiteral("请填写信息分类"));
	}
	else 	if (data.m_dateSite == "")
	{
		l_dataWidget.setTipText(QStringLiteral("请填写信息地点"));
	}
	else 	if (data.m_beginTime == data.m_endTime)
	{
		l_dataWidget.setTipText(QStringLiteral("请检查日程开始时间和日程结束时间是否冲突"));
	}
	else 	if (data.m_datePlan == QStringLiteral("未选择"))
	{
		l_dataWidget.setTipText(QStringLiteral("请填写日程进度"));
	}
	else 	if (data.m_remark == "")
	{
		l_dataWidget.setTipText(QStringLiteral("请填写日程备注"));
	}
	else
	{
		l_flag = true;
	}
	if(!l_flag)
	{
		l_dataWidget.exec();
	}
	return l_flag;
}

void lyDataMesDialog::onDateTypeSelect(int index)
{
	ui.dateSiteEdit->show();
	ui.dateSiteComboBox->hide();
}

void lyDataMesDialog::onDateSiteClicked()
{
	if (ui.mesTypeComboBox->currentText() == QStringLiteral("出差"))
	{
		m_cityWidget->initData();
		m_cityWidget->show();
	}
	else if (ui.mesTypeComboBox->currentText() == QStringLiteral("会议"))
	{
		ui.dateSiteEdit->hide();
		ui.dateSiteComboBox->clear();
		for (int i = 0; i < lyConfigManager::m_sParConfig->m_MesTypes_Meet.size(); i++)
		{
			ui.dateSiteComboBox->addItem(lyConfigManager::m_sParConfig->m_MesTypes_Meet.at(i));
		}
		ui.dateSiteEdit->setText(ui.dateSiteComboBox->currentText());
		ui.dateSiteComboBox->show();
	}
}

void lyDataMesDialog::onBeginDateFinishEdit()
{
	ui.endTimeEdit->setDateTime(ui.beginTimeEdit->dateTime());
}

void lyDataMesDialog::onEndTDateFinishEdit()
{
	if (ui.endTimeEdit->dateTime() < ui.beginTimeEdit->dateTime())
	{
		ui.endTimeEdit->setDateTime(ui.beginTimeEdit->dateTime());
	}
}
