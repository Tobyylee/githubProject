/********************************************************************************
** Form generated from reading UI file 'testTable.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTTABLE_H
#define UI_TESTTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "lytreeview.h"

QT_BEGIN_NAMESPACE

class Ui_testTableClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;
    QCalendarWidget *calendarWidget;
    lyTreeView *treeView_2;
    lyTreeView *treeView;
    QSpacerItem *verticalSpacer;
    QTableView *tableView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *testTableClass)
    {
        if (testTableClass->objectName().isEmpty())
            testTableClass->setObjectName(QStringLiteral("testTableClass"));
        testTableClass->resize(416, 564);
        centralWidget = new QWidget(testTableClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);

        treeView_2 = new lyTreeView(centralWidget);
        treeView_2->setObjectName(QStringLiteral("treeView_2"));

        verticalLayout->addWidget(treeView_2);

        treeView = new lyTreeView(centralWidget);
        treeView->setObjectName(QStringLiteral("treeView"));

        verticalLayout->addWidget(treeView);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        horizontalLayout->addWidget(tableView);


        horizontalLayout_2->addLayout(horizontalLayout);

        testTableClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(testTableClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 416, 26));
        testTableClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(testTableClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        testTableClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(testTableClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        testTableClass->setStatusBar(statusBar);

        retranslateUi(testTableClass);

        QMetaObject::connectSlotsByName(testTableClass);
    } // setupUi

    void retranslateUi(QMainWindow *testTableClass)
    {
        testTableClass->setWindowTitle(QApplication::translate("testTableClass", "testTable", Q_NULLPTR));
        label->setText(QString());
        pushButton->setText(QApplication::translate("testTableClass", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class testTableClass: public Ui_testTableClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTTABLE_H
