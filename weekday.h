#ifndef WEEKDAY_H
#define WEEKDAY_H

#include "mainwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QLabel>
#include <QScreen>
#include <QMainWindow>
#include <QString>

class Weekday: public MainWindow
{
public:
    std::string name;
    QPushButton *button;

    Weekday(std::string n);

};


#endif // WEEKDAY_H
