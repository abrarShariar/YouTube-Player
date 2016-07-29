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

    QString playAllUrl;
    QMap<QString,QString>playlistMap;

public slots:
    void on_removeButton_clicked();
    void on_playButton_clicked();
    void setPlaylistUrl();

private:
    Ui::Playlist *ui;
};

#endif // PLAYLIST_H
