#ifndef MENU_H
#define MENU_H

#include <QWidget>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_btnPlay_clicked();

    void on_btnScores_clicked();

    void on_btnExit_clicked();

private:
    Ui::Menu *ui;

signals:
    void showGame();
    void showScores();
};

#endif // MENU_H
