/********************************************************************************
** Form generated from reading UI file 'lyDataMesDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYDATAMESDIALOG_H
#define UI_LYDATAMESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "lydatesiteedit.h"

QT_BEGIN_NAMESPACE

class Ui_lyDataMesDialog
{
public:
    QHBoxLayout *horizontalLayout_11;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *writeTimeLabel;
    QDateTimeEdit *writeTimeEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *mesSectionLabel;
    QLineEdit *mesSectionEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *mesTypeLabel;
    QComboBox *mesTypeComboBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *mesContentLabel;
    QLineEdit *mesContentEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *dateSiteLabel;
    lyDateSiteEdit *dateSiteEdit;
    QComboBox *dateSiteComboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *beginTimeLabel;
    QDateTimeEdit *beginTimeEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *endTimeLabel;
    QDateTimeEdit *endTimeEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *datePlanLabel;
    QComboBox *datePlanComboBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *remarkLabel;
    QLineEdit *remarkEdit;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirmBtn;
    QPushButton *cancleBtn;

    void setupUi(QDialog *lyDataMesDialog)
    {
        if (lyDataMesDialog->objectName().isEmpty())
            lyDataMesDialog->setObjectName(QStringLiteral("lyDataMesDialog"));
        lyDataMesDialog->resize(442, 621);
        QIcon icon;
        icon.addFile(QStringLiteral(":/DataManger/Data/image/calendar.png"), QSize(), QIcon::Normal, QIcon::Off);
        lyDataMesDialog->setWindowIcon(icon);
        lyDataMesDialog->setStyleSheet(QLatin1String("QDialog\n"
"{\n"
"	border: 0px solid gray;\n"
"}"));
        horizontalLayout_11 = new QHBoxLayout(lyDataMesDialog);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(5, 5, 5, 5);
        frame = new QFrame(lyDataMesDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        writeTimeLabel = new QLabel(frame);
        writeTimeLabel->setObjectName(QStringLiteral("writeTimeLabel"));
        writeTimeLabel->setMinimumSize(QSize(120, 0));
        writeTimeLabel->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(writeTimeLabel);

        writeTimeEdit = new QDateTimeEdit(frame);
        writeTimeEdit->setObjectName(QStringLiteral("writeTimeEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(writeTimeEdit->sizePolicy().hasHeightForWidth());
        writeTimeEdit->setSizePolicy(sizePolicy);
        writeTimeEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(writeTimeEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        mesSectionLabel = new QLabel(frame);
        mesSectionLabel->setObjectName(QStringLiteral("mesSectionLabel"));
        mesSectionLabel->setMinimumSize(QSize(120, 0));
        mesSectionLabel->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_4->addWidget(mesSectionLabel);

        mesSectionEdit = new QLineEdit(frame);
        mesSectionEdit->setObjectName(QStringLiteral("mesSectionEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mesSectionEdit->sizePolicy().hasHeightForWidth());
        mesSectionEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(mesSectionEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        mesTypeLabel = new QLabel(frame);
        mesTypeLabel->setObjectName(QStringLiteral("mesTypeLabel"));
        mesTypeLabel->setMinimumSize(QSize(120, 0));
        mesTypeLabel->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_5->addWidget(mesTypeLabel);

        mesTypeComboBox = new QComboBox(frame);
        mesTypeComboBox->setObjectName(QStringLiteral("mesTypeComboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mesTypeComboBox->sizePolicy().hasHeightForWidth());
        mesTypeComboBox->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(mesTypeComboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        mesContentLabel = new QLabel(frame);
        mesContentLabel->setObjectName(QStringLiteral("mesContentLabel"));
        mesContentLabel->setMinimumSize(QSize(120, 0));
        mesContentLabel->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_7->addWidget(mesContentLabel);

        mesContentEdit = new QLineEdit(frame);
        mesContentEdit->setObjectName(QStringLiteral("mesContentEdit"));
        sizePolicy1.setHeightForWidth(mesContentEdit->sizePolicy().hasHeightForWidth());
        mesContentEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(mesContentEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        dateSiteLabel = new QLabel(frame);
        dateSiteLabel->setObjectName(QStringLiteral("dateSiteLabel"));
        dateSiteLabel->setMinimumSize(QSize(120, 0));
        dateSiteLabel->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_6->addWidget(dateSiteLabel);

        dateSiteEdit = new lyDateSiteEdit(frame);
        dateSiteEdit->setObjectName(QStringLiteral("dateSiteEdit"));
        sizePolicy1.setHeightForWidth(dateSiteEdit->sizePolicy().hasHeightForWidth());
        dateSiteEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(dateSiteEdit);

        dateSiteComboBox = new QComboBox(frame);
        dateSiteComboBox->setObjectName(QStringLiteral("dateSiteComboBox"));
        sizePolicy2.setHeightForWidth(dateSiteComboBox->sizePolicy().hasHeightForWidth());
        dateSiteComboBox->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(dateSiteComboBox);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        beginTimeLabel = new QLabel(frame);
        beginTimeLabel->setObjectName(QStringLiteral("beginTimeLabel"));
        beginTimeLabel->setMinimumSize(QSize(120, 0));
        beginTimeLabel->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_2->addWidget(beginTimeLabel);

        beginTimeEdit = new QDateTimeEdit(frame);
        beginTimeEdit->setObjectName(QStringLiteral("beginTimeEdit"));
        sizePolicy.setHeightForWidth(beginTimeEdit->sizePolicy().hasHeightForWidth());
        beginTimeEdit->setSizePolicy(sizePolicy);
        beginTimeEdit->setCalendarPopup(true);

        horizontalLayout_2->addWidget(beginTimeEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        endTimeLabel = new QLabel(frame);
        endTimeLabel->setObjectName(QStringLiteral("endTimeLabel"));
        endTimeLabel->setMinimumSize(QSize(120, 0));
        endTimeLabel->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_3->addWidget(endTimeLabel);

        endTimeEdit = new QDateTimeEdit(frame);
        endTimeEdit->setObjectName(QStringLiteral("endTimeEdit"));
        sizePolicy.setHeightForWidth(endTimeEdit->sizePolicy().hasHeightForWidth());
        endTimeEdit->setSizePolicy(sizePolicy);
        endTimeEdit->setCalendarPopup(true);

        horizontalLayout_3->addWidget(endTimeEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        datePlanLabel = new QLabel(frame);
        datePlanLabel->setObjectName(QStringLiteral("datePlanLabel"));
        datePlanLabel->setMinimumSize(QSize(120, 0));
        datePlanLabel->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_8->addWidget(datePlanLabel);

        datePlanComboBox = new QComboBox(frame);
        datePlanComboBox->setObjectName(QStringLiteral("datePlanComboBox"));
        sizePolicy2.setHeightForWidth(datePlanComboBox->sizePolicy().hasHeightForWidth());
        datePlanComboBox->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(datePlanComboBox);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        remarkLabel = new QLabel(frame);
        remarkLabel->setObjectName(QStringLiteral("remarkLabel"));
        remarkLabel->setMinimumSize(QSize(120, 0));
        remarkLabel->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_9->addWidget(remarkLabel);

        remarkEdit = new QLineEdit(frame);
        remarkEdit->setObjectName(QStringLiteral("remarkEdit"));
        sizePolicy1.setHeightForWidth(remarkEdit->sizePolicy().hasHeightForWidth());
        remarkEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(remarkEdit);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(5);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(5, 5, 5, 5);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        confirmBtn = new QPushButton(frame);
        confirmBtn->setObjectName(QStringLiteral("confirmBtn"));
        confirmBtn->setMinimumSize(QSize(100, 40));

        horizontalLayout_10->addWidget(confirmBtn);

        cancleBtn = new QPushButton(frame);
        cancleBtn->setObjectName(QStringLiteral("cancleBtn"));
        cancleBtn->setMinimumSize(QSize(100, 40));

        horizontalLayout_10->addWidget(cancleBtn);


        verticalLayout->addLayout(horizontalLayout_10);


        horizontalLayout_11->addWidget(frame);


        retranslateUi(lyDataMesDialog);

        QMetaObject::connectSlotsByName(lyDataMesDialog);
    } // setupUi

    void retranslateUi(QDialog *lyDataMesDialog)
    {
        lyDataMesDialog->setWindowTitle(QApplication::translate("lyDataMesDialog", "lyDataMesDialog", Q_NULLPTR));
        writeTimeLabel->setText(QApplication::translate("lyDataMesDialog", "\345\275\225\345\205\245\346\227\266\351\227\264", Q_NULLPTR));
        mesSectionLabel->setText(QApplication::translate("lyDataMesDialog", "\344\277\241\346\201\257\345\275\222\345\261\236", Q_NULLPTR));
        mesTypeLabel->setText(QApplication::translate("lyDataMesDialog", "\344\277\241\346\201\257\345\210\206\347\261\273", Q_NULLPTR));
        mesContentLabel->setText(QApplication::translate("lyDataMesDialog", "\344\277\241\346\201\257\345\206\205\345\256\271", Q_NULLPTR));
        dateSiteLabel->setText(QApplication::translate("lyDataMesDialog", "\346\227\245\347\250\213\345\234\260\347\202\271", Q_NULLPTR));
        beginTimeLabel->setText(QApplication::translate("lyDataMesDialog", "\346\227\245\347\250\213\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        endTimeLabel->setText(QApplication::translate("lyDataMesDialog", "\346\227\245\347\250\213\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        datePlanLabel->setText(QApplication::translate("lyDataMesDialog", "\346\227\245\347\250\213\350\277\233\345\272\246", Q_NULLPTR));
        remarkLabel->setText(QApplication::translate("lyDataMesDialog", "\345\244\207\346\263\250", Q_NULLPTR));
        confirmBtn->setText(QApplication::translate("lyDataMesDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        cancleBtn->setText(QApplication::translate("lyDataMesDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class lyDataMesDialog: public Ui_lyDataMesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYDATAMESDIALOG_H
