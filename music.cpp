#include "music.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>

Music::Music(std::string path, int numMusic){
    this->musicPath = path;

    MP3 mp3(path);
    mp3.get_inf();

    this->Album = mp3.tag.Album;
    this->Title = mp3.tag.Title;
    this->Year = mp3.tag.Year;
    this->Comment = mp3.tag.Comment;
    this->Artist = mp3.tag.Artist;

    this->lenght = mp3.get_len() / 60;

    this->imagePath = "C:/Users/Mahdi/Documents/first/music/img/" + this->Title + std::to_string(numMusic) + ".jpg";
    mp3.save_pic(this->imagePath);

    this->musicWidget = new QPushButton();
    this->musicWidget->resize(200, 55);
    this->musicWidget->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    this->musicWidget->setAttribute(Qt::WA_NoSystemBackground, true);
    this->musicWidget->setAttribute(Qt::WA_TranslucentBackground, true);
    this->musicWidget->setStyleSheet(QString::fromStdString("background-color: rgba(0, 0, 0, 0);"));

    this->imageLabel = new QLabel(this->musicWidget);
    this->imageLabel->resize(50, 50);
    this->imageLabel->setStyleSheet(QString::fromStdString("border-image: url(" + this->imagePath + ");border-radius: 25px;"));
    this->imageLabel->show();

    this->titleLabel = new QLabel(this->musicWidget);
    this->titleLabel->resize(150, 20);
    this->titleLabel->move(55, 0);
    this->titleLabel->setText(QString::fromStdString(this->Title));
    this->titleLabel->setStyleSheet(QString::fromStdString("color: #feff19;background-color: None;font-size:17px; font-family:Comic Sans MS;"));
    this->titleLabel->setAlignment(Qt::AlignLeft);
    this->titleLabel->show();

    this->artistLabel = new QLabel(this->musicWidget);
    this->artistLabel->resize(170, 20);
    this->artistLabel->move(55, 19);
    this->artistLabel->setText(QString::fromStdString(this->Artist));
    this->artistLabel->setStyleSheet(QString::fromStdString("color: #17fc00;background-color: None;font-size:13px; font-family:Comic Sans MS;"));
    this->artistLabel->setAlignment(Qt::AlignLeft);
    this->artistLabel->show();

    int temp1, temp2, temp3, temp4;
    temp1 = lenght / 10;
    temp2 = lenght / 1;
    temp3 = (int)(lenght * 10) % 10;
    temp4 = (int)(lenght * 100) % 10;

    std::string timeStr = "";
    if(temp1 != 0)
        timeStr = std::to_string(temp1);
    if(temp2 != 0)
        timeStr += std::to_string(temp2);
    timeStr += ":" + std::to_string(temp3) + std::to_string(temp4);


    this->timeLabel = new QLabel(this->musicWidget);
    this->timeLabel->resize(170, 20);
    this->timeLabel->move(55, 37);
    this->timeLabel->setText(QString::fromStdString(timeStr));
    this->timeLabel->setStyleSheet(QString::fromStdString("color: #ff84b8; background-color: None;font-size:10px; font-family:Comic Sans MS;"));
    this->timeLabel->setAlignment(Qt::AlignLeft);
    this->timeLabel->show();
}


void MainWindow::showMusic(){
    mciSendString((LPCWSTR)"open \"C:/Users/Mahdi/Documents/first/music/03.Darkside.mp3\" type mpegvideo alias mp3", NULL, 0, 0);
    mciSendString((LPCWSTR)"play mp3 wait", NULL, 0, NULL);

}





