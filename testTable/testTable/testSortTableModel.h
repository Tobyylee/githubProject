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
	*@brief �Զ�����˹��ܣ��������з������豸
	*@param[in] sourceRow:		���жϹ�����
	*@param[in] sourceParent:	��INDEX
	*@return �����Ƿ���˱�ǡ����ˣ�false, �����ˣ�true
	*@see ��
	*/
	bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;
};

#pragma once
#endif // TESTSORTTABLEMODEL_H_
