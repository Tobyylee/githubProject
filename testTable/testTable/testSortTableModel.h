#ifndef TESTSORTTABLEMODEL_H_
#define TESTSORTTABLEMODEL_H_

#include <QSortFilterProxyModel>
class testSortTableModel : public QSortFilterProxyModel
{
	Q_OBJECT
public:
	testSortTableModel(QObject* object = nullptr);
	virtual ~testSortTableModel();

protected:
	/*!
	*@brief 自定义过滤功能，过滤所有非在线设备
	*@param[in] sourceRow:		被判断过滤行
	*@param[in] sourceParent:	父INDEX
	*@return 返回是否过滤标记。过滤：false, 不过滤：true
	*@see 无
	*/
	bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;
};

#pragma once
#endif // TESTSORTTABLEMODEL_H_
