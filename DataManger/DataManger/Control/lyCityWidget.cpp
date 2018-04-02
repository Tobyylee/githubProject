#include "lyCityWidget.h"
#include "lyReadSiteInfo.h"
#include "DateTableMes.h"
#include "lyExcelDataManager.h"

lyCityWidget::lyCityWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initData();
	initSlot();
}

lyCityWidget::~lyCityWidget()
{
}

void lyCityWidget::initData()
{
	QMap<QString, QVector<QString>>::iterator it = lyReadSiteInfo::getInstance()->m_datas.begin();
	QVector<QString> l_list;
	while (it != lyReadSiteInfo::getInstance()->m_datas.end())
	{
		l_list.append(it.key());
		it++;
	}
	ui.page->setData(l_list);
	m_count = 0;
}

void lyCityWidget::initSlot()
{
	connect(ui.page, SIGNAL(currentCity(const QString&)), this, SLOT(onSelectCity(const QString&)));
}

void lyCityWidget::onSelectCity(const QString& city)
{
	if (m_count == 0)
	{
		QMap<QString, QVector<QString>>& datas = lyReadSiteInfo::getInstance()->m_datas;
		QVector<QString>& l_citys = datas[city];
		ui.page->setData(l_citys);
		m_currentCity = "";
		m_currentCity = ui.page->getCityName();
		m_count++;
	}
	else
	{
		if (!ui.page->getCityName().isEmpty())
		{
			m_currentCity = m_currentCity + QString("/") + ui.page->getCityName();
		}
		m_count = 0;
		emit finishSelect(m_currentCity);
		hide();
	}
}
