#include "playlist.h"
#include "ui_playlist.h"

#include<QDebug>
#include<QtSql>
#include<QSqlQuery>


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

            qDebug()<<url<<endl;
            qDebug()<<repeat<<endl;
        }
    }
}

Playlist::~Playlist()
{
    delete ui;
}
