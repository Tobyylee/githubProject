#pragma once

#include <QAbstractItemModel>
#include <QTreeWidgetItem>
#include "gtrTreeCheckItem.h"

enum ZoneBrowse
{
	ControlArea,
	ControlLine,
	Fairway,
	Facility_Traffic,
	Weather_Station,
	ZoneBrowse_Count,
};

enum ControlAreaItem
{
	Cultivation_Area,
	ForbidVoyage_Area,
	Military_Exercise_Area,
	Throw_Mud_Area,
	Limit_Speed_Area,
	Shoal_Area,
	No_Anchoring_Area,
	ControlAreaItem_Count,
};


class gtrHasbeenreadModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	gtrHasbeenreadModel(QObject *parent);
	~gtrHasbeenreadModel();

	QVariant data(const QModelIndex &index, int role) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	QVariant headerData(int section, Qt::Orientation orientation,
		int role = Qt::DisplayRole) const;
	QModelIndex index(int row, int column,
		const QModelIndex &parent = QModelIndex()) const;
	QModelIndex parent(const QModelIndex &index) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	// 构建模型数据  
	void setupModelData(gtrTreeCheckItem *parent);

	QMimeData* mimeData(const QModelIndexList &indexes) const;
	QStringList mimeTypes() const;
	bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
	// 更新模型数据  
	void updateData();

	void controlData(const QModelIndex& index);

	void addItem(const QModelIndex& index, const QList<QVariant>& data, int state);

protected:
	void setChildState(gtrTreeCheckItem* item, int state);
	void setParentState(gtrTreeCheckItem* item);
	gtrTreeCheckItem* findItem(gtrTreeCheckItem* item, QString& itemData);

private:
	gtrTreeCheckItem* rootItem;
	QIcon* m_icon;
	gtrTreeCheckItem* m_currentSelected;
};
