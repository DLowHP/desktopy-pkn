#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_btnPlay_clicked()
{
    emit showGame();
}

void Menu::on_btnScores_clicked()
{
    emit showScores();
}

void Menu::on_btnExit_clicked()
{
    exit(0);
}
