#ifndef GAME_H
#define GAME_H

#include <QWidget>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

    QVector<QString> getScore();
    void initGame();

private slots:

    void on_rockButton_clicked();

    void on_paperButton_clicked();

    void on_scissorsButton_clicked();

    void setComputerImg();


    void on_btnMenu_clicked();

private:
    Ui::Game *ui;

    int result;
    int computerScore = 0;
    int playerScore = 0;
    int random;

signals:
    void endGame();

};

#endif // GAME_H
