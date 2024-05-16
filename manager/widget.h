#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDomDocument>
#include "updatepassword.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QStandardItemModel;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    enum DateTimeType{Time, Date, DateTime};
    QString getDateTime(DateTimeType type);

private slots:
    //商品管理部分
    void on_manageBtn_clicked();

    void on_sellTypeComboBox_currentTextChanged(const QString &arg1);

    void on_sellBrandComboBox_currentTextChanged(const QString &arg1);

    void on_sellNumSpinBox_valueChanged(int arg1);

    void on_sellCancelBtn_clicked();

    void on_sellOkBtn_clicked();

    //销售统计部分
    void on_typeComboBox_currentTextChanged(const QString &arg1);

    void on_updateBtn_clicked();

    void on_chartBtn_clicked();

    //更改密码部分
    void on_passwordBtn_clicked();

private:
    Ui::Widget *ui;
    QDomDocument doc;
    QStandardItemModel * chartModel;

    //主要是xml的处理
    bool docRead();
    bool docWrite();
    void writeXml();
    void Create_DateElement_Content(QDomElement &date);
    void showDailyList();

    //主要是model/view的处理
    void createChartModelView();
    void insert_modeldata_for_display();
    UpdatepassWord * update;
};
#endif // WIDGET_H
