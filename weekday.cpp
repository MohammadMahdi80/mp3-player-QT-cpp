#include "weekday.h"
#include <iostream>

Weekday::Weekday(std::string n){
    this->name = n;

    this->button = new QPushButton();
    this->button->setText(QString::fromStdString(this->name));
    this->button->resize(120, 35);
    this->button->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    this->button->setAttribute(Qt::WA_NoSystemBackground, true);
    this->button->setAttribute(Qt::WA_TranslucentBackground, true);
    this->button->setStyleSheet(QString::fromStdString("QPushButton {"
                                                       "border: 2px solid #8f8f91;"
                                                       "border-radius: 10px;"
                                                       "background-color: rgba(255, 255, 255, 10);"
                                                       "font-family:Comic Sans MS;color: #04f700;"
                                                       "min-width: 50px;"
                                                       "font-size:20px;}"
                                                       "QPushButton:pressed {color: #5b60bd;}"));

}

void MainWindow::showWeekday(){
    std::string text;
    QPushButton *btn = (QPushButton *)sender();
    QString content = btn->text();
    text = content.toStdString();

    std::cout << text << std::endl;


    this->showWeekdayWidget = new QWidget(this);
    this->showWeekdayWidget->move(130, 30);
    this->showWeekdayWidget->resize(770, 470);
    this->showWeekdayWidget->setStyleSheet(QString::fromStdString("background-color:rgba(0, 0, 0, 100);"));

    this->explainTextEdit = new QLineEdit(this->showWeekdayWidget);
    this->explainTextEdit->setStyleSheet(QString::fromStdString("QLineEdit {border: 2px solid #0713f7"
                                                                ";border-radius: 10px;"
                                                                "border-image:0;"
                                                                "padding: 0 8px;"
                                                                "background: #d5fdff;"
                                                                "background-color: rgba(255, 255, 255, 0);"
                                                                "font-family:Comic Sans MS;color: #f707af;"
                                                                "selection-background-color: darkgray;"
                                                                "font-size: 20px;}"));
    this->explainTextEdit->resize(600, 40);
    this->explainTextEdit->move(100,0);

    if(!text.empty()){
        this->showWeekdayWidget->show();
        this->explainTextEdit->show();
    }

}
