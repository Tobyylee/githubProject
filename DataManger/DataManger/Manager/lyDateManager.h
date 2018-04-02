#pragma once

class lyDateManager
{
public:
	lyDateManager();
	virtual ~lyDateManager();

	static void CreatAllDate();
	static void DeleteAllDate();

protected:
	static void InitSysLanguage();
	static void InitSysTheme();

};