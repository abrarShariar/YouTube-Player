#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QUrl>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    QString playlistUrl;
    int getRepeatTimes();
    void setRepeatTimes(int);
    void setUrl(QUrl);
    QString getUrl();

public slots:
    void on_okButton_clicked();

private:
    Ui::Dialog *ui;
    int repeatTimes=10;
};

#endif // DIALOG_H
