#include "lyExcelItemProxyModel.h"

lyExcelItemProxyModel::lyExcelItemProxyModel(QObject *parent)
	: QSortFilterProxyModel(parent)
{
}

lyExcelItemProxyModel::~lyExcelItemProxyModel()
{
}

//bool lyExcelItemProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
//{
//	return true;
//}
