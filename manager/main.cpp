#include "widget.h"
#include "connection.h"
#include <QApplication>
#include <logindialog.h>
#include <QTextCodec>
#include <QtMath>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!createConnection() || !createXml())
        return 0;
    Widget w;
    LoginDialog dlg;
    if (dlg.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else
        return 0;
}
