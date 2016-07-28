#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QDialog>
#include<QMap>

namespace Ui {
class Playlist;
}

class Playlist : public QDialog
{
    Q_OBJECT

public:
    explicit Playlist(QWidget *parent = 0);
    ~Playlist();
    QMap <QString,QString>playlistMap;

private:
    Ui::Playlist *ui;
};

#endif // PLAYLIST_H
