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
	*@brief �Զ�����˹��ܣ��������з������豸
	*@param[in] sourceRow:		���жϹ�����
	*@param[in] sourceParent:	��INDEX
	*@return �����Ƿ���˱�ǡ����ˣ�false, �����ˣ�true
	*@see ��
	*/
//	bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;
};
