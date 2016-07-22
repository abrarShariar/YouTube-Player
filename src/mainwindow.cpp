/*
 * CAUTION
 * THIS FILE CONTAINS DEPRECATED CODE FOR THIS PROJECT
 * CODE WILL BE REMOVED SOON
 * NEW DESTINATION
 * webview.cpp
 */

/*

#include "mainwindow.h"
#include "webview.h"
#include "ui_mainwindow.h"
#include "ui_webview.h"

#include<QWebEngineView>
#include<QWidget>
#include<QHBoxLayout>
#include<QScrollArea>
#include<QLabel>
#include<QFont>
#include<QDebug>



QScrollArea *scrollArea;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

//Construct the initial window
    //initial text display
    QFont font;
    font.setPointSize(15);
    QLabel *label=new QLabel;
    label->setFont(font);
    label->setText("Paste the YouTube URL below and PLAY ON !!");
    label->setAlignment(Qt::AlignCenter);

    //scroll area
    scrollArea=new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->resize(this->width()+50,this->height()-120);
    scrollArea->setWidget(label);

    //set horizontal layout
    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(label);
    scrollArea->setLayout(layout);
    scrollArea->show();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_playButton_clicked(){
    qDebug()<<ui->plainTextEdit->toPlainText()<<endl;

    QWebEngineView *view=new QWebEngineView;
    view->load(QUrl(ui->plainTextEdit->toPlainText()));
    view->resize(1000,500);

    //webBox->setWindowFlags(webBox->windowFlags());
    //webBox->show();

}

bool MainWindow::on_playlistButton_clicked(){
    qDebug()<<"Playlist Button Clicked"<<endl;
    return true;
}
*/
