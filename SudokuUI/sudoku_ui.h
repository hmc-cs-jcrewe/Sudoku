#ifndef SUDOKU_UI_H
#define SUDOKU_UI_H

#include <QMainWindow>

namespace Ui {
class Sudoku_UI;
}

class Sudoku_UI : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sudoku_UI(QWidget *parent = 0);
    ~Sudoku_UI();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Sudoku_UI *ui;
};

#endif // SUDOKU_UI_H
