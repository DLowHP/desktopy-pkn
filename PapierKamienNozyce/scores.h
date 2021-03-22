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

private slots:
    void on_pushButton_clicked();

private:
    Ui::Scores *ui;

signals:
    void showMenu();
};

#endif // SCORES_H
