/********************************************************************************
** Form generated from reading UI file 'DateInputTipWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATEINPUTTIPWIDGET_H
#define UI_DATEINPUTTIPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DateInputTipWidget
{
public:
    QLabel *label;

    void setupUi(QWidget *DateInputTipWidget)
    {
        if (DateInputTipWidget->objectName().isEmpty())
            DateInputTipWidget->setObjectName(QStringLiteral("DateInputTipWidget"));
        DateInputTipWidget->resize(408, 237);
        label = new QLabel(DateInputTipWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 60, 251, 71));

        retranslateUi(DateInputTipWidget);

        QMetaObject::connectSlotsByName(DateInputTipWidget);
    } // setupUi

    void retranslateUi(QWidget *DateInputTipWidget)
    {
        DateInputTipWidget->setWindowTitle(QApplication::translate("DateInputTipWidget", "DateInputTipWidget", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DateInputTipWidget: public Ui_DateInputTipWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATEINPUTTIPWIDGET_H
