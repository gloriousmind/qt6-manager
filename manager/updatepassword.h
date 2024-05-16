#ifndef UPDATEPASSWORD_H
#define UPDATEPASSWORD_H

#include <QDialog>

namespace Ui {
class UpdatepassWord;
}

class UpdatepassWord : public QDialog
{
    Q_OBJECT

public:
    explicit UpdatepassWord(QWidget *parent = nullptr);
    ~UpdatepassWord();

private slots:
    void textChanged_oldPassword_check(const QString & text);

    void on_changePassword_clicked();

private:
    Ui::UpdatepassWord *ui;
};

#endif // UPDATEPASSWORD_H
