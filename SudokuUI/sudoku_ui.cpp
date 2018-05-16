#include "sudoku_ui.h"
#include "ui_sudoku_ui.h"

Sudoku_UI::Sudoku_UI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sudoku_UI)
{
    ui->setupUi(this);
}

Sudoku_UI::~Sudoku_UI()
{
    delete ui;
}
