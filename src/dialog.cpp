#include "dialog.h"
#include "ui_dialog.h"
#include<QUrl>
#include<QSpinBox>
#include<QDebug>
#include<QtSql>
#include<QSqlQuery>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->spinBox->setValue(10);

    //connect to sqlite
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("playlistDB.db");
    QSqlQuery query;
    bool db_ok=db.open();
    if(db_ok){
        query.exec("CREATE TABLE IF NOT EXISTS MyPlaylist (url TEXT,repeat INTEGER)");
    }
}
Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::getUrl(){
   return this->playlistUrl;
}

void Dialog::setUrl(QUrl url){
    this->playlistUrl=url.toString();
    ui->lineEdit->setText(this->playlistUrl);
}

void Dialog::setRepeatTimes(int num){
    this->repeatTimes=num;
}

int Dialog::getRepeatTimes(){
    return this->repeatTimes;
}

void Dialog::on_okButton_clicked(){
    int num=ui->spinBox->value();
    this->setRepeatTimes(num);


/*
    query.prepare("SELECT * FROM MyPlaylist");
    query.exec();
    while(query.next()){
        qDebug()<<query.value(0).toString()<<endl;
    }
    */
}
