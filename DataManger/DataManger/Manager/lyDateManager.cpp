#include "lyDateManager.h"
#include "lyConfigManager.h"
#include "lyLanguageManager.h"
#include "lyThemeManager.h"
#include "lyWidgetManager.h"
#include "lyExcelDataManager.h"
#include "lyDataBase.h"
#include "lyReadSiteInfo.h"
#include "lyLogManager.h"

lyDateManager::lyDateManager()
{

}

lyDateManager::~lyDateManager()
{

}

void lyDateManager::CreatAllDate()
{
	//日志管理
	qInstallMessageHandler(lyOutputMessage);
	//读取配置文件
	lyConfigManager::ReadAllConfig();

	//语言设置
	InitSysLanguage();

	//初始化界面主题
	InitSysTheme();

	//初始化数据库连接
	lyDataBase::getInstance()->initDataBase(lyConfigManager::m_sSysConfig->m_dataBasePath);
	//读取城市配置
	lyReadSiteInfo::getInstance()->readData(lyConfigManager::m_sSysConfig->m_cityConfigPath);
	//初始化表格数据
	lyExcelDataManager::initData();

}

void lyDateManager::DeleteAllDate()
{
	lyConfigManager::ReleaseAllConfig();
}

void lyDateManager::InitSysLanguage()
{
	string l_languageRoot = lyConfigManager::m_sSysConfig->m_languageRoot.toStdString();
	string l_languageName = lyConfigManager::m_sSysConfig->m_languageName.toStdString();
	string l_languagePath = l_languageRoot + l_languageName;
	lyLanguageManager::AddTranslator(lyLanguageManager::ReadAllTranslatorFile(l_languagePath), l_languageName);
	vector<QTranslator*>* l_pTranslatorList = lyLanguageManager::GetTranslator(l_languageName);
	if (l_pTranslatorList != NULL)
	{
		for (int i = 0; i < l_pTranslatorList->size(); i++)
		{
			QTranslator* l_pTranslator = l_pTranslatorList->at(i);
			QApplication::instance()->installTranslator(l_pTranslator);
		}
	}
}

void lyDateManager::InitSysTheme()
{
	string l_themeRoot = lyConfigManager::m_sSysConfig->m_themeRoot.toStdString();
	string l_themeName = lyConfigManager::m_sSysConfig->m_themeName.toStdString();
	string l_themePath = l_themeRoot + l_themeName;
	string l_qss = lyThemeManager::ReadAllQssFile(l_themePath);
	lyThemeManager::AddTheme(l_qss, l_themeName);
	QString l_styleSheet = QString::fromLocal8Bit(lyThemeManager::GetTheme(l_themeName).c_str());
	((QApplication*)QApplication::instance())->setStyleSheet(l_styleSheet);
}
