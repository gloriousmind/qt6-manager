#include "updatepassword.h"
#include "ui_updatepassword.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>

UpdatepassWord::UpdatepassWord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdatepassWord)
{
    ui->setupUi(this);
    ui->OldPwdlineedit->setFocus();
    ui->NewPwdlineedit->setEnabled(false);
    ui->NewPwdCofirmlineedit->setEnabled(false);
    connect(ui->OldPwdlineedit, &QLineEdit::textChanged, this, &UpdatepassWord::textChanged_oldPassword_check);
}

UpdatepassWord::~UpdatepassWord()
{
    delete ui;
}

void UpdatepassWord::textChanged_oldPassword_check(const QString &text)
{
    QSqlQuery query;
    query.exec("select pwd from password");
    query.next();
    if (query.value(0).toString() == text)
    {
        ui->NewPwdlineedit->setEnabled(true);
        ui->NewPwdCofirmlineedit->setEnabled(true);
        ui->NewPwdlineedit->setFocus();
    }
}

void UpdatepassWord::on_changePassword_clicked()
{
    if (!ui->NewPwdlineedit->text().isEmpty() && !ui->NewPwdCofirmlineedit->text().isEmpty())
    {
        if (ui->NewPwdlineedit->text() == ui->NewPwdCofirmlineedit->text())
        {
            QSqlDatabase::database().transaction();
            QSqlQuery query;
            if (query.exec(QString("update password set pwd = '%1'").arg(ui->NewPwdlineedit->text())))
            {
                QSqlDatabase::database().commit();
                QMessageBox::information(this, "提示信息", "密码修改成功!");
            }
            else
                QSqlDatabase::database().rollback();

        }
        else
            QMessageBox::warning(this, "提示信息", "密码不一致");
    }
}
