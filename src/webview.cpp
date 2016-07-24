#include "webview.h"
#include "ui_webview.h"

#include<QWebEngineView>
#include<QWidget>
#include<QHBoxLayout>
#include<QScrollArea>
#include<QLabel>
#include<QFont>
#include<QDebug>
#include<QPushButton>
#include<QIcon>

QScrollArea *sArea;

webview::webview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::webview)
{
    /* Construct the initial window
     */


        QIcon btnPlay(":/icon/play.png");
        QIcon btnAdd(":/icon/add.png");
        //initial text display
        QFont font;
        font.setPointSize(15);
        QLabel *label=new QLabel;
        label->setFont(font);
        label->setText("Paste the YouTube URL below and PLAY ON !!");
        label->setAlignment(Qt::AlignCenter);

        //scroll area
        sArea=new QScrollArea(this);

        sArea->setBackgroundRole(QPalette::Dark);
        sArea->resize(this->width()+50,this->height()-100);
        sArea->setWidget(label);

        //this works
        //QPushButton *btn=new QPushButton(this);
        //btn->setIcon(QIcon(":/icon/play.png"));

        //set horizontal layout
        QHBoxLayout *layout=new QHBoxLayout;
        layout->addWidget(label);
        sArea->setLayout(layout);
        sArea->show();

        qDebug()<<this->view->url()<<endl;

        ui->setupUi(this);
        ui->playButton->setIcon(btnPlay);
        ui->playButton->setIconSize(QSize(ui->playButton->width(),ui->playButton->height()-10));
        ui->playButton_2->setIcon(btnAdd);
        ui->playButton_2->setIconSize(QSize(ui->playButton_2->width(),ui->playButton_2->height()-10));

}

webview::~webview()
{
    delete ui;
}

void webview::on_playButton_clicked(){
    //qDebug()<<ui->plainTextEdit->toPlainText()<<endl;

    /* read url link
     * open link in QWebEngineView
     */


    //view=new QWebEngineView(this);

    QString text=ui->plainTextEdit->toPlainText();
    if(text=="" || text==" "){
        ui->plainTextEdit->appendPlainText("Please Enter A Valid URL...");
        return;
    }
    this->view->load(QUrl(ui->plainTextEdit->toPlainText()));
    this->view->resize(sArea->width(),sArea->height()+10);
    sArea->hide();
    this->view->show();

    //qDebug()<<this->view-><<endl;

}

void webview::on_playlistButton_clicked(){
    qDebug()<<"PLAYLIST"<<endl;

}
