#include "webview.h"
#include "dialog.h"
#include "playlist.h"
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
#include<QMap>

QScrollArea *sArea;
int repeatMe=10;

webview::webview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::webview)
{
    /* Construct the initial window
     */
        QIcon btnPlay(":/icon/play.png");
        QIcon btnAdd(":/icon/add.png");
        QIcon btnHome(":/icon/youtube_icon.png");
        QIcon btnPlaylist(":/icon/playlist.png");
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
        ui->playlistButton->setIcon(btnPlaylist);
        ui->homeButton->setIcon(btnHome);
        ui->homeButton->setIconSize(QSize(ui->homeButton->width(),ui->homeButton->height()-10));
        ui->playButton->setIcon(btnPlay);
        ui->playButton->setIconSize(QSize(ui->playButton->width(),ui->playButton->height()-10));
        ui->addButton->setIcon(btnAdd);
        ui->addButton->setIconSize(QSize(ui->addButton->width(),ui->addButton->height()-10));

        this->setWindowFlags(this->windowFlags() | Qt::WindowMinimizeButtonHint);
}

webview::~webview()
{
    delete ui;
}

void webview::updateUrl(){
    QString strUrl=this->view->url().toString();
    int found=strUrl.indexOf("=",0);
    if(found!=-1){
        this->videoId=this->getVideoID(strUrl);
        //read http://lifehacker.com/create-a-youtube-playlist-without-an-account-with-this-1688862486
        strUrl="http://www.youtube.com/watch_videos?video_ids="+this->videoId;
        for(int i=0;i<repeatMe;i++){
            strUrl=strUrl+","+this->videoId;
        }
        this->loopUrl=strUrl;
        ui->plainTextEdit->setPlainText("http://www.youtube.com/watch?v="+this->videoId);
    }
}

QString webview::getVideoID(QString strUrl){
    QStringList list;
    list=strUrl.split("=");
    return list[1];
}

void webview::on_addButton_clicked(){
  Dialog *repeatBox=new Dialog(this);
  repeatBox->setUrl(ui->plainTextEdit->toPlainText());
  repeatBox->setWindowTitle("Add to playlist");
  repeatBox->show();

}

void webview::on_playButton_clicked(){        
    //error handling
    QString text=ui->plainTextEdit->toPlainText();
    if(text=="" || text==" "){
        ui->plainTextEdit->appendPlainText("Please Choose A Valid YouTube Video...");
       return;
    }else{
        //get repeat times input
        this->view->setUrl(QUrl(this->loopUrl));
        ui->plainTextEdit->setPlainText("http://www.youtube.com/watch?v="+this->videoId);

     }
}

void webview::setupWebview(QString url){
    this->viewUrl=url;
    this->view->load(this->viewUrl);
    this->view->resize(sArea->width(),sArea->height()+10);
    sArea->hide();
    this->view->show();
}

void webview::on_playlistButton_clicked(){
    Playlist *myPlaylist=new Playlist(this);
    myPlaylist->setWindowTitle("My Playlist");

    int X=20,Y=40,width,height=16;
    int rX=380,rY=40,rWidth=20,rHeight=16;
    QMapIterator<QString,QString>i(myPlaylist->playlistMap);
    while(i.hasNext()){
        i.next();
        QLabel *urlLabel=new QLabel(myPlaylist);
        width=i.key().length()+300;
        urlLabel->setGeometry(X,Y,width,height);
        urlLabel->setText(i.key());
        urlLabel->show();

        QLabel *repeatLabel=new QLabel(myPlaylist);
        repeatLabel->setGeometry(rX,rY,rWidth,rHeight);
        repeatLabel->setText(i.value());
        repeatLabel->show();
        Y+=25;
        rY+=25;
    }
    myPlaylist->show();
}

void webview::on_homeButton_clicked(){
    this->view->setUrl(QUrl("http://www.youtube.com/"));
    ui->plainTextEdit->setPlainText("http://www.youtube.com/");
}

void webview::loadPlaylist(QString url){
    //qDebug()<<url<<endl;
    this->view->setUrl(QUrl(url));
}
