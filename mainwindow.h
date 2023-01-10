#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QScreen>
#include <QLabel>
#include <QScrollArea>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    bool enterToMusic = false;
    bool enterToSchedule = false;


    std::string username = "0";
    std::string password = "0";


private:
    Ui::MainWindow *ui;
    QPushButton *closeBtn;
    QPushButton *minimBtn;
    QLineEdit *edit1;
    QLineEdit *edit2;
    QPushButton *loginBtn;
    QPushButton *musicBtn;
    QPushButton *scheduleBtn;
    QWidget *musicWidget;
    QScrollArea *scrollMusicList;
    QWidget *widgetMusicList;
    QPushButton *backBtn;
    QWidget *daysWidget;
    QWidget *showWeekdayWidget;
    QLineEdit *explainTextEdit;

private slots:
    void closeWindow();
    void minimWindow();
    void saveText();
    void confLogBtn();
    void confMusicBtn();
    void confScheduleBtn();
    void showMusic();
    void showWeekday();

};
#endif // MAINWINDOW_H
