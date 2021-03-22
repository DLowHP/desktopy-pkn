#include "scores.h"
#include "ui_scores.h"

Scores::Scores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scores)
{
    ui->setupUi(this);
}

Scores::~Scores()
{
    delete ui;
}

void Scores::saveScore(QVector<QString> score)
{
    ui->plainTextEdit->appendPlainText(score[0] + ": " + score[1] + "/" + score[2] + "\n");
}

void Scores::on_pushButton_clicked()
{
    emit showMenu();
}
