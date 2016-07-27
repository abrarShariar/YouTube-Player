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
    QString videoId;
    QString strUrl=this->view->url().toString();
    ui->plainTextEdit->setPlainText(strUrl);
    int found=strUrl.indexOf("=",0);
    if(found!=-1){
        videoId=this->getVideoID(strUrl);
        strUrl="http://www.youtube.com/embed/v/"+videoId+"?version=3&loop=1&playlist="+videoId;
        this->loopUrl=strUrl;
        //-------FIX ASAP------
        //this->view->load(QUrl(strUrl));
        //qDebug()<<this->viewUrl<<endl;
    }
}

QString webview::getVideoID(QString strUrl){
    QStringList list;
    list=strUrl.split("=");
    return list[1];
}

void webview::on_addButton_clicked(){
   QUrl currentUrl=this->view->url();
}

void webview::on_playButton_clicked(){    
    /* read url link
     * open link in QWebEngineView
     */
    //get URL
    /*
     */
    /*
    QString text=ui->plainTextEdit->toPlainText();
    if(text=="" || text==" "){
        ui->plainTextEdit->appendPlainText("Please Enter A Valid URL...");
       return;
    }else{
        this->view->(this->viewUrl);
        this->view->show();
        qDebug()<<this->view->url()<<endl;
    }
   */
    qDebug()<<this->loopUrl<<endl;
    this->view->setUrl(QUrl(this->loopUrl));
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
