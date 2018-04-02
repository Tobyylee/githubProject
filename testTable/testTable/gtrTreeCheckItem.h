#pragma once

#include <QList>
#include <QVariant>

class gtrTreeCheckItem
{
public:
	gtrTreeCheckItem(const QList<QVariant> &data, gtrTreeCheckItem *parent = 0);
	~gtrTreeCheckItem();

	void appendChild(gtrTreeCheckItem *child);
	gtrTreeCheckItem *child(int row);
	int childCount() const;
	int columnCount() const;
	QVariant data(int column) const;
	int row() const;
	gtrTreeCheckItem *parent();
	void setChecked(int flag) { m_flag = flag;  }
	int getIsChecked() { return m_flag;  }
	void changeRow(int form, int to);

private:
	gtrTreeCheckItem *parentItem;  // �����  
	QList<gtrTreeCheckItem*> childItems; // �ӽ���б�  
	QList<QVariant> itemData; // �ӽڵ��Ӧ���� 
	int m_flag;
};

