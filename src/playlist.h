#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QDialog>

namespace Ui {
class Playlist;
}

class Playlist : public QDialog
{
    Q_OBJECT

public:
    explicit Playlist(QWidget *parent = 0);
    ~Playlist();

private:
    Ui::Playlist *ui;
};

#endif // PLAYLIST_H
