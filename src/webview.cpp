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
        //label->setStyleSheet("QLabel { color : #167AC6; }");
        label->setAlignment(Qt::AlignCenter);

        //scroll area
        sArea=new QScrollArea(this);

        sArea->setBackgroundRole(QPalette::Dark);
        sArea->resize(this->width()+50,this->height()-100);
        sArea->setWidget(label);

        //set horizontal layout
        QHBoxLayout *layout=new QHBoxLayout;
        layout->addWidget(label);
        sArea->setLayout(layout);
        sArea->show();

        this->setupWebview("http://www.youtube.com");
        connect(this->view,SIGNAL(urlChanged(QUrl)),this,SLOT(updateUrl()));


        ui->setupUi(this);
        ui->playButton->setIcon(btnPlay);
        ui->playButton->setIconSize(QSize(ui->playButton->width(),ui->playButton->height()-10));
        ui->addButton->setIcon(btnAdd);
        ui->addButton->setIconSize(QSize(ui->addButton->width(),ui->addButton->height()-10));
}

webview::~webview()
{
    delete ui;
}

void webview::updateUrl(){
    //qDebug()<<"webview change"<<endl;
    QString str=this->view->url().toString();
    ui->plainTextEdit->setPlainText(str);

}

QString webview::getVideoID(QString strUrl){
    QStringList list;
    list=strUrl.split("=");
    return list[1];
}

void webview::on_addButton_clicked(){
   QUrl currentUrl=this->view->url();

   //qDebug()<<currentUrl<<endl;
   //qDebug()<<getVideoID(currentUrl)<<endl;
}

void webview::on_playButton_clicked(){    
    /* read url link
     * open link in QWebEngineView
     */
    //get URL

//    if(text=="" || text==" "){
//        ui->plainTextEdit->appendPlainText("Please Enter A Valid URL...");
//       return;
//  }

    //get video id
    //QString url=this->getVideoID()
    //QString url="https://www.youtube.com/embed/v="+list[1]+"?autoplay=1&loop=1";

    //this->setupWebview(url);
    //this->view->show();
}

void webview::setupWebview(QString url){
    this->viewUrl=url;
    this->view->load(this->viewUrl);
    this->view->resize(sArea->width(),sArea->height()+10);
    sArea->hide();
    this->view->show();
}

void webview::on_playlistButton_clicked(){
    qDebug()<<"PLAYLIST"<<endl;
}
