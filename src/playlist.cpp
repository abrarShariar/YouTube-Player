/*
 * Playlist Code needs much improvement
 */
#include "playlist.h"
#include "ui_playlist.h"
#include<QDebug>
#include<QtSql>
#include<QSqlQuery>
#include<QMap>
#include<QString>
#include<QSignalMapper>


Playlist::Playlist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Playlist)
{
    ui->setupUi(this);

    //connect to database
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("playlistDB.db");
    QSqlQuery query;
    bool db_ok=db.open();
    if(db_ok){
        query.prepare("SELECT * FROM MyPlaylist");
        query.exec();
        int urlField=query.record().indexOf("url");
        int repeatField=query.record().indexOf("repeat");
        while(query.next()){
            QString url=query.value(urlField).toString();
            QString repeat=query.value(repeatField).toString();
            this->playlistMap[url]=repeat;
        }
    }

    //send playall url to webview (signal slot)

    QMapIterator<QString,QString>i(this->playlistMap);
    //strUrl="http://www.youtube.com/watch_videos?video_ids="+this->videoId;
    this->playAllUrl="http://www.youtube.com/watch_videos?video_ids=";

    QString videoId="";
    while(i.hasNext()){
        i.next();
        bool ok;
        int limit=i.value().toInt(&ok,10);
        QStringList list=i.key().split('=');
        for(int j=0;j<limit;j++){
            this->playAllUrl=this->playAllUrl+list[1]+",";
        }
    }
    //send playall url to webview (signal slot)
    /*signal slot handling
     * signal emits the event play all button click
     * slot to catch the playlist url and load in webengine view
     */
    //connect(this->ui->playButton,SIGNAL(clicked()),this,SLOT(setPlayUrl()));

    QSignalMapper* signalMapper=new QSignalMapper(this);
    connect(this->ui->playButton,SIGNAL(clicked()),signalMapper,SLOT(map()));

    signalMapper->setMapping(this->ui->playButton,this->playAllUrl);
    connect(signalMapper,SIGNAL(mapped(QString)),this->parentWidget(),SLOT(loadPlaylist(QString)));
}

Playlist::~Playlist()
{
    delete ui;
}

void Playlist::on_removeButton_clicked(){
    QSqlQuery query;
    query.prepare("DELETE FROM MyPlaylist");
    query.exec();
    this->playlistMap.clear();
}
void Playlist::on_playButton_clicked(){
    this->close();
}

void Playlist::setPlaylistUrl(){

}

