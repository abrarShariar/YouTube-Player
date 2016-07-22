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
    ~webview();


public slots:
    void on_playButton_clicked();
    void on_playlistButton_clicked();

private:
    Ui::webview *ui;

    QWebEngineView *view=new QWebEngineView(this);
};

#endif // WEBVIEW_H
