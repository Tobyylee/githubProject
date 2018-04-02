#pragma once
#include "lyWidgetManager.h"

DataManager* lyWidgetManager::m_sDataManager = nullptr;
lyTipTranWidget* lyWidgetManager::m_sTipTranWidget = nullptr;

lyWidgetManager::lyWidgetManager()
{

}

lyWidgetManager::~lyWidgetManager()
{

}

void lyWidgetManager::CreatAllWidget()
{
	if (!m_sDataManager)
	{
		m_sDataManager = new DataManager();
		m_sDataManager->showMaximized();
	}
	if (!m_sTipTranWidget)
	{
		m_sTipTranWidget = new lyTipTranWidget();
		m_sTipTranWidget->hide();
	}
}

void lyWidgetManager::DelelteAllWidget()
{
	if (m_sDataManager)
	{
		delete m_sDataManager;
		m_sDataManager = nullptr;
	}
}


