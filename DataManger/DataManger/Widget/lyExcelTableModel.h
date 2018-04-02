#pragma once

#include <QAbstractTableModel>

#include "DateTableMes.h"

class lyExcelTableModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	lyExcelTableModel(QObject *parent);
	~lyExcelTableModel();

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

	bool editRows(int position, int rows, const QModelIndex &index, DateTableMes dateMes);

	bool insertRows(int position, int rows, const QModelIndex &index, DateTableMes dateMes);

	bool removeRows(int position, int rows, const QModelIndex &index);

	void setExcelTableData(const QString&fileName);

	void writeExcelTableData(const QString&fileName);

	void refreshTableData();
	
	void dataSort(const QModelIndex &index, int sort);
signals:
	void setExcelTitle(const QStringList& title);
	void writeFinished();
	void readFinished();

protected:
	QStringList m_columnList;
};
