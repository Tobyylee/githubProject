#include "gtrHasbeenreadModel.h"
#include <QDebug>
#include <QFile>
#include <QMimeData>

const QString g_AreaBrower[ZoneBrowse_Count] =
{
	QStringLiteral("控制区"),
	QStringLiteral("控制线"),
	QStringLiteral("航道"),
	QStringLiteral("交通设施"),
	QStringLiteral("气象站"),
};

const QString g_ControlAreaItems[ControlAreaItem_Count] =
{
	QStringLiteral("养殖区"),
	QStringLiteral("禁航区"),
	QStringLiteral("军事演习区"),
	QStringLiteral("抛泥区"),
	QStringLiteral("限速区"),
	QStringLiteral("浅滩区"),
	QStringLiteral("禁锚区"),
};

gtrHasbeenreadModel::gtrHasbeenreadModel(QObject *parent)
	: QAbstractItemModel(parent)
{
	rootItem = NULL;
	m_icon = new QIcon("./Data/Image/ToolBar/drag.png");
	updateData();
	m_currentSelected = nullptr;
}

gtrHasbeenreadModel::~gtrHasbeenreadModel()
{
	if(rootItem)
	{
		delete rootItem;
		rootItem = nullptr;
	}
}

QVariant gtrHasbeenreadModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	
	// 显示节点数据值  
	if (role == Qt::DisplayRole)
	{
		gtrTreeCheckItem *item = static_cast<gtrTreeCheckItem*>(index.internalPointer());
		return item->data(index.column());
	}
	else if (role == Qt::CheckStateRole)
	{
		gtrTreeCheckItem *item = static_cast<gtrTreeCheckItem*>(index.internalPointer());
		return item->getIsChecked();
	}
	else if (role == Qt::DecorationRole&&index.column() == 0)
	{
		return *m_icon;
	}
	return QVariant();
}

Qt::ItemFlags gtrHasbeenreadModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return 0;

//	Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
	return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;
}

QVariant gtrHasbeenreadModel::headerData(int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole*/) const
{
	if (orientation == Qt::Horizontal&&role == Qt::DisplayRole)
		return rootItem->data(section);

	return QVariant();
}

QModelIndex gtrHasbeenreadModel::index(int row, int column, const QModelIndex &parent /*= QModelIndex()*/) const
{
	if (!hasIndex(row, column, parent))
		return QModelIndex();

	gtrTreeCheckItem *parentItem;
	if (!parent.isValid())
	{
		parentItem = rootItem;
	}
	else
	{
		parentItem = static_cast<gtrTreeCheckItem*>(parent.internalPointer());
	}

	gtrTreeCheckItem *childItem = parentItem->child(row);
	if (childItem)
		return createIndex(row, column, childItem); // 展开树形,为子节点建立索引  
	else
		return QModelIndex();
}

QModelIndex gtrHasbeenreadModel::parent(const QModelIndex &index) const
{
	if (!index.isValid())
		return QModelIndex();

	gtrTreeCheckItem *childItem = static_cast<gtrTreeCheckItem*>(index.internalPointer());
	gtrTreeCheckItem *parentItem = childItem->parent();

	// 顶层节点,直接返回空索引  
	if (parentItem == rootItem)
		return QModelIndex();

	// 为父结点建立索引  
	return createIndex(parentItem->row(), 0, parentItem);
}

int gtrHasbeenreadModel::rowCount(const QModelIndex &parent /*= QModelIndex()*/) const
{
	gtrTreeCheckItem *parentItem;

	if (!parent.isValid())
		parentItem = rootItem;
	else
		parentItem = static_cast<gtrTreeCheckItem*>(parent.internalPointer());

	return parentItem->childCount(); // 返回父结点下子结点数目
}

int gtrHasbeenreadModel::columnCount(const QModelIndex &parent /*= QModelIndex()*/) const
{
	return rootItem->columnCount();
}

bool gtrHasbeenreadModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	qDebug() << "setData:" << index.row() << "value:" << value;
	return true;
}

QMimeData* gtrHasbeenreadModel::mimeData(const QModelIndexList &indexes) const
{
	if (indexes.count() <= 0)
	{//If the list of indexes is empty, or there are no supported MIME types,
	 //0 is returned rather than a serialized empty list.
		return 0;
	}

	//QMap<int, QStringList> nodeData;
	//QStringList listName;
	//  foreach(QModelIndex index, indexes)
	//  {
	//      TreeNode* node = nodeFromIndex(index);
	//  }

	QByteArray itemData;
	QDataStream dataStream(&itemData, QIODevice::ReadWrite);
	dataStream.setVersion(QDataStream::Qt_5_8);
	gtrTreeCheckItem *item = static_cast<gtrTreeCheckItem*>(indexes.at(0).internalPointer());
	/*gtrTreeCheckItem* node = nodeFromIndex(indexes.at(0));
	NlsData::ConItem* conItem = static_cast<NlsData::ConItem*>(node->data());*/
	int l_column = indexes.at(0).column();
	if (item)
	{
		qDebug() << item->data(l_column).toString();
		dataStream<< item->data(l_column);
	}
	qDebug() << itemData;
	QMimeData *data = new QMimeData;
	data->setData("text/plain", itemData);//key值需要与Drop中一致
	return data;
}

