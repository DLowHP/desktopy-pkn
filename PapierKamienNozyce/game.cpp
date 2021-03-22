#include "game.h"
#include "ui_game.h"

#include <QRandomGenerator>
#include <QSettings>

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);

    QPixmap Pix (":/images/img/questionmark.png");

    ui->leftPhoto->setPixmap(Pix.scaled(200,300,Qt::KeepAspectRatio));
    ui->rightPhoto->setPixmap(Pix.scaled(200,300,Qt::KeepAspectRatio));
}

Game::~Game()
{
    delete ui;
}

void Game::setComputerImg()
{
    random = QRandomGenerator::global()->bounded(0,3);
    QPixmap Rock(":/images/img/rock.png");
    QPixmap Paper(":/images/img/paper.png");
    QPixmap Scissors(":/images/img/scissors.png");



    switch(random)
    {
        case 0:
            ui->rightPhoto->setPixmap(Rock);
            result = 0;
        break;

        case 1:
            ui->rightPhoto->setPixmap(Paper);
            result = 1;
        break;

        case 2:
            ui->rightPhoto->setPixmap(Scissors);
            result = 2;
        break;
    }
}

void Game::on_rockButton_clicked()
{
    QPixmap Rock(":/images/img/rock.png");
    ui->leftPhoto->setPixmap(Rock);
    setComputerImg();

    if(result == 1)
    {
        ui->resultLabel->setText("Przegrałeś!");
        computerScore++;
        ui->computerScore->setText("Punkty komputera: " + QString::number(playerScore));

    }   else if(result==2)
        {
            ui->resultLabel->setText("Wygrałeś!");
            playerScore++;
            ui->playerScore->setText("Punkty gracza: " + QString::number(playerScore));

        }   else ui->resultLabel->setText("Remis");
}

void Game::on_paperButton_clicked()
{
    QPixmap Paper(":/images/img/paper.png");
    ui->leftPhoto->setPixmap(Paper);
    setComputerImg();
    if(result == 2)
    {
        ui->resultLabel->setText("Przegrałeś!");
        computerScore++;
        ui->computerScore->setText("Punkty komputera: " + QString::number(computerScore));

    }   else if(result==0)
        {
            ui->resultLabel->setText("Wygrałeś!");
            playerScore++;
            ui->playerScore->setText("Punkty gracza: " + QString::number(playerScore));

        }   else ui->resultLabel->setText("Remis");
}

void Game::on_scissorsButton_clicked()
{
    QPixmap Scissors(":/images/img/scissors.png");
    ui->leftPhoto->setPixmap(Scissors);
    setComputerImg();

    if(result == 0)
    {
        ui->resultLabel->setText("Przegrałeś!");
        computerScore++;
        ui->computerScore->setText("Punkty komputera: " + QString::number(computerScore));

    }   else if(result==1)
        {
            ui->resultLabel->setText("Wygrałeś!");
            playerScore++;
            ui->playerScore->setText("Punkty gracza: " + QString::number(playerScore));

        }   else ui->resultLabel->setText("Remis");
}

void Game::on_btnMenu_clicked()
{
    emit endGame();
}

QVector<QString> Game::getScore()
{
    QVector<QString> score;
    QString name = qgetenv("USER");
    if (name.isEmpty())
        name = qgetenv("USERNAME");
    score.insert(0, name);
    score.insert(1, QString::number(playerScore));
    score.insert(2, QString::number(computerScore));
    return score;
}

void Game::initGame()
{
    QPixmap Pix (":/images/img/questionmark.png");

    ui->leftPhoto->setPixmap(Pix.scaled(200,300,Qt::KeepAspectRatio));
    ui->rightPhoto->setPixmap(Pix.scaled(200,300,Qt::KeepAspectRatio));

    ui->resultLabel->setText("Start!");

    playerScore = 0;
    computerScore = 0;

    ui->playerScore->setText("Punkty gracza: " + QString::number(playerScore));
    ui->computerScore->setText("Punkty komputera: " + QString::number(computerScore));
}
