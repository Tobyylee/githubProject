/********************************************************************************
** Form generated from reading UI file 'lyCityWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYCITYWIDGET_H
#define UI_LYCITYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "lycitypagewidget.h"

QT_BEGIN_NAMESPACE

class Ui_lyCityWidget
{
public:
    QVBoxLayout *verticalLayout;
    lyCityPageWidget *page;

    void setupUi(QWidget *lyCityWidget)
    {
        if (lyCityWidget->objectName().isEmpty())
            lyCityWidget->setObjectName(QStringLiteral("lyCityWidget"));
        lyCityWidget->resize(421, 395);
        QIcon icon;
        icon.addFile(QStringLiteral(":/DataManger/Data/image/calendar.png"), QSize(), QIcon::Normal, QIcon::Off);
        lyCityWidget->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(lyCityWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        page = new lyCityPageWidget(lyCityWidget);
        page->setObjectName(QStringLiteral("page"));
        page->setFrameShape(QFrame::StyledPanel);
        page->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(page);


        retranslateUi(lyCityWidget);

        QMetaObject::connectSlotsByName(lyCityWidget);
    } // setupUi

    void retranslateUi(QWidget *lyCityWidget)
    {
        lyCityWidget->setWindowTitle(QApplication::translate("lyCityWidget", "lyCityWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class lyCityWidget: public Ui_lyCityWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYCITYWIDGET_H
