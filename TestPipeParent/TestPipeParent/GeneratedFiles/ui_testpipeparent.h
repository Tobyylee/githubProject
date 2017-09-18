/********************************************************************************
** Form generated from reading UI file 'testpipeparent.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTPIPEPARENT_H
#define UI_TESTPIPEPARENT_H

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

class Ui_TestPipeParentClass
{
public:
    QWidget *centralWidget;
    QPushButton *m_sendBtn;
    QTextEdit *m_sendText;
    QPushButton *m_receiveBtn;
    QTextEdit *m_receiveText;

    void setupUi(QMainWindow *TestPipeParentClass)
    {
        if (TestPipeParentClass->objectName().isEmpty())
            TestPipeParentClass->setObjectName(QStringLiteral("TestPipeParentClass"));
        TestPipeParentClass->resize(600, 400);
        centralWidget = new QWidget(TestPipeParentClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        m_sendBtn = new QPushButton(centralWidget);
        m_sendBtn->setObjectName(QStringLiteral("m_sendBtn"));
        m_sendBtn->setGeometry(QRect(40, 80, 93, 28));
        m_sendText = new QTextEdit(centralWidget);
        m_sendText->setObjectName(QStringLiteral("m_sendText"));
        m_sendText->setGeometry(QRect(200, 40, 301, 141));
        m_receiveBtn = new QPushButton(centralWidget);
        m_receiveBtn->setObjectName(QStringLiteral("m_receiveBtn"));
        m_receiveBtn->setGeometry(QRect(40, 290, 93, 28));
        m_receiveText = new QTextEdit(centralWidget);
        m_receiveText->setObjectName(QStringLiteral("m_receiveText"));
        m_receiveText->setGeometry(QRect(200, 230, 301, 141));
        TestPipeParentClass->setCentralWidget(centralWidget);

        retranslateUi(TestPipeParentClass);

        QMetaObject::connectSlotsByName(TestPipeParentClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestPipeParentClass)
    {
        TestPipeParentClass->setWindowTitle(QApplication::translate("TestPipeParentClass", "TestPipeParent", 0));
        m_sendBtn->setText(QApplication::translate("TestPipeParentClass", "\345\217\221\351\200\201", 0));
        m_receiveBtn->setText(QApplication::translate("TestPipeParentClass", "\346\216\245\346\224\266", 0));
    } // retranslateUi

};

namespace Ui {
    class TestPipeParentClass: public Ui_TestPipeParentClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTPIPEPARENT_H
