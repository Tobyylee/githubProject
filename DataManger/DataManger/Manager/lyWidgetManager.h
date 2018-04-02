#pragma once

#include "DataManager.h"
#include "lyTipTranWidget.h"

class lyWidgetManager
{
public:
	lyWidgetManager();
	virtual ~lyWidgetManager();

	static void CreatAllWidget();
	static void DelelteAllWidget();

	static DataManager* m_sDataManager;
	static lyTipTranWidget* m_sTipTranWidget;
};