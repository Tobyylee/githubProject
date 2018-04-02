/********************************************************************************
** Form generated from reading UI file 'DataInputTipWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAINPUTTIPWIDGET_H
#define UI_DATAINPUTTIPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DataInputTipWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;

    void setupUi(QDialog *DataInputTipWidget)
    {
        if (DataInputTipWidget->objectName().isEmpty())
            DataInputTipWidget->setObjectName(QStringLiteral("DataInputTipWidget"));
        DataInputTipWidget->resize(385, 272);
        horizontalLayout = new QHBoxLayout(DataInputTipWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(DataInputTipWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);


        horizontalLayout->addWidget(frame);


        retranslateUi(DataInputTipWidget);

        QMetaObject::connectSlotsByName(DataInputTipWidget);
    } // setupUi

    void retranslateUi(QDialog *DataInputTipWidget)
    {
        DataInputTipWidget->setWindowTitle(QApplication::translate("DataInputTipWidget", "DataInputTipWidget", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DataInputTipWidget: public Ui_DataInputTipWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAINPUTTIPWIDGET_H
