#include "lyEditMesType.h"
#include "lyConfigManager.h"
#include "lyParConfig.h"

lyEditMesType::lyEditMesType(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initSlot();
	initData();
}

lyEditMesType::~lyEditMesType()
{
}

void lyEditMesType::initData()
{
	for (int i = 0; i < lyConfigManager::m_sParConfig->m_MesTypes_Assign.size(); i++)
	{
		ui.mesTypeComboBox->addItem(lyConfigManager::m_sParConfig->m_MesTypes_Assign.at(i));
	}
	ui.modifyEdit->setText(ui.mesTypeComboBox->currentText());
}

void lyEditMesType::initSlot()
{
	connect(ui.mesTypeComboBox, SIGNAL(activated(int)), this, SLOT(onSelectCurrentMesType(int)));
	connect(ui.addBtn, SIGNAL(clicked()), this, SLOT(onAddMesType()));
	connect(ui.editBtn, SIGNAL(clicked()), this, SLOT(onEditMesType()));
	connect(ui.delBtn, SIGNAL(clicked()), this, SLOT(onDelMesType()));
}

void lyEditMesType::onSelectCurrentMesType(int index)
{
	ui.modifyEdit->setText(ui.mesTypeComboBox->currentText());
}

void lyEditMesType::onAddMesType()
{
	QStringList& l_list = lyConfigManager::m_sParConfig->m_MesTypes_Assign;
	QString l_str = ui.modifyEdit->text();
		bool l_flag = false;
	for (int i = 0; i<l_list.size(); i++)
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

void lyEditMesType::onDelMesType()
{
	QStringList& l_list = lyConfigManager::m_sParConfig->m_MesTypes_Assign;
	QString l_str = ui.modifyEdit->text();
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

void lyEditMesType::onEditMesType()
{
	QStringList& l_list = lyConfigManager::m_sParConfig->m_MesTypes_Assign;
	QString l_str = ui.mesTypeComboBox->currentText();
	for (int i = 0; i < l_list.size(); i++)
	{
		if (l_list.at(i) == l_str)
		{
			l_list.replace(i, ui.modifyEdit->text());
			break;
		}
	}
	hide();
}

