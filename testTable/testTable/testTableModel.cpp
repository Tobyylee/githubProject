#include "testTableModel.h"
#include "testTable.h"
#include <QDebug>

const char* g_TestTableModelName[] =
{
	QT_TRANSLATE_NOOP("testTableModel", "Name"),
	QT_TRANSLATE_NOOP("testTableModel", "Age"),
	QT_TRANSLATE_NOOP("testTableModel", "Height"),
	QT_TRANSLATE_NOOP("testTableModel", "Weight"),
	QT_TRANSLATE_NOOP("testTableModel", "Sex"),
	QT_TRANSLATE_NOOP("testTableModel", "isChecked"),
};

testTableModel::testTableModel(QObject* object)
{
	for (int i = 0; i < 6; i++)
	{
		m_columnList << tr(g_TestTableModelName[i]);
	}
}

testTableModel::~testTableModel()
{

}

Qt::ItemFlags testTableModel::flags(const QModelIndex &index) const
{
	Qt::ItemFlags theFlags = QAbstractTableModel::flags(index);
	if (index.isValid())
		theFlags |= Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
	return theFlags;
}

int testTableModel::rowCount(const QModelIndex &parent) const
{
	return parent.isValid() ? 0 : testTable::m_personData->count();
}

int testTableModel::columnCount(const QModelIndex &parent) const
{
	return parent.isValid() ? 0 : m_columnList.count();
}

QVariant testTableModel::data(const QModelIndex &index, int role /*= Qt::DisplayRole*/) const
{
	 QVector<personData>* l_data = testTable::m_personData;

	if (!index.isValid() || index.row() < 0 || index.row() >= l_data->count() ||
		index.column() < 0 || index.column() >= m_columnList.size())
		return QVariant();

	// 其他的role一定要有返回值，默认给QVariant()就行  && (Qt::BackgroundColorRole != role)
	//if(Qt::DisplayRole != role )  
	//{  
	//	return QVariant();  
	//}
	int curRow = index.row();
	QVariant  theResult;
	QString l_onlineStatus;
	const personData &dataItem = l_data->at(index.row());
	if (role == Qt::DisplayRole)
	{
		using ::citCCTVColumn;
		switch (index.column())
		{
		case P_NAME:
		{
			theResult = dataItem.m_name;
			break;
		}
		case P_AGE:
		{
			theResult = dataItem.m_age;
			
			break;
		}
		case P_HEIGHT:
		{
			theResult = dataItem.m_height;
			break;
		}
		case P_WEIGHT:
		{
			theResult = dataItem.m_weight;
			break;
		}
		case P_SEX:
		{
			theResult = dataItem.m_sex;
			break;
		}
		case P_FLAG:
		{
			theResult = dataItem.m_flag;
			break;
		}
		default:
			break;
		}
	}
	else if (role == Qt::TextAlignmentRole)
	{
		theResult = (Qt::AlignCenter);
		//return value;
	}
	else if(role == Qt::CheckStateRole)
	{ 
		if (index.column() == 0)
		{
			return Qt::Unchecked;
		}
	}
	//else if (role == Qt::BackgroundColorRole)
	//{
	///*	if (index.row() % 5 == 0)
	//		return QColor(Qt::red);*/
	//	/*else if (index.row() % 5 == 1)
	//		return QColor(Qt::green);
	//	else if (index.row() % 5 == 2)
	//		return QColor(Qt::blue);
	//	else if (index.row() % 5 == 3)
	//		return QColor(Qt::yellow);
	//	else if (index.row() % 5 == 4)
	//		return QColor(Qt::gray);*/
	//	/*if (!dataItem.m_flag)
	//	{
	//		if (index.column() == P_SEX)
	//		{
	//			return QColor(Qt::darkBlue);
	//		}
	//	}
	//	else
	//	{
	//		return QVariant();
	//	}*/
	//		
	//}
	else if (role == Qt::DecorationRole)
	{
		QImage l_image("drag.png");
		switch (index.column())
		{
		case P_NAME:	
		{
			theResult = QVariant(l_image);
			break;
		}
		}
	}
	else
	{
		return QVariant();
	}

	return theResult;
}

QVariant testTableModel::headerData(int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole*/) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			if (section < 0 || section >= m_columnList.size())
				return QVariant();
			else
				return m_columnList[section];
		}
		else
		{
			return QVariant(section + 1);
		}
	}

	return QAbstractTableModel::headerData(section, orientation, role);
}

bool testTableModel::setData(const QModelIndex &index, const QVariant &value, int role /*= Qt::EditRole*/)
{
	QVector<personData>* l_data = testTable::m_personData;

	if (index.isValid() && role == Qt::EditRole) {
		emit dataChanged(index, index);
		return true;
	}
	if (role == Qt::CheckStateRole && index.column() == 0)
	{
		bool l_flag = (value == Qt::Checked ? Qt::Checked : Qt::Unchecked);
	}
	if (!index.isValid() || role != Qt::DisplayRole || index.row() < 0 ||
		index.row() >= l_data->count() || index.column() < 0)
		return false;
	emit dataChanged(index, index);
	return true;
}

QStringList testTableModel::getColumnList()
{
	return m_columnList;
}

void testTableModel::updateStatus()
{

}
