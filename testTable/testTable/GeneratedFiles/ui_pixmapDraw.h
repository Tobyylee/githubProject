/********************************************************************************
** Form generated from reading UI file 'pixmapDraw.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIXMAPDRAW_H
#define UI_PIXMAPDRAW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pixmapDraw
{
public:

    void setupUi(QWidget *pixmapDraw)
    {
        if (pixmapDraw->objectName().isEmpty())
            pixmapDraw->setObjectName(QStringLiteral("pixmapDraw"));
        pixmapDraw->resize(400, 300);

        retranslateUi(pixmapDraw);

        QMetaObject::connectSlotsByName(pixmapDraw);
    } // setupUi

    void retranslateUi(QWidget *pixmapDraw)
    {
        pixmapDraw->setWindowTitle(QApplication::translate("pixmapDraw", "pixmapDraw", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pixmapDraw: public Ui_pixmapDraw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIXMAPDRAW_H
