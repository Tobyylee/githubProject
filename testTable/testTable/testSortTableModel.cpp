#include "testSortTableModel.h"

testSortTableModel::testSortTableModel(QObject* object /*= nullptr*/)
{

}

testSortTableModel::~testSortTableModel()
{

}

bool testSortTableModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
	return true;
}
