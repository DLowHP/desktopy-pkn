#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "game.h"
#include "menu.h"
#include "scores.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Menu *m = new Menu;
    Game *g = new Game;
    Scores *s = new Scores;

    ui->app->insertWidget(0, m);
    ui->app->insertWidget(1, g);
    ui->app->insertWidget(2, s);

    ui->app->setCurrentIndex(1);

    connect(m, SIGNAL(showMenu()), this, SLOT(setMenu()));
    connect(m, SIGNAL(showGame()), this, SLOT(setGame()));
    connect(m, SIGNAL(showScores()), this, SLOT(setScores()));

    connect(s, SIGNAL(showMenu()), this, SLOT(setMenu()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMenu()
{
    ui->app->setCurrentIndex(0);
}

void MainWindow::setGame()
{
    ui->app->setCurrentIndex(1);
}

void MainWindow::setScores()
{
    ui->app->setCurrentIndex(2);
}