void gtrHasbeenreadModel::setupModelData(gtrTreeCheckItem *parent)
{
	for (int i = 0; i < ZoneBrowse_Count; i++)
	{
		QList<QVariant> datas;
		datas << g_AreaBrower[i];

		// 主结点下挂两个子节点  
		gtrTreeCheckItem *primary = new gtrTreeCheckItem(datas, parent);
		primary->setChecked(Qt::Checked);
		parent->appendChild(primary);
		

		for (int j = 0; j < ControlAreaItem_Count; j++)
		{
			if (i == ControlArea)
			{
				QList<QVariant> ds;
				ds << g_ControlAreaItems[j];
				gtrTreeCheckItem *children = new gtrTreeCheckItem(ds, primary);
				children->setChecked(Qt::Checked);
				primary->appendChild(children);
				if (j == ForbidVoyage_Area)
				{
					for (int z = 0; z < 2; z++)
					{
						QList<QVariant> ds2;
						ds2 << QStringLiteral("禁锚区-%2").arg(z);
						gtrTreeCheckItem *children2 = new gtrTreeCheckItem(ds2, children);
						children2->setChecked(Qt::Checked);
						children->appendChild(children2);
					}
				}
			}
		}
	}
}

QStringList gtrHasbeenreadModel::mimeTypes() const
{
	return QStringList("text/plain");
}

void gtrHasbeenreadModel::updateData()
{
	if (rootItem)
	{
		delete rootItem;
		rootItem = NULL;
	}

	QList<QVariant> rootData;
	rootData << QStringLiteral("区域浏览");

	rootItem = new gtrTreeCheckItem(rootData);
	rootItem->setChecked(Qt::Checked);
	setupModelData(rootItem);

	// 刷新模型  
	//reset();
}

void gtrHasbeenreadModel::controlData(const QModelIndex& index)
{
	layoutAboutToBeChanged();
	gtrTreeCheckItem* indexItem = static_cast<gtrTreeCheckItem*>(index.internalPointer());
	bool l_indexFlag = false;
	//设置子item值
	if (indexItem->getIsChecked() == Qt::Checked || indexItem->getIsChecked() == Qt::PartiallyChecked)
	{
		indexItem->setChecked(Qt::Unchecked);
		setChildState(indexItem, Qt::Unchecked);
	}
	else
	{
		indexItem->setChecked(Qt::Checked);
		setChildState(indexItem, Qt::Checked);
		l_indexFlag = true;
	}
	//查询父节点
	setParentState(indexItem);
	layoutChanged();
}

void gtrHasbeenreadModel::addItem(const QModelIndex& index, const QList<QVariant>& data, int state)
{
	gtrTreeCheckItem* indexItem = static_cast<gtrTreeCheckItem*>(index.internalPointer());
	gtrTreeCheckItem *children = new gtrTreeCheckItem(data, indexItem);
	children->setChecked(state);
	indexItem->appendChild(children);
}

void gtrHasbeenreadModel::setChildState(gtrTreeCheckItem* item, int state)
{
	int childrenCount = item->childCount();
	for (int i = 0; i < childrenCount; i++)
	{
		item->child(i)->setChecked(state);
		setChildState(item->child(i), state);
	}
}

void gtrHasbeenreadModel::setParentState(gtrTreeCheckItem* item)
{
	gtrTreeCheckItem* parentItem = item->parent();
	if (parentItem)
	{
		int childrenCount = parentItem->childCount();
		int childrenStateChecked = 0;
		int childrenStateUnchecked = 0;
		for (int i = 0; i < childrenCount; i++)
		{
			if (parentItem->child(i)->getIsChecked() == Qt::Checked)
			{
				childrenStateChecked++;
			}
			else if (parentItem->child(i)->getIsChecked() == Qt::Unchecked)
			{
				childrenStateUnchecked++;
			}
		}
		if (childrenStateChecked == childrenCount)
		{
			parentItem->setChecked(Qt::Checked);
		}
		else if (childrenStateUnchecked == childrenCount)
		{
			parentItem->setChecked(Qt::Unchecked);
		}
		else
		{
			parentItem->setChecked(Qt::PartiallyChecked);
		}
		setParentState(parentItem);
	}
}

gtrTreeCheckItem* gtrHasbeenreadModel::findItem(gtrTreeCheckItem* item, QString& itemData)
{
	if (item)
	{
		if (item->data(0).toString() == itemData)
		{
			m_currentSelected = item;
		}
		else
		{
			if (item->childCount() > 0)
			{
				for (int i = 0; i < item->childCount(); i++)
				{
					findItem(item->child(i), itemData);
				}
			}
		}
	}
	return nullptr;
}

bool gtrHasbeenreadModel::dropMimeData(const QMimeData *dataa, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
	layoutAboutToBeChanged();
	gtrTreeCheckItem *item = static_cast<gtrTreeCheckItem*>(parent.internalPointer());

	QByteArray l_byte = dataa->data("text/plain");
	QDataStream dataStream(&l_byte, QIODevice::ReadWrite);
	dataStream.setVersion(QDataStream::Qt_5_8);
	QVariant l_data;
	dataStream>> l_data;
	findItem(rootItem, l_data.toString());
	if (m_currentSelected)
	{
		if (m_currentSelected->parent() == item->parent())
		{
			item->parent()->changeRow(m_currentSelected->row(), item->row());
		}
	}
	m_currentSelected = nullptr;
	layoutChanged();
	qDebug() << "row" << row<<"column"<< column <<"data"<< l_data.toString()<<"item"<< item->data(0).toString();
	return true;
}
