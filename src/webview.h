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
    QString getVideoID(QString);
    ~webview();


public slots:
    void on_playButton_clicked();
    void on_playlistButton_clicked();
    void on_addButton_clicked();
    void setupWebview(QString);

    void updateUrl();
private:
    Ui::webview *ui;
    QUrl viewUrl;

};

#endif // WEBVIEW_H
