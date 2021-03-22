#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include "game.h"
#include "menu.h"
#include "scores.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Menu *m;
    Game *g;
    Scores *s;

private slots:
    void setMenu();
    void setGame();
    void setScores();
    void saveScore();
};
#endif // MAINWINDOW_H
