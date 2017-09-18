/********************************************************************************
** Form generated from reading UI file 'testpipechild.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTPIPECHILD_H
#define UI_TESTPIPECHILD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestPipeChildClass
{
public:
    QWidget *centralWidget;
    QPushButton *m_sendBtn;
    QPushButton *m_receiveBtn;
    QTextEdit *m_sendText;
    QTextEdit *m_receiveText;

    void setupUi(QMainWindow *TestPipeChildClass)
    {
        if (TestPipeChildClass->objectName().isEmpty())
            TestPipeChildClass->setObjectName(QStringLiteral("TestPipeChildClass"));
        TestPipeChildClass->resize(600, 400);
        centralWidget = new QWidget(TestPipeChildClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        m_sendBtn = new QPushButton(centralWidget);
        m_sendBtn->setObjectName(QStringLiteral("m_sendBtn"));
        m_sendBtn->setGeometry(QRect(40, 80, 93, 28));
        m_receiveBtn = new QPushButton(centralWidget);
        m_receiveBtn->setObjectName(QStringLiteral("m_receiveBtn"));
        m_receiveBtn->setGeometry(QRect(40, 280, 93, 28));
        m_sendText = new QTextEdit(centralWidget);
        m_sendText->setObjectName(QStringLiteral("m_sendText"));
        m_sendText->setGeometry(QRect(200, 20, 311, 161));
        m_receiveText = new QTextEdit(centralWidget);
        m_receiveText->setObjectName(QStringLiteral("m_receiveText"));
        m_receiveText->setGeometry(QRect(200, 220, 311, 161));
        TestPipeChildClass->setCentralWidget(centralWidget);

        retranslateUi(TestPipeChildClass);

        QMetaObject::connectSlotsByName(TestPipeChildClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestPipeChildClass)
    {
        TestPipeChildClass->setWindowTitle(QApplication::translate("TestPipeChildClass", "TestPipeChild", 0));
        m_sendBtn->setText(QApplication::translate("TestPipeChildClass", "\345\217\221\351\200\201", 0));
        m_receiveBtn->setText(QApplication::translate("TestPipeChildClass", "\346\216\245\346\224\266", 0));
    } // retranslateUi

};

namespace Ui {
    class TestPipeChildClass: public Ui_TestPipeChildClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTPIPECHILD_H
