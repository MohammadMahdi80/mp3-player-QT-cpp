#include <QApplication>
#include "mainwindow.h"
#include <QWidget>
#include <QScreen>
#include <QString>
#include <time.h>
#include <vector>
#include <filesystem>
#include <iostream>




namespace fs = std::filesystem;






int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    MainWindow window;

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    std::string bcksPath = "C:/Users/Mahdi/Documents/first/bcks/a/";
    std::vector<std::string> bcks;

    for(const auto & entry : fs::directory_iterator(bcksPath))
        bcks.push_back(entry.path().string());

    srand(time(NULL));
    int RanIndex = rand() % bcks.size();

//    window.resize(width/1.5, height/1.5);
    window.setFixedSize(width/1.5, height/1.5);

    std::string bcksStyle;
    bcksStyle += "border-image: url(";
    bcksStyle += bcks.at(0);
    bcksStyle += ");";
    window.setStyleSheet(QString::fromStdString(bcksStyle));
    window.setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    window.setParent(0); // Create TopLevel-Widget
    window.setAttribute(Qt::WA_NoSystemBackground, true);
    window.setAttribute(Qt::WA_TranslucentBackground, true);

    window.show();

    return app.exec();
}
