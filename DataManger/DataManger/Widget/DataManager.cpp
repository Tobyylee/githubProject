#include "DataManager.h"
#include <QDebug>
#include <QDateTime>
#include <QFileDialog>

#include "DateTableMes.h"
#include "lyExcelDataManager.h"
#include "lyOperatorExcelFile.h"
#include "lyDataBase.h"
#include "lyEditMesType.h"
#include "lyEditMesTypeRoom.h"

DataManager::DataManager(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initWidget();
	initSlot();
}

DataManager::~DataManager()
{

}

void DataManager::initWidget()
{
	
}

void DataManager::initSlot()
{
	connect(ui.actionopenFile, SIGNAL(triggered()), this, SLOT(onOpenFile()));
	connect(ui.actionsaveFile, SIGNAL(triggered()), this, SLOT(onSaveFile()));
	connect(ui.actionoutputFile, SIGNAL(triggered()), this, SLOT(onOutputFile()));
	connect(ui.actionEditMesTpye, SIGNAL(triggered()), this, SLOT(onEditMesTpye()));
	connect(ui.actioneditMeetSite, SIGNAL(triggered()), this, SLOT(onEditMeetSite()));
}

void DataManager::onOpenFile()
{
	QFileDialog fileDialog;
	//�����ļ��Ի������  
	fileDialog.setWindowTitle(QStringLiteral("��Excel"));
	//����Ĭ���ļ�·��  
	fileDialog.setDirectory(".");
	//�����ļ�������  
	fileDialog.setNameFilter(tr("(*.xlsx)"));
	//���ÿ���ѡ�����ļ�,Ĭ��Ϊֻ��ѡ��һ���ļ�QFileDialog::ExistingFiles  
	fileDialog.setFileMode(QFileDialog::ExistingFiles);
	//������ͼģʽ  
	fileDialog.setViewMode(QFileDialog::Detail);
	QStringList fileNames;
	if (fileDialog.exec())
	{
		fileNames = fileDialog.selectedFiles();
	}
	for (auto tmp : fileNames)
	{
		ui.widget->setExcelTableData(tmp);
	}
}

void DataManager::onSaveFile()
{
	QMap<QString, QVector<DateTableMes>>& datas = *lyExcelDataManager::m_ExcelData;
	QMap<QString, QVector<DateTableMes>>::iterator it = datas.begin();
	while (it != datas.end())
	{
		QString l_key = it.key();
		QVector<DateTableMes>& l_dataTables = datas[l_key];
		for (int i = 0; i < l_dataTables.size(); i++)
		{
			if (l_dataTables.at(i).m_writeTime.isValid())
			{
				lyDataBase::getInstance()->insertExcelData(l_dataTables.at(i));
			}
		}
		it++;
	}
}

void DataManager::onOutputFile()
{
	QFileDialog fileDialog;
	//�����ļ��Ի������  
	fileDialog.setWindowTitle(QStringLiteral("����Excel"));
	//����Ĭ���ļ�·��  
	fileDialog.setDirectory(".");
	//���ÿ���ѡ�����ļ�,Ĭ��Ϊֻ��ѡ��һ���ļ�QFileDialog::ExistingFiles  
	fileDialog.setFileMode(QFileDialog::Directory);
	//������ͼģʽ  
	fileDialog.setViewMode(QFileDialog::Detail);

	QStringList fileNames;
	if (fileDialog.exec())
	{
		fileNames = fileDialog.selectedFiles();
	}
	for (auto tmp : fileNames)
	{
		ui.widget->writeExcelTableData(tmp);
	}
}

void DataManager::onEditMesTpye()
{
	lyEditMesType l_editMesType;
	l_editMesType.exec();
}

void DataManager::onEditMeetSite()
{
	lyEditMesTypeRoom l_editMesTypeRoom;
	l_editMesTypeRoom.exec();
}

