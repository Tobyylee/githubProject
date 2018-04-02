#pragma once

#include <QSortFilterProxyModel>

class lyExcelItemProxyModel : public QSortFilterProxyModel
{
	Q_OBJECT

public:
	lyExcelItemProxyModel(QObject *parent);
	~lyExcelItemProxyModel();

protected:
	/*!
	*@brief 自定义过滤功能，过滤所有非在线设备
	*@param[in] sourceRow:		被判断过滤行
	*@param[in] sourceParent:	父INDEX
	*@return 返回是否过滤标记。过滤：false, 不过滤：true
	*@see 无
	*/
//	bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;
};
