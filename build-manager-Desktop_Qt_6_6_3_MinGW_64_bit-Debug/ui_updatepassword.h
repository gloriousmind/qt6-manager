/********************************************************************************
** Form generated from reading UI file 'updatepassword.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEPASSWORD_H
#define UI_UPDATEPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UpdatepassWord
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *OldPwdlineedit;
    QLineEdit *NewPwdlineedit;
    QLineEdit *NewPwdCofirmlineedit;
    QPushButton *changePassword;

    void setupUi(QDialog *UpdatepassWord)
    {
        if (UpdatepassWord->objectName().isEmpty())
            UpdatepassWord->setObjectName("UpdatepassWord");
        UpdatepassWord->resize(704, 490);
        label = new QLabel(UpdatepassWord);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 80, 53, 16));
        label_2 = new QLabel(UpdatepassWord);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(105, 169, 61, 21));
        label_3 = new QLabel(UpdatepassWord);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(104, 240, 91, 20));
        OldPwdlineedit = new QLineEdit(UpdatepassWord);
        OldPwdlineedit->setObjectName("OldPwdlineedit");
        OldPwdlineedit->setGeometry(QRect(200, 80, 163, 21));
        OldPwdlineedit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        NewPwdlineedit = new QLineEdit(UpdatepassWord);
        NewPwdlineedit->setObjectName("NewPwdlineedit");
        NewPwdlineedit->setGeometry(QRect(200, 170, 171, 21));
        NewPwdlineedit->setEchoMode(QLineEdit::Password);
        NewPwdCofirmlineedit = new QLineEdit(UpdatepassWord);
        NewPwdCofirmlineedit->setObjectName("NewPwdCofirmlineedit");
        NewPwdCofirmlineedit->setGeometry(QRect(201, 240, 171, 21));
        NewPwdCofirmlineedit->setEchoMode(QLineEdit::Password);
        changePassword = new QPushButton(UpdatepassWord);
        changePassword->setObjectName("changePassword");
        changePassword->setGeometry(QRect(430, 240, 93, 28));

        retranslateUi(UpdatepassWord);

        QMetaObject::connectSlotsByName(UpdatepassWord);
    } // setupUi

    void retranslateUi(QDialog *UpdatepassWord)
    {
        UpdatepassWord->setWindowTitle(QCoreApplication::translate("UpdatepassWord", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("UpdatepassWord", "\346\227\247\345\257\206\347\240\201:", nullptr));
        label_2->setText(QCoreApplication::translate("UpdatepassWord", "\346\226\260\345\257\206\347\240\201:", nullptr));
        label_3->setText(QCoreApplication::translate("UpdatepassWord", "\346\226\260\345\257\206\347\240\201\347\241\256\350\256\244\357\274\232", nullptr));
        changePassword->setText(QCoreApplication::translate("UpdatepassWord", "\346\233\264\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UpdatepassWord: public Ui_UpdatepassWord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEPASSWORD_H
