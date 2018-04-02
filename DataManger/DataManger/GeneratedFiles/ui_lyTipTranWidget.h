/********************************************************************************
** Form generated from reading UI file 'lyTipTranWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYTIPTRANWIDGET_H
#define UI_LYTIPTRANWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_lyTipTranWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QDialog *lyTipTranWidget)
    {
        if (lyTipTranWidget->objectName().isEmpty())
            lyTipTranWidget->setObjectName(QStringLiteral("lyTipTranWidget"));
        lyTipTranWidget->resize(398, 216);
        QIcon icon;
        icon.addFile(QStringLiteral(":/DataManger/Data/image/calendar.png"), QSize(), QIcon::Normal, QIcon::Off);
        lyTipTranWidget->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(lyTipTranWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(lyTipTranWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        retranslateUi(lyTipTranWidget);

        QMetaObject::connectSlotsByName(lyTipTranWidget);
    } // setupUi

    void retranslateUi(QDialog *lyTipTranWidget)
    {
        lyTipTranWidget->setWindowTitle(QApplication::translate("lyTipTranWidget", "lyTipTranWidget", Q_NULLPTR));
        label->setText(QApplication::translate("lyTipTranWidget", "\346\255\243\345\234\250\345\257\274\345\207\272\346\225\260\346\215\256\357\274\214\350\257\267\347\250\215\345\220\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class lyTipTranWidget: public Ui_lyTipTranWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYTIPTRANWIDGET_H
