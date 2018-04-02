#ifndef TESTTABLEMODEL_H
#define TESTTABLEMODEL_H_

#include <QAbstractTableModel>

class testTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	testTableModel(QObject* object = nullptr);
	virtual ~testTableModel();

	Qt::ItemFlags flags(const QModelIndex &index) const;

	virtual int rowCount(const QModelIndex &parent) const;

	virtual int columnCount(const QModelIndex &parent) const;

	/*!< 表格数据，返回每个单元格的各种role的值 */
	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	/*!< 可以返回行列名称 */
	virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

	QStringList getColumnList();

	void updateStatus();

protected:
	QStringList m_columnList;
};

#pragma once
#endif // 
