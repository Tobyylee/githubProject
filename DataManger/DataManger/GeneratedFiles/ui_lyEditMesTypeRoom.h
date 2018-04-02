/********************************************************************************
** Form generated from reading UI file 'lyEditMesTypeRoom.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYEDITMESTYPEROOM_H
#define UI_LYEDITMESTYPEROOM_H

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

class Ui_lyEditMesTypeRoom
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QLabel *meetSiteNameLabel;
    QComboBox *meetSiteComboBox;
    QLabel *modifyMeetNameLabel;
    QLineEdit *modifyMeetSiteEdit;
    QPushButton *addBtn;
    QPushButton *delBtn;
    QPushButton *editBtn;

    void setupUi(QDialog *lyEditMesTypeRoom)
    {
        if (lyEditMesTypeRoom->objectName().isEmpty())
            lyEditMesTypeRoom->setObjectName(QStringLiteral("lyEditMesTypeRoom"));
        lyEditMesTypeRoom->resize(464, 305);
        QIcon icon;
        icon.addFile(QStringLiteral(":/DataManger/Data/image/calendar.png"), QSize(), QIcon::Normal, QIcon::Off);
        lyEditMesTypeRoom->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(lyEditMesTypeRoom);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(lyEditMesTypeRoom);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        meetSiteNameLabel = new QLabel(frame);
        meetSiteNameLabel->setObjectName(QStringLiteral("meetSiteNameLabel"));
        meetSiteNameLabel->setGeometry(QRect(10, 40, 151, 41));
        meetSiteComboBox = new QComboBox(frame);
        meetSiteComboBox->setObjectName(QStringLiteral("meetSiteComboBox"));
        meetSiteComboBox->setGeometry(QRect(180, 40, 221, 41));
        modifyMeetNameLabel = new QLabel(frame);
        modifyMeetNameLabel->setObjectName(QStringLiteral("modifyMeetNameLabel"));
        modifyMeetNameLabel->setGeometry(QRect(10, 120, 151, 41));
        modifyMeetSiteEdit = new QLineEdit(frame);
        modifyMeetSiteEdit->setObjectName(QStringLiteral("modifyMeetSiteEdit"));
        modifyMeetSiteEdit->setGeometry(QRect(180, 120, 221, 41));
        addBtn = new QPushButton(frame);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(10, 200, 131, 41));
        delBtn = new QPushButton(frame);
        delBtn->setObjectName(QStringLiteral("delBtn"));
        delBtn->setGeometry(QRect(160, 200, 131, 41));
        editBtn = new QPushButton(frame);
        editBtn->setObjectName(QStringLiteral("editBtn"));
        editBtn->setGeometry(QRect(310, 200, 131, 41));

        horizontalLayout->addWidget(frame);


        retranslateUi(lyEditMesTypeRoom);

        QMetaObject::connectSlotsByName(lyEditMesTypeRoom);
    } // setupUi

    void retranslateUi(QDialog *lyEditMesTypeRoom)
    {
        lyEditMesTypeRoom->setWindowTitle(QApplication::translate("lyEditMesTypeRoom", "lyEditMesTypeRoom", Q_NULLPTR));
        meetSiteNameLabel->setText(QApplication::translate("lyEditMesTypeRoom", "\347\216\260\346\234\211\344\274\232\350\256\256\345\234\260\347\202\271\345\220\215\347\247\260", Q_NULLPTR));
        modifyMeetNameLabel->setText(QApplication::translate("lyEditMesTypeRoom", "\351\234\200\344\277\256\346\224\271\347\232\204\344\274\232\350\256\256\345\234\260\347\202\271", Q_NULLPTR));
        addBtn->setText(QApplication::translate("lyEditMesTypeRoom", "\346\267\273\345\212\240\346\226\260\344\274\232\350\256\256\345\234\260\347\202\271", Q_NULLPTR));
        delBtn->setText(QApplication::translate("lyEditMesTypeRoom", "\345\210\240\351\231\244\344\274\232\350\256\256\345\234\260\347\202\271", Q_NULLPTR));
        editBtn->setText(QApplication::translate("lyEditMesTypeRoom", "\344\277\256\346\224\271\344\274\232\350\256\256\345\234\260\347\202\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class lyEditMesTypeRoom: public Ui_lyEditMesTypeRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYEDITMESTYPEROOM_H
