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
