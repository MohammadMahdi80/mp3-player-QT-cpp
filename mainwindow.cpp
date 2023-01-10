#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <typeinfo>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QLabel>
#include <QScreen>


#include <mp3.h>
#include <mp3frame.h>

#include <filesystem>
namespace fs = std::filesystem;

#include <typeinfo>
#include <vector>

#include <cstdlib>
#include <windows.h>
#include <ctime>

#include "music.h"

#include "weekday.h"

QString lineEditStyle = "QLineEdit {border: 2px solid gray"
                       ";border-radius: 10px;"
                       "border-image:0;"
                       "padding: 0 8px;"
                       "background: #d5fdff;"
                       "selection-background-color: darkgray;"
                       "font-size: 15px;}"

                       "QLineEdit[echoMode=2] "
                       "{lineedit-password-character: 9679;}"

                       "QLineEdit:read-only "
                       "{background: lightblue;}";

QString loginBtnStyle = "QPushButton {"
                       "border: 2px solid #8f8f91;"
                       "border-radius: 10px;"
                       "min-width: 50px;"
                       "font-size:24px;"
                       "border-image: url(C:/Users/Mahdi/Documents/first/icon/login3.png);}"

                      "QPushButton:pressed {border-image: url(C:/Users/Mahdi/Documents/first/icon/login3p.png);}";

QString backBtnStyle = "QPushButton {"
                       "border: 2px solid #8f8f91;"
                       "border-radius: 10px;"
                       "min-width: 50px;"
                       "font-size:24px;"
                       "border-image: url(C:/Users/Mahdi/Documents/first/icon/back2.png);}"

                      "QPushButton:pressed {border-image: url(C:/Users/Mahdi/Documents/first/icon/back2p.png);}";

QString musicBtnStyle = "QPushButton {"
                       "border: 2px solid #8f8f91;"
                       "border-radius: 10px;"
                       "min-width: 50px;"
                       "font-size:24px;"
                       "border-image: url(C:/Users/Mahdi/Documents/first/icon/ms2.jpg);}"

                      "QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);"
                        "border-image: url(C:/Users/Mahdi/Documents/first/icon/ms2p.jpg);}";

QString scheduleBtnStyle = "QPushButton {"
                       "border: 2px solid #8f8f91;"
                       "border-radius: 10px;"
                       "min-width: 50px;"
                       "font-size:24px;"
                       "border-image: url(C:/Users/Mahdi/Documents/first/icon/date.png);}"

                      "QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);"
                        "border-image: url(C:/Users/Mahdi/Documents/first/icon/datep.png);}";


QString closeBtnStyle = "QPushButton {"
                       "border-image: url(C:/Users/Mahdi/Documents/first/icon/close.png);}"

                      "QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);"
                        "border-image: url(C:/Users/Mahdi/Documents/first/icon/closep.png);}";

