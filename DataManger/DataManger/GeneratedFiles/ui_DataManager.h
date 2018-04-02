/********************************************************************************
** Form generated from reading UI file 'DataManager.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAMANAGER_H
#define UI_DATAMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "lymainwidget.h"

QT_BEGIN_NAMESPACE

class Ui_DataMangerClass
{
public:
    QAction *actionopenFile;
    QAction *actionsaveFile;
    QAction *actionoutputFile;
    QAction *actionEditMesTpye;
    QAction *actioneditMeetSite;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    lyMainWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuoperator;

    void setupUi(QMainWindow *DataMangerClass)
    {
        if (DataMangerClass->objectName().isEmpty())
            DataMangerClass->setObjectName(QStringLiteral("DataMangerClass"));
        DataMangerClass->resize(850, 680);
        QIcon icon;
        icon.addFile(QStringLiteral(":/DataManger/Data/image/calendar.png"), QSize(), QIcon::Normal, QIcon::Off);
        DataMangerClass->setWindowIcon(icon);
        actionopenFile = new QAction(DataMangerClass);
        actionopenFile->setObjectName(QStringLiteral("actionopenFile"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/DataManger/Data/image/openFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionopenFile->setIcon(icon1);
        actionsaveFile = new QAction(DataMangerClass);
        actionsaveFile->setObjectName(QStringLiteral("actionsaveFile"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/DataManger/Data/image/saveFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsaveFile->setIcon(icon2);
        actionoutputFile = new QAction(DataMangerClass);
        actionoutputFile->setObjectName(QStringLiteral("actionoutputFile"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/DataManger/Data/image/outputFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionoutputFile->setIcon(icon3);
        actionEditMesTpye = new QAction(DataMangerClass);
        actionEditMesTpye->setObjectName(QStringLiteral("actionEditMesTpye"));
        actioneditMeetSite = new QAction(DataMangerClass);
        actioneditMeetSite->setObjectName(QStringLiteral("actioneditMeetSite"));
        centralWidget = new QWidget(DataMangerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("QWidget#centralWidget\n"
"{\n"
"	border-top: 1px solid white;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new lyMainWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 40));
        widget->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(widget);

        DataMangerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DataMangerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 850, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuoperator = new QMenu(menuBar);
        menuoperator->setObjectName(QStringLiteral("menuoperator"));
        DataMangerClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuoperator->menuAction());
        menuFile->addAction(actionopenFile);
        menuFile->addSeparator();
        menuFile->addAction(actionsaveFile);
        menuFile->addSeparator();
        menuFile->addAction(actionoutputFile);
        menuoperator->addAction(actionEditMesTpye);
        menuoperator->addAction(actioneditMeetSite);

        retranslateUi(DataMangerClass);

        QMetaObject::connectSlotsByName(DataMangerClass);
    } // setupUi

    void retranslateUi(QMainWindow *DataMangerClass)
    {
        DataMangerClass->setWindowTitle(QApplication::translate("DataMangerClass", "DataManger", Q_NULLPTR));
        actionopenFile->setText(QApplication::translate("DataMangerClass", "openFile", Q_NULLPTR));
        actionsaveFile->setText(QApplication::translate("DataMangerClass", "saveFile", Q_NULLPTR));
        actionoutputFile->setText(QApplication::translate("DataMangerClass", "outputFile", Q_NULLPTR));
        actionEditMesTpye->setText(QApplication::translate("DataMangerClass", "editMesTpye", Q_NULLPTR));
        actioneditMeetSite->setText(QApplication::translate("DataMangerClass", "editMeetSite", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("DataMangerClass", "File", Q_NULLPTR));
        menuoperator->setTitle(QApplication::translate("DataMangerClass", "operator", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DataMangerClass: public Ui_DataMangerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAMANAGER_H
