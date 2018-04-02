#pragma once

#include <map>
#include <vector>
#include <string>
using namespace std;

#include <QTranslator>

class lyLanguageManager
{
public:
	lyLanguageManager();
	virtual ~lyLanguageManager();

	static vector<QTranslator*>* ReadAllTranslatorFile(const string& dir);
	static bool AddTranslator(vector<QTranslator*>* list, const string& mark);
	static vector<QTranslator*>* GetTranslator(const string& mark);
	static void DeleteTranslator(const string& mark);
	static void DeleteAllTranslator();

protected:
	static void LanguageInit();

protected:
	static map<string, vector<QTranslator*>*>* m_sLanguages;
};