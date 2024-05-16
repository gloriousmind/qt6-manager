#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QFile>
#include <QXmlStreamWriter>
#include <QSqlQuery>
#include <QDebug>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setHostName("jieLinux");
    db.setDatabaseName("data.db");
    db.setUserName("jie");
    if (!db.open())
    {
        //提示错误
        return false;
    }

    QSqlQuery query;

    //创建分类表
    if (query.exec("create table type(id varchar primary key, name varchar)"))
        query.exec("insert into type values('0', '请选择类型')");
    query.exec("insert into type values('01', '电视')");
    query.exec("insert into type values('02', '空调')");

    // 创建品牌表
    query.exec("create table brand(id varchar primary key, name varchar, "
               "type varchar, price int, sum int, sell int, last int)");
    query.exec("insert into brand values('01', '海信', '电视', 3699, 50, 0, 40)");
    query.exec("insert into brand values('02', '创维', '电视', 3499, 20, 0, 15)");
    query.exec("insert into brand values('03', '海尔', '电视', 4199, 80, 0, 40)");
    query.exec("insert into brand values('04', '王牌', '电视', 3999, 40, 0, 30)");
    query.exec("insert into brand values('05', '海尔', '空调', 2899, 60, 0, 50)");
    query.exec("insert into brand values('06', '格力', '空调', 2799, 70, 0, 50)");

    //创建密码表
    if (!query.exec("select pwd from password"))
    {
        query.exec("create table password(pwd varchar primary key)");
        query.exec("insert into password values('12345')");
    }

    return true;
}

static bool createXml()
{
    QFile file("data.xml");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return false;
    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("日销售记录");
    stream.writeEndElement();
    stream.writeEndDocument();
    file.close();
    return true;
}
#endif // CONNECTION_H
