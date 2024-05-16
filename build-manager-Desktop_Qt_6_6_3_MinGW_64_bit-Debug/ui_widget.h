/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *managePage;
    QLabel *label;
    QToolBox *toolBox;
    QWidget *page;
    QLabel *label_2;
    QComboBox *sellTypeComboBox;
    QLabel *label_3;
    QComboBox *sellBrandComboBox;
    QLabel *label_4;
    QLineEdit *sellPriceLineEdit;
    QLabel *label_5;
    QSpinBox *sellNumSpinBox;
    QLabel *label_6;
    QLabel *sellRemainingNumLabel;
    QLabel *label_8;
    QLineEdit *sellSumLineEdit;
    QLabel *label_9;
    QPushButton *sellOkBtn;
    QPushButton *sellCancelBtn;
    QWidget *page_3;
    QListWidget *dailyList;
    QWidget *chartPage;
    QPushButton *updateBtn;
    QComboBox *typeComboBox;
    QLabel *label_7;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *manageBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *chartBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *passwordBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(750, 500);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(20, 60, 700, 410));
        managePage = new QWidget();
        managePage->setObjectName("managePage");
        label = new QLabel(managePage);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 10, 700, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setFrameShape(QFrame::StyledPanel);
        label->setAlignment(Qt::AlignCenter);
        toolBox = new QToolBox(managePage);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(0, 90, 321, 321));
        toolBox->setLayoutDirection(Qt::LeftToRight);
        toolBox->setFrameShape(QFrame::WinPanel);
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 317, 249));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 20, 72, 15));
        sellTypeComboBox = new QComboBox(page);
        sellTypeComboBox->setObjectName("sellTypeComboBox");
        sellTypeComboBox->setGeometry(QRect(60, 20, 87, 22));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 50, 72, 15));
        sellBrandComboBox = new QComboBox(page);
        sellBrandComboBox->setObjectName("sellBrandComboBox");
        sellBrandComboBox->setGeometry(QRect(60, 50, 87, 22));
        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 80, 72, 15));
        sellPriceLineEdit = new QLineEdit(page);
        sellPriceLineEdit->setObjectName("sellPriceLineEdit");
        sellPriceLineEdit->setGeometry(QRect(60, 80, 113, 21));
        label_5 = new QLabel(page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 110, 41, 16));
        sellNumSpinBox = new QSpinBox(page);
        sellNumSpinBox->setObjectName("sellNumSpinBox");
        sellNumSpinBox->setGeometry(QRect(60, 110, 46, 22));
        label_6 = new QLabel(page);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(190, 80, 21, 16));
        sellRemainingNumLabel = new QLabel(page);
        sellRemainingNumLabel->setObjectName("sellRemainingNumLabel");
        sellRemainingNumLabel->setGeometry(QRect(120, 110, 111, 16));
        label_8 = new QLabel(page);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 150, 41, 16));
        sellSumLineEdit = new QLineEdit(page);
        sellSumLineEdit->setObjectName("sellSumLineEdit");
        sellSumLineEdit->setGeometry(QRect(60, 150, 113, 21));
        label_9 = new QLabel(page);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(200, 150, 21, 16));
        sellOkBtn = new QPushButton(page);
        sellOkBtn->setObjectName("sellOkBtn");
        sellOkBtn->setGeometry(QRect(10, 200, 93, 28));
        sellCancelBtn = new QPushButton(page);
        sellCancelBtn->setObjectName("sellCancelBtn");
        sellCancelBtn->setGeometry(QRect(150, 200, 93, 28));
        toolBox->addItem(page, QString::fromUtf8("\345\207\272\345\224\256\345\225\206\345\223\201"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        page_3->setGeometry(QRect(0, 0, 317, 249));
        toolBox->addItem(page_3, QString::fromUtf8("Page 2"));
        dailyList = new QListWidget(managePage);
        dailyList->setObjectName("dailyList");
        dailyList->setGeometry(QRect(340, 90, 341, 321));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dailyList->sizePolicy().hasHeightForWidth());
        dailyList->setSizePolicy(sizePolicy);
        stackedWidget->addWidget(managePage);
        chartPage = new QWidget();
        chartPage->setObjectName("chartPage");
        updateBtn = new QPushButton(chartPage);
        updateBtn->setObjectName("updateBtn");
        updateBtn->setGeometry(QRect(120, 40, 93, 28));
        typeComboBox = new QComboBox(chartPage);
        typeComboBox->setObjectName("typeComboBox");
        typeComboBox->setGeometry(QRect(20, 40, 87, 22));
        label_7 = new QLabel(chartPage);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 10, 661, 21));
        label_7->setFrameShape(QFrame::Panel);
        label_7->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(chartPage);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 10, 661, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        manageBtn = new QPushButton(layoutWidget);
        manageBtn->setObjectName("manageBtn");

        horizontalLayout->addWidget(manageBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        chartBtn = new QPushButton(layoutWidget);
        chartBtn->setObjectName("chartBtn");

        horizontalLayout->addWidget(chartBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        passwordBtn = new QPushButton(layoutWidget);
        passwordBtn->setObjectName("passwordBtn");

        horizontalLayout->addWidget(passwordBtn);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(1);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\225\206\345\223\201\347\256\241\347\220\206", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\261\273\345\236\213\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\223\201\347\211\214\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\215\225\344\273\267\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\346\225\260\351\207\217\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\345\205\203", nullptr));
        sellRemainingNumLabel->setText(QCoreApplication::translate("Widget", "\345\211\251\344\275\231\346\225\260\351\207\217\357\274\232000", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\351\207\221\351\242\235\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "\345\205\203", nullptr));
        sellOkBtn->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        sellCancelBtn->setText(QCoreApplication::translate("Widget", "\345\217\226\346\266\210", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("Widget", "\345\207\272\345\224\256\345\225\206\345\223\201", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("Widget", "Page 2", nullptr));
        updateBtn->setText(QCoreApplication::translate("Widget", "\346\233\264\346\226\260\346\230\276\347\244\272", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\351\224\200\345\224\256\347\273\237\350\256\241", nullptr));
        manageBtn->setText(QCoreApplication::translate("Widget", "\345\225\206\345\223\201\347\256\241\347\220\206", nullptr));
        chartBtn->setText(QCoreApplication::translate("Widget", "\351\224\200\345\224\256\347\273\237\350\256\241", nullptr));
        passwordBtn->setText(QCoreApplication::translate("Widget", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