QString minimBtnStyle = "QPushButton {"
                       "border-image: url(C:/Users/Mahdi/Documents/first/icon/min.png);}"

                      "QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);"
                        "border-image: url(C:/Users/Mahdi/Documents/first/icon/minp.png);}";




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    closeBtn = new QPushButton(this);
    closeBtn->move(int(0.968*width/1.5),int(0.014*height/1.5));
    closeBtn->resize(int(0.015 * width), int(0.02 * height));
    closeBtn->setStyleSheet(closeBtnStyle);
    closeBtn->connect(closeBtn, SIGNAL(clicked(bool)), this, SLOT(closeWindow()));

    minimBtn = new QPushButton(this);
    minimBtn->move(int(0.935*width/1.5),int(0.014*height/1.5));
    minimBtn->resize(int(0.015 * width), int(0.02 * height));
    minimBtn->setStyleSheet(minimBtnStyle);
    minimBtn->connect(minimBtn, SIGNAL(clicked(bool)), this, SLOT(minimWindow()));



    edit1 = new QLineEdit(this);
    edit1->move(int(0.5*width/1.5 - (0.2 * width)/2),int(0.2*height/1.5));
    edit1->resize(int(0.2 * width), int(0.039 * height));
    edit1->setStyleSheet(lineEditStyle);
    edit1->setPlaceholderText("Username");
    edit1->connect(edit1, SIGNAL(textChanged(QString)), this, SLOT(saveText()));



    edit2 = new QLineEdit(this);
    edit2->move(int(0.5*width/1.5 - (0.2 * width)/2),int(0.27*height/1.5));
    edit2->resize(int(0.2 * width), int(0.039 * height));
    edit2->setStyleSheet(lineEditStyle);
    edit2->setPlaceholderText("Password");
    edit2->setEchoMode(QLineEdit::Password);
    edit2->connect(edit2, SIGNAL(textChanged(QString)), this, SLOT(saveText()));



    loginBtn = new QPushButton(this);
    loginBtn->move(int(0.5*width/1.5 - (0.1 * width)/2),int(0.35*height/1.5));
    loginBtn->resize(int(0.1 * width), int(0.05 * height));
    loginBtn->setStyleSheet(loginBtnStyle);
    loginBtn->connect(loginBtn, SIGNAL(clicked(bool)), this, SLOT(confLogBtn()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeWindow(){
    QCoreApplication::quit();
}

void MainWindow::minimWindow(){
    this->setWindowState(Qt::WindowMinimized);
}

void MainWindow::saveText(){
    std::string text;
    QLineEdit *edit = (QLineEdit *)sender();
    QString content = edit->text();
    text = content.toStdString();
}

void MainWindow::confLogBtn(){
    if(enterToMusic){
        scrollMusicList->hide();
        musicBtn->show();
        backBtn->hide();
        scheduleBtn->show();
    }
    else if(enterToSchedule){
        musicBtn->show();
        backBtn->hide();
        scheduleBtn->show();}
    else{
    std::string enteredUsername = edit1->text().toStdString();
    std::string enteredPassword = edit2->text().toStdString();
    if(username == enteredUsername && password == enteredPassword){
        edit1->close();
        edit2->close();
        loginBtn->close();

        this->setStyleSheet(QString::fromStdString("border-image: none;background-color: rgba(0, 0, 0, 200)"));


        musicBtn = new QPushButton(this);
        musicBtn->move(int((0.05 * width)/1.5),int(0.05*height)/1.5);
        musicBtn->resize(int(0.08 * width), int(0.13 * height));
        musicBtn->setStyleSheet(musicBtnStyle);
        musicBtn->connect(musicBtn, SIGNAL(clicked(bool)), this, SLOT(confMusicBtn()));
        musicBtn->show();

        scheduleBtn = new QPushButton(this);
        scheduleBtn->move(int((0.2 * width)/1.5),int(0.05*height)/1.5);
        scheduleBtn->resize(int(0.08 * width), int(0.13 * height));
        scheduleBtn->setStyleSheet(scheduleBtnStyle);
        scheduleBtn->connect(scheduleBtn, SIGNAL(clicked(bool)), this, SLOT(confScheduleBtn()));
        scheduleBtn->show();

    }
    }
}

void MainWindow::confMusicBtn()
{
    musicBtn->close();
    scheduleBtn->close();


    this->setStyleSheet(QString::fromStdString("border-image: none;background-color: rgba(0, 0, 20, 200)"));

    if(this->enterToMusic){scrollMusicList->show();backBtn->show();}
    else{
        std::string path = "C:/Users/Mahdi/Documents/first/music/";
        std::vector<std::string> files;
        for(const auto & entry : fs::directory_iterator(path)){
            std::cout<< entry << std::endl;
            if(entry.path().string()[entry.path().string().length()-1] == '3'
                    && entry.path().string()[entry.path().string().length()-2] == 'p'
                    && entry.path().string()[entry.path().string().length()-3] == 'm')

                files.push_back(entry.path().string());
        }

        scrollMusicList = new QScrollArea(this);
        scrollMusicList->resize(width/5, height/1.6);
        scrollMusicList->move(5, 5);
        scrollMusicList->setStyleSheet(QString::fromStdString("QScrollBar {height:0px;width:0px;}"));

        widgetMusicList = new QWidget(this);
        widgetMusicList->resize(width/5 , height/1.6);
        widgetMusicList->move(5, 5);
        widgetMusicList->setStyleSheet(QString::fromStdString("background-color:rgba(0, 0, 0, 0);"));

        Music music(files.at(0), 0);
        music.musicWidget->move(10, 10);
        music.musicWidget->setParent(widgetMusicList);
        music.musicWidget->show();
        music.musicWidget->connect(music.musicWidget, SIGNAL(clicked(bool)), this, SLOT(showMusic()));

        Music music2(files.at(1), 1);
        music2.musicWidget->move(10, 70);
        music2.musicWidget->setParent(widgetMusicList);
        music2.musicWidget->show();
        music2.musicWidget->connect(music2.musicWidget, SIGNAL(clicked(bool)), this, SLOT(showMusic()));


        if(enterToMusic || enterToSchedule){backBtn->show();}
        else{
        backBtn = new QPushButton(this);
        backBtn->move(0,height/1.6 + 6);
        backBtn->resize(20, 20);
        backBtn->setStyleSheet(backBtnStyle);
        backBtn->connect(backBtn, SIGNAL(clicked(bool)), this, SLOT(confLogBtn()));
        backBtn->show();
        }

        scrollMusicList->setWidget(widgetMusicList);
        scrollMusicList->show();
        this->enterToMusic = true;

    }



}

void MainWindow::confScheduleBtn(){

    musicBtn->close();
    scheduleBtn->close();
    if(this->enterToSchedule){backBtn->show();}
    else{


        if(enterToMusic || enterToSchedule){backBtn->show();}
        else{
        backBtn = new QPushButton(this);
        backBtn->move(0,height/1.6 + 6);
        backBtn->resize(20, 20);
        backBtn->setStyleSheet(backBtnStyle);
        backBtn->connect(backBtn, SIGNAL(clicked(bool)), this, SLOT(confLogBtn()));
        backBtn->show();
        }

        daysWidget = new QWidget(this);
        daysWidget->resize(width/10 , height/1.6);
        daysWidget->move(5, 5);
        daysWidget->setStyleSheet(QString::fromStdString("background-color:rgba(0, 0, 0, 0);"));
        daysWidget->show();

        Weekday sunday("Sunday");
        sunday.button->setParent(daysWidget);
        sunday.connect(sunday.button, SIGNAL(clicked(bool)), this, SLOT(showWeekday()));
        sunday.button->show();

        int d = 50;

        Weekday monday("Monday");
        monday.button->setParent(daysWidget);
        monday.connect(monday.button, SIGNAL(clicked(bool)), this, SLOT(showWeekday()));
        monday.button->move(0,d);
        monday.button->show();

        Weekday tuesday("Tuesday ");
        tuesday.button->setParent(daysWidget);
        tuesday.connect(tuesday.button, SIGNAL(clicked(bool)), this, SLOT(showWeekday()));
        tuesday.button->move(0,2*d);
        tuesday.button->show();

        Weekday wednesday ("Wednesday ");
        wednesday.button->setParent(daysWidget);
        wednesday.connect(wednesday.button, SIGNAL(clicked(bool)), this, SLOT(showWeekday()));
        wednesday.button->move(0,3*d);
        wednesday.button->show();

        Weekday thursday ("Thursday ");
        thursday.button->setParent(daysWidget);
        thursday.connect(thursday.button, SIGNAL(clicked(bool)), this, SLOT(showWeekday()));
        thursday.button->move(0,4*d);
        thursday.button->show();

        Weekday friday("Friday ");
        friday.button->setParent(daysWidget);
        friday.connect(friday.button, SIGNAL(clicked(bool)), this, SLOT(showWeekday()));
        friday.button->move(0,5*d);
        friday.button->show();

        Weekday saturday("Saturday ");
        saturday.button->setParent(daysWidget);
        saturday.connect(saturday.button, SIGNAL(clicked(bool)), this, SLOT(showWeekday()));
        saturday.button->move(0,6*d);
        saturday.button->show();

        this->showWeekday();

        enterToSchedule = true;
    }
}












