#include "DateManagerApp.h"
#include "lyDateManager.h"
#include "lyWidgetManager.h"

DateManagerApp::DateManagerApp(int argc, char* argv[]) : QApplication(argc, argv)
{
	lyDateManager::CreatAllDate();
	lyWidgetManager::CreatAllWidget();
}

DateManagerApp::~DateManagerApp()
{
	lyDateManager::DeleteAllDate();
	lyWidgetManager::DelelteAllWidget();
}
