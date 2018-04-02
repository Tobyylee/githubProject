/********************************************************************************
** Form generated from reading UI file 'lyDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYDIALOG_H
#define UI_LYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lyDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirmBtn;
    QPushButton *cancleBtn;

    void setupUi(QWidget *lyDialog)
    {
        if (lyDialog->objectName().isEmpty())
            lyDialog->setObjectName(QStringLiteral("lyDialog"));
        lyDialog->resize(567, 425);
        verticalLayout = new QVBoxLayout(lyDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(40, 40, 40, 40);
        tableView = new QTableView(lyDialog);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setStyleSheet(QLatin1String("QTableView\n"
"{\n"
"	background:rgb(33, 53, 82);\n"
"	color : rgb(255, 255, 255);\n"
"}\n"
"\n"
"QTableView QHeaderView::section\n"
"{\n"
"	background:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 rgb(255, 255, 255),stop:0.5 rgb(47, 129, 197),stop:1 rgb(58, 141, 222));\n"
"	border: 0px solid rgb(0, 0, 0);\n"
"	color : rgb(255, 255, 255);\n"
"	font-size: 18px;\n"
"	padding:5px;\n"
"}"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        confirmBtn = new QPushButton(lyDialog);
        confirmBtn->setObjectName(QStringLiteral("confirmBtn"));

        horizontalLayout->addWidget(confirmBtn);

        cancleBtn = new QPushButton(lyDialog);
        cancleBtn->setObjectName(QStringLiteral("cancleBtn"));

        horizontalLayout->addWidget(cancleBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(lyDialog);

        QMetaObject::connectSlotsByName(lyDialog);
    } // setupUi

    void retranslateUi(QWidget *lyDialog)
    {
        lyDialog->setWindowTitle(QApplication::translate("lyDialog", "lyDialog", Q_NULLPTR));
        confirmBtn->setText(QApplication::translate("lyDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        cancleBtn->setText(QApplication::translate("lyDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class lyDialog: public Ui_lyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYDIALOG_H
