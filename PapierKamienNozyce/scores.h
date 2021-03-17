#ifndef SCORES_H
#define SCORES_H

#include <QWidget>

namespace Ui {
class Scores;
}

class Scores : public QWidget
{
    Q_OBJECT

public:
    explicit Scores(QWidget *parent = nullptr);
    ~Scores();

private:
    Ui::Scores *ui;
};

#endif // SCORES_H
