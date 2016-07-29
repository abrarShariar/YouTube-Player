/*
 * main window here
 */

#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QWidget>
#include <QWebEngineView>

namespace Ui {
class webview;
}

class webview : public QWidget
{
    Q_OBJECT

public:
    explicit webview(QWidget *parent = 0);
    QWebEngineView *view=new QWebEngineView(this);
    bool initialLoad=true;
    QString getVideoID(QString);
    QString loopUrl;
    QString videoId="";

   // void loadPlaylist();
    ~webview();


public slots:
    void on_homeButton_clicked();
    void on_playButton_clicked();
    void on_playlistButton_clicked();
    void on_addButton_clicked();
    void setupWebview(QString);
    void updateUrl();
    void loadPlaylist(QString);

private:
    QUrl viewUrl;
    Ui::webview *ui;
};

#endif // WEBVIEW_H
