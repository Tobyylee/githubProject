#pragma once
#include <stdio.h>

#include <map>
#include <string>

using namespace std;

class lyThemeManager 
{
public:
	lyThemeManager();
	virtual ~lyThemeManager();

	static string ReadAllQssFile(const string& dir);
	static bool AddTheme(const string& qss, const string& mark);
	static string GetTheme(const string& mark);
	static void DeleteTheme(const string& mark);
	static void DeleteAllTheme();

protected:
	static void ThemeInit();

protected:
	static map<string, string>* m_sThemes;
};