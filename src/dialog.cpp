#include "dialog.h"
#include "ui_dialog.h"

#include<QUrl>
#include<QSpinBox>
#include<QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->spinBox->setValue(10);
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

}
