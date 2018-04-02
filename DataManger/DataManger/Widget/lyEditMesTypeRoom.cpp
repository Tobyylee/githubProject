#include "lyEditMesTypeRoom.h"
#include "lyParConfig.h"
#include "lyConfigManager.h"

lyEditMesTypeRoom::lyEditMesTypeRoom(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initSlot();
	initData();
}

lyEditMesTypeRoom::~lyEditMesTypeRoom()
{
}

void lyEditMesTypeRoom::initData()
{
	for (int i = 0; i < lyConfigManager::m_sParConfig->m_MesTypes_Meet.size(); i++)
	{
		ui.meetSiteComboBox->addItem(lyConfigManager::m_sParConfig->m_MesTypes_Meet.at(i));
	}
	ui.modifyMeetSiteEdit->setText(ui.meetSiteComboBox->currentText());
}

void lyEditMesTypeRoom::initSlot()
{
	connect(ui.meetSiteComboBox, SIGNAL(activated(int)), this, SLOT(onSelectCurrentMesType(int)));
	connect(ui.addBtn, SIGNAL(clicked()), this, SLOT(onAddMeetSite()));
	connect(ui.editBtn, SIGNAL(clicked()), this, SLOT(onEditMeetSite()));
	connect(ui.delBtn, SIGNAL(clicked()), this, SLOT(onDelMeetSite()));
}

void lyEditMesTypeRoom::onSelectCurrentMeetSite(int index)
{
	ui.modifyMeetSiteEdit->setText(ui.meetSiteComboBox->currentText());
}

void lyEditMesTypeRoom::onAddMeetSite()
{
	QStringList& l_list = lyConfigManager::m_sParConfig->m_MesTypes_Meet;
	QString l_str = ui.modifyMeetSiteEdit->text();
	bool l_flag = false;
	for (int i = 0; i < l_list.size(); i++)
	{
		if (l_list.at(i) == l_str)
		{
			l_flag = true;
		}
	}
	if (!l_flag)
	{
		l_list.append(l_str);
	}
	hide();
}

void lyEditMesTypeRoom::onDelMeetSite()
{
	QStringList& l_list = lyConfigManager::m_sParConfig->m_MesTypes_Meet;
	QString l_str = ui.modifyMeetSiteEdit->text();
	for (int i = 0; i < l_list.size(); i++)
	{
		if (l_list.at(i) == l_str)
		{
			l_list.removeAt(i);
			break;
		}
	}
	hide();
}

void lyEditMesTypeRoom::onEditMeetSite()
{
	QStringList& l_list = lyConfigManager::m_sParConfig->m_MesTypes_Meet;
	QString l_str = ui.meetSiteComboBox->currentText();
	for (int i = 0; i < l_list.size(); i++)
	{
		if (l_list.at(i) == l_str)
		{
			l_list.replace(i, ui.modifyMeetSiteEdit->text());
			break;
		}
	}
	hide();
}
