/********************************************************************************
** Form generated from reading UI file 'exam.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAM_H
#define UI_EXAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_examClass
{
public:

    void setupUi(QWidget *examClass)
    {
        if (examClass->objectName().isEmpty())
            examClass->setObjectName(QStringLiteral("examClass"));
        examClass->resize(600, 400);

        retranslateUi(examClass);

        QMetaObject::connectSlotsByName(examClass);
    } // setupUi

    void retranslateUi(QWidget *examClass)
    {
        examClass->setWindowTitle(QApplication::translate("examClass", "exam", 0));
    } // retranslateUi

};

namespace Ui {
    class examClass: public Ui_examClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAM_H
