#pragma once

#include "lySysConfig.h"
#include "lyParConfig.h"

class lyConfigManager
{
public:
	lyConfigManager();
	virtual ~lyConfigManager();

	static void ReadAllConfig();
	static void WriteAllConfig();
	static void ReleaseAllConfig();

protected:
	static void InitConfig();

public:
	static lySysConfig* m_sSysConfig;
	static lyParConfig* m_sParConfig;
};
