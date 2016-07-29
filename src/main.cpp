/*
 * A customizable YouTube-Player
 * UNDER DEV
 * BEWARE : A lot of messey and hacky code
 */

#include "webview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QMainWindow replaced with QWidget
    webview w;
    w.setWindowTitle("YouTube - Player");
    w.show();
    return a.exec();
}
