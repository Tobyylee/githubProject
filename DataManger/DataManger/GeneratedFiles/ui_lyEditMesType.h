/********************************************************************************
** Form generated from reading UI file 'lyEditMesType.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYEDITMESTYPE_H
#define UI_LYEDITMESTYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_lyEditMesType
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QLabel *mesTypeLabel;
    QComboBox *mesTypeComboBox;
    QLabel *modifyLabel;
    QLineEdit *modifyEdit;
    QPushButton *addBtn;
    QPushButton *delBtn;
    QPushButton *editBtn;

    void setupUi(QDialog *lyEditMesType)
    {
        if (lyEditMesType->objectName().isEmpty())
            lyEditMesType->setObjectName(QStringLiteral("lyEditMesType"));
        lyEditMesType->resize(483, 355);
        QIcon icon;
        icon.addFile(QStringLiteral(":/DataManger/Data/image/calendar.png"), QSize(), QIcon::Normal, QIcon::Off);
        lyEditMesType->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(lyEditMesType);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(lyEditMesType);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        mesTypeLabel = new QLabel(frame);
        mesTypeLabel->setObjectName(QStringLiteral("mesTypeLabel"));
        mesTypeLabel->setGeometry(QRect(40, 50, 111, 41));
        mesTypeComboBox = new QComboBox(frame);
        mesTypeComboBox->setObjectName(QStringLiteral("mesTypeComboBox"));
        mesTypeComboBox->setGeometry(QRect(170, 51, 231, 41));
        modifyLabel = new QLabel(frame);
        modifyLabel->setObjectName(QStringLiteral("modifyLabel"));
        modifyLabel->setGeometry(QRect(40, 160, 111, 41));
        modifyEdit = new QLineEdit(frame);
        modifyEdit->setObjectName(QStringLiteral("modifyEdit"));
        modifyEdit->setGeometry(QRect(170, 160, 231, 41));
        addBtn = new QPushButton(frame);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(40, 250, 101, 51));
        delBtn = new QPushButton(frame);
        delBtn->setObjectName(QStringLiteral("delBtn"));
        delBtn->setGeometry(QRect(200, 250, 101, 51));
        editBtn = new QPushButton(frame);
        editBtn->setObjectName(QStringLiteral("editBtn"));
        editBtn->setGeometry(QRect(350, 250, 101, 51));

        horizontalLayout->addWidget(frame);


        retranslateUi(lyEditMesType);

        QMetaObject::connectSlotsByName(lyEditMesType);
    } // setupUi

    void retranslateUi(QDialog *lyEditMesType)
    {
        lyEditMesType->setWindowTitle(QApplication::translate("lyEditMesType", "lyEditMesType", Q_NULLPTR));
        mesTypeLabel->setText(QApplication::translate("lyEditMesType", "\344\274\232\350\256\256\347\261\273\345\236\213", Q_NULLPTR));
        modifyLabel->setText(QApplication::translate("lyEditMesType", "\351\234\200\350\246\201\344\277\256\346\224\271", Q_NULLPTR));
        addBtn->setText(QApplication::translate("lyEditMesType", "\346\267\273\345\212\240\346\226\260\347\261\273\345\236\213", Q_NULLPTR));
        delBtn->setText(QApplication::translate("lyEditMesType", "\345\210\240\351\231\244\345\275\223\345\211\215\347\261\273\345\236\213", Q_NULLPTR));
        editBtn->setText(QApplication::translate("lyEditMesType", "\344\277\256\346\224\271\345\275\223\345\211\215\347\261\273\345\236\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class lyEditMesType: public Ui_lyEditMesType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYEDITMESTYPE_H
