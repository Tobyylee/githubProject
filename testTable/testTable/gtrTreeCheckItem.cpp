#include "gtrTreeCheckItem.h"


gtrTreeCheckItem::gtrTreeCheckItem(const QList<QVariant> &data, gtrTreeCheckItem *parent)
{
	parentItem = parent;
	itemData = data;
	m_flag = false;
}


gtrTreeCheckItem::~gtrTreeCheckItem()
{
	qDeleteAll(childItems);
}

void gtrTreeCheckItem::appendChild(gtrTreeCheckItem *child)
{
	childItems.append(child);
}

gtrTreeCheckItem * gtrTreeCheckItem::child(int row)
{
	return childItems.value(row);
}

int gtrTreeCheckItem::childCount() const
{
	return childItems.count();
}

int gtrTreeCheckItem::columnCount() const
{
	return itemData.count();
}

QVariant gtrTreeCheckItem::data(int column) const
{
	return itemData.value(column);
}

int gtrTreeCheckItem::row() const
{
	if (parentItem)
		return parentItem->childItems.indexOf(const_cast<gtrTreeCheckItem*>(this));

	return 0;
}

gtrTreeCheckItem * gtrTreeCheckItem::parent()
{
	return parentItem;
}

void gtrTreeCheckItem::changeRow(int form, int to)
{
	childItems.swap(form, to);
}
