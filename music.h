#ifndef MUSIC_H
#define MUSIC_H

#include "mainwindow.h"

#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QLabel>
#include <QScreen>
#include <QMainWindow>
#include <QString>

#include <cstdlib>
#include <windows.h>
#include <ctime>

#include <mp3.h>
#include <mp3frame.h>

class Music: public MainWindow
{

public:
    std::string musicPath;
    std::string imagePath;
    std::string Artist;
    std::string Title;
    std::string Album;
    std::string Year;
    std::string Comment;

    double lenght;

    QPushButton *musicWidget;
    QLabel *imageLabel;
    QLabel *titleLabel;
    QLabel *artistLabel;
    QLabel *timeLabel;

    Music(std::string path, int numMusic);

};


#endif // MUSIC_H
