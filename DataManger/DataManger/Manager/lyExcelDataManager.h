#pragma once

#include <QVector>
#include <QMap>
#include "DateTableMes.h"

enum ly_sort
{
	ly_ascending = 0,
	ly_descending,
	ly_sort_count
};

class lyExcelDataManager
{
public:
	lyExcelDataManager();
	virtual ~lyExcelDataManager();

	static void initData();
	static void appendData(const DateTableMes& data);
	static void deleteData(const DateTableMes& data);
	static void updateData(const DateTableMes& data);
	static void insertData(int index, const DateTableMes& data);
	static const QStringList getAllExcelTitle();
	static void deleteTitle(const QString& title);
	static void judgeDateConflict();
	static QString getTitleName(const QString& name);
	static void creatNewPage(const QString& pageName);
	static void checkDataUrgency();
	static void isSelectDataPlan();
	static void renameTable(const QString& oldName, const QString& newName);

	//≈≈–Ú
	static bool writeSortDe(const DateTableMes& p1, const DateTableMes& p2);
	static bool writeSortAs(const DateTableMes& p1, const DateTableMes& p2);

	static bool beginTimeSortDe(const DateTableMes& p1, const DateTableMes& p2);
	static bool beginTimeSortAs(const DateTableMes& p1, const DateTableMes& p2);

	static bool endTimeSortDe(const DateTableMes& p1, const DateTableMes& p2);
	static bool endTimeSortAs(const DateTableMes& p1, const DateTableMes& p2);

	static bool PrioritizationSortDe(const DateTableMes& p1, const DateTableMes& p2);
	static bool PrioritizationSortAs(const DateTableMes& p1, const DateTableMes& p2);

	static void clearData();
	static QMap<QString, QVector<DateTableMes>>* m_ExcelData;
	static QString m_SelectedTitle;
};