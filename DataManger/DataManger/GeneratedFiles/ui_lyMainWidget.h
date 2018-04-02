/********************************************************************************
** Form generated from reading UI file 'lyMainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYMAINWIDGET_H
#define UI_LYMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lyMainWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *deleteBtn;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_2;
    QLabel *label_2;
    QLineEdit *pageNameLineEdit;
    QPushButton *buildPageBtn;
    QFrame *line;
    QLabel *label_5;
    QLineEdit *renameEdit;
    QPushButton *renameBtn;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line_3;
    QComboBox *findComboBox;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_3;
    QLabel *beginTimeLabel;
    QDateTimeEdit *beginTimeEdit;
    QLabel *endTimeLabel;
    QDateTimeEdit *endTimeEdit;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *dateSiteEdit;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *findBtn;
    QTableView *tableView;

    void setupUi(QWidget *lyMainWidget)
    {
        if (lyMainWidget->objectName().isEmpty())
            lyMainWidget->setObjectName(QStringLiteral("lyMainWidget"));
        lyMainWidget->resize(1793, 800);
        lyMainWidget->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background:rgb(255, 0, 0);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(lyMainWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(lyMainWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 40));
        frame->setStyleSheet(QLatin1String("QFrame#frame\n"
"{\n"
"	border-top: 1px solid white;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(comboBox);

        deleteBtn = new QPushButton(frame);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(deleteBtn->sizePolicy().hasHeightForWidth());
        deleteBtn->setSizePolicy(sizePolicy1);
        deleteBtn->setMinimumSize(QSize(80, 0));

        horizontalLayout->addWidget(deleteBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        line_2 = new QFrame(frame);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setStyleSheet(QStringLiteral("background:rgb(255, 255, 255);"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        pageNameLineEdit = new QLineEdit(frame);
        pageNameLineEdit->setObjectName(QStringLiteral("pageNameLineEdit"));
        sizePolicy.setHeightForWidth(pageNameLineEdit->sizePolicy().hasHeightForWidth());
        pageNameLineEdit->setSizePolicy(sizePolicy);
        pageNameLineEdit->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(pageNameLineEdit);

        buildPageBtn = new QPushButton(frame);
        buildPageBtn->setObjectName(QStringLiteral("buildPageBtn"));
        sizePolicy1.setHeightForWidth(buildPageBtn->sizePolicy().hasHeightForWidth());
        buildPageBtn->setSizePolicy(sizePolicy1);
        buildPageBtn->setMinimumSize(QSize(80, 0));

        horizontalLayout->addWidget(buildPageBtn);

        line = new QFrame(frame);
        line->setObjectName(QStringLiteral("line"));
        line->setStyleSheet(QStringLiteral("background:rgb(255, 255, 255);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        renameEdit = new QLineEdit(frame);
        renameEdit->setObjectName(QStringLiteral("renameEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(renameEdit->sizePolicy().hasHeightForWidth());
        renameEdit->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(renameEdit);

        renameBtn = new QPushButton(frame);
        renameBtn->setObjectName(QStringLiteral("renameBtn"));

        horizontalLayout->addWidget(renameBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        line_3 = new QFrame(frame);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setStyleSheet(QStringLiteral("background:rgb(255, 255, 255);"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        findComboBox = new QComboBox(frame);
        findComboBox->setObjectName(QStringLiteral("findComboBox"));
        sizePolicy.setHeightForWidth(findComboBox->sizePolicy().hasHeightForWidth());
        findComboBox->setSizePolicy(sizePolicy);
        findComboBox->setMinimumSize(QSize(150, 0));
        findComboBox->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(findComboBox);

        stackedWidget = new QStackedWidget(frame);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy3);
        stackedWidget->setMaximumSize(QSize(16777215, 40));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        horizontalLayout_3 = new QHBoxLayout(page);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        beginTimeLabel = new QLabel(page);
        beginTimeLabel->setObjectName(QStringLiteral("beginTimeLabel"));

        horizontalLayout_3->addWidget(beginTimeLabel);

        beginTimeEdit = new QDateTimeEdit(page);
        beginTimeEdit->setObjectName(QStringLiteral("beginTimeEdit"));
        sizePolicy1.setHeightForWidth(beginTimeEdit->sizePolicy().hasHeightForWidth());
        beginTimeEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(beginTimeEdit);

        endTimeLabel = new QLabel(page);
        endTimeLabel->setObjectName(QStringLiteral("endTimeLabel"));

        horizontalLayout_3->addWidget(endTimeLabel);

        endTimeEdit = new QDateTimeEdit(page);
        endTimeEdit->setObjectName(QStringLiteral("endTimeEdit"));
        sizePolicy1.setHeightForWidth(endTimeEdit->sizePolicy().hasHeightForWidth());
        endTimeEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(endTimeEdit);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        horizontalLayout_4 = new QHBoxLayout(page_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        dateSiteEdit = new QLineEdit(page_2);
        dateSiteEdit->setObjectName(QStringLiteral("dateSiteEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(dateSiteEdit->sizePolicy().hasHeightForWidth());
        dateSiteEdit->setSizePolicy(sizePolicy4);

        horizontalLayout_4->addWidget(dateSiteEdit);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        horizontalLayout_5 = new QHBoxLayout(page_3);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        lineEdit = new QLineEdit(page_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(lineEdit);

        stackedWidget->addWidget(page_3);

        horizontalLayout->addWidget(stackedWidget);

        findBtn = new QPushButton(frame);
        findBtn->setObjectName(QStringLiteral("findBtn"));
        sizePolicy1.setHeightForWidth(findBtn->sizePolicy().hasHeightForWidth());
        findBtn->setSizePolicy(sizePolicy1);
        findBtn->setMinimumSize(QSize(100, 0));
        findBtn->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(findBtn);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addWidget(frame);

        tableView = new QTableView(lyMainWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(tableView);


        retranslateUi(lyMainWidget);

        QMetaObject::connectSlotsByName(lyMainWidget);
    } // setupUi

    void retranslateUi(QWidget *lyMainWidget)
    {
        lyMainWidget->setWindowTitle(QApplication::translate("lyMainWidget", "lyMainWidget", Q_NULLPTR));
        label->setText(QApplication::translate("lyMainWidget", "currentshowPage", Q_NULLPTR));
        deleteBtn->setText(QApplication::translate("lyMainWidget", "\345\210\240\351\231\244\351\241\265", Q_NULLPTR));
        label_2->setText(QApplication::translate("lyMainWidget", "\346\226\260\345\273\272\351\241\265\345\220\215\357\274\232", Q_NULLPTR));
        buildPageBtn->setText(QApplication::translate("lyMainWidget", "\346\226\260\345\273\272\351\241\265", Q_NULLPTR));
        label_5->setText(QApplication::translate("lyMainWidget", "\345\275\223\345\211\215\350\241\250\345\220\215:", Q_NULLPTR));
        renameBtn->setText(QApplication::translate("lyMainWidget", "\344\277\256\346\224\271\350\241\250\345\220\215", Q_NULLPTR));
        beginTimeLabel->setText(QApplication::translate("lyMainWidget", "\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        endTimeLabel->setText(QApplication::translate("lyMainWidget", "\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        label_3->setText(QApplication::translate("lyMainWidget", "\346\227\245\347\250\213\345\234\260\347\202\271", Q_NULLPTR));
        label_4->setText(QApplication::translate("lyMainWidget", "\346\227\245\347\250\213\345\210\206\347\261\273:", Q_NULLPTR));
        findBtn->setText(QApplication::translate("lyMainWidget", "\346\237\245\350\257\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class lyMainWidget: public Ui_lyMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYMAINWIDGET_H
