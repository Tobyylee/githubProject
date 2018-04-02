#include "lyConfigManager.h"

const char* lyConfigMan_SysConfigPath = "./Data/Config/SysConfig.ini";
const char* lyConfigMan_ParConfigPath = "./Data/Config/ParConfig.ini";

lySysConfig*   lyConfigManager::m_sSysConfig = nullptr;
lyParConfig*   lyConfigManager::m_sParConfig = nullptr;

lyConfigManager::lyConfigManager()
{

}

lyConfigManager::~lyConfigManager()
{

}

void lyConfigManager::ReadAllConfig()
{
	InitConfig();
	m_sSysConfig->ReadConfig();
	m_sParConfig->ReadConfig();
}

void lyConfigManager::WriteAllConfig()
{
	InitConfig();
	m_sSysConfig->WriteConfig();
	m_sParConfig->WriteConfig();
}

void lyConfigManager::ReleaseAllConfig()
{
	WriteAllConfig();
	if (m_sSysConfig != nullptr)
	{
		delete m_sSysConfig;
		m_sSysConfig = nullptr;
	}
	if (m_sParConfig != nullptr)
	{
		delete m_sParConfig;
		m_sParConfig = nullptr;
	}
}

void lyConfigManager::InitConfig()
{
	if (!m_sSysConfig)
	{
		m_sSysConfig = new lySysConfig(lyConfigMan_SysConfigPath);
	}
	if (!m_sParConfig)
	{
		m_sParConfig = new lyParConfig(lyConfigMan_ParConfigPath);
	}
}


