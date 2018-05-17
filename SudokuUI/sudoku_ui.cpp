#include "sudoku_ui.h"
#include "ui_sudoku_ui.h"
#include "/Users/jacksoncrewe/Desktop/Sudoku/solver.h"
#include <iostream>

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

void Sudoku_UI::on_pushButton_clicked()
{

    QString one_one_one = ui->one_one_1->toPlainText();
    one_one_one = one_one_one.trimmed();
    if (one_one_one.isEmpty()){
        one_one_one = '0';
    }
    else if (one_one_one.length() != 1){
        // display an error message
    }
    QString one_two_one = ui->one_two_1->toPlainText();
    one_two_one = one_two_one.trimmed();
    if (one_two_one.isEmpty()){
        one_two_one = '0';
    }
    else if (one_two_one.length() != 1){
        // display an error message
    }
    QString one_three_one = ui->one_three_1->toPlainText();
    one_three_one = one_three_one.trimmed();
    if (one_three_one.isEmpty()){
        one_three_one = '0';
    }
    else if (one_three_one.length() != 1){
        // display an error message
    }
    QString two_one_one = ui->two_one_1->toPlainText();
    two_one_one = two_one_one.trimmed();
    if (two_one_one.isEmpty()){
        two_one_one = '0';
    }
    if (two_one_one.length() != 1){
        // display an error message
    }
    QString two_two_one = ui->two_two_1->toPlainText();
    two_two_one = two_two_one.trimmed();
    if (two_two_one.isEmpty()){
        two_two_one = '0';
    }
    if (two_two_one.length() != 1){
        // display an error message
    }
    QString two_three_one = ui->two_three_1->toPlainText();
    two_three_one = two_three_one.trimmed();
    if (two_three_one.isEmpty()){
        two_three_one = '0';
    }
    if (two_three_one.length() != 1){
        // display an error message
    }
    QString three_one_one = ui->three_one_1->toPlainText();
    three_one_one = three_one_one.trimmed();
    if (three_one_one.isEmpty()){
        three_one_one = '0';
    }
    if (three_one_one.length() != 1){
        // display an error message
    }
    QString three_two_one = ui->three_two_1->toPlainText();
    three_two_one = three_two_one.trimmed();
    if (three_two_one.isEmpty()){
        three_two_one = '0';
    }
    if (three_two_one.length() != 1){
        // display an error message
    }
    QString three_three_one = ui->three_three_1->toPlainText();
    three_three_one = three_three_one.trimmed();
    if (three_three_one.isEmpty()){
        three_three_one = '0';
    }
    if (three_three_one.length() != 1){
        // display an error message
    }



    QString one_one_two = ui->one_one_2->toPlainText();
    one_one_two = one_one_two.trimmed();
    if (one_one_two.isEmpty()){
        one_one_two = '0';
    }
    if (one_one_two.length() != 1){
        // display an error message
    }
    QString one_two_two = ui->one_two_2->toPlainText();
    one_two_two = one_two_two.trimmed();
    if (one_two_two.isEmpty()){
        one_two_two = '0';
    }
    if (one_two_two.length() != 1){
        // display an error message
    }
    QString one_three_two = ui->one_three_2->toPlainText();
    one_three_two = one_three_two.trimmed();
    if (one_three_two.isEmpty()){
        one_three_two = '0';
    }
    if (one_three_two.length() != 1){
        // display an error message
    }
    QString two_one_two = ui->two_one_2->toPlainText();
    two_one_two = two_one_two.trimmed();
    if (two_one_two.isEmpty()){
        two_one_two = '0';
    }
    if (two_one_two.length() != 1){
        // display an error message
    }
    QString two_two_two = ui->two_two_2->toPlainText();
    two_two_two = two_two_two.trimmed();
    if (two_two_two.isEmpty()){
        two_two_two = '0';
    }
    if (two_two_two.length() != 1){
        // display an error message
    }
    QString two_three_two = ui->two_three_2->toPlainText();
    two_three_two = two_three_two.trimmed();
    if (two_three_two.isEmpty()){
        two_three_two = '0';
    }
    if (two_three_two.length() != 1){
        // display an error message
    }
    QString three_one_two = ui->three_one_2->toPlainText();
    three_one_two = three_one_two.trimmed();
    if (three_one_two.isEmpty()){
        three_one_two = '0';
    }
    if (three_one_two.length() != 1){
        // display an error message
    }
    QString three_two_two = ui->three_two_2->toPlainText();
    three_two_two = three_two_two.trimmed();
    if (three_two_two.isEmpty()){
        three_two_two = '0';
    }
    if (three_two_two.length() != 1){
        // display an error message
    }
    QString three_three_two = ui->three_three_2->toPlainText();
    three_three_two = three_three_two.trimmed();
    if (three_three_two.isEmpty()){
        three_three_two = '0';
    }
    if (three_three_two.length() != 1){
        // display an error message
    }



    QString one_one_three = ui->one_one_3->toPlainText();
    one_one_three = one_one_three.trimmed();
    if (one_one_three.isEmpty()){
        one_one_three = '0';
    }
    if (one_one_three.length() != 1){
        // display an error message
    }
    QString one_two_three = ui->one_two_3->toPlainText();
    one_two_three = one_two_three.trimmed();
    if (one_two_three.isEmpty()){
        one_two_three = '0';
    }
    if (one_two_three.length() != 1){
        // display an error message
    }
    QString one_three_three = ui->one_three_3->toPlainText();
    one_three_three = one_three_three.trimmed();
    if (one_three_three.isEmpty()){
        one_three_three = '0';
    }
    if (one_three_three.length() != 1){
        // display an error message
    }
    QString two_one_three = ui->two_one_3->toPlainText();
    two_one_three = two_one_three.trimmed();
    if (two_one_three.isEmpty()){
        two_one_three = '0';
    }
    if (two_one_three.length() != 1){
        // display an error message
    }
    QString two_two_three = ui->two_two_3->toPlainText();
    two_two_three = two_two_three.trimmed();
    if (two_two_three.isEmpty()){
        two_two_three = '0';
    }
    if (two_two_three.length() != 1){
        // display an error message
    }
    QString two_three_three = ui->two_three_3->toPlainText();
    two_three_three = two_three_three.trimmed();
    if (two_three_three.isEmpty()){
        two_three_three = '0';
    }
    if (two_three_three.length() != 1){
        // display an error message
    }
    QString three_one_three = ui->three_one_3->toPlainText();
    three_one_three = three_one_three.trimmed();
    if (three_one_three.isEmpty()){
        three_one_three = '0';
    }
    if (three_one_three.length() != 1){
        // display an error message
    }
    QString three_two_three = ui->three_two_3->toPlainText();
    three_two_three = three_two_three.trimmed();
    if (three_two_three.isEmpty()){
        three_two_three = '0';
    }
    if (three_two_three.length() != 1){
        // display an error message
    }
    QString three_three_three = ui->three_three_3->toPlainText();
    three_three_three = three_three_three.trimmed();
    if (three_three_three.isEmpty()){
        three_three_three = '0';
    }
    if (three_three_three.length() != 1){
        // display an error message
    }



    QString one_one_four = ui->one_one_4->toPlainText();
    one_one_four = one_one_four.trimmed();
    if (one_one_four.isEmpty()){
        one_one_four = '0';
    }
    if (one_one_four.length() != 1){
        // display an error message
    }
    QString one_two_four = ui->one_two_4->toPlainText();
    one_two_four = one_two_four.trimmed();
    if (one_two_four.isEmpty()){
        one_two_four = '0';
    }
    if (one_two_four.length() != 1){
        // display an error message
    }
    QString one_three_four = ui->one_three_4->toPlainText();
    one_three_four = one_three_four.trimmed();
    if (one_three_four.isEmpty()){
        one_three_four = '0';
    }
    if (one_three_four.length() != 1){
        // display an error message
    }
    QString two_one_four = ui->two_one_4->toPlainText();
    two_one_four = two_one_four.trimmed();
    if (two_one_four.isEmpty()){
        two_one_four = '0';
    }
    if (two_one_four.length() != 1){
        // display an error message
    }
    QString two_two_four = ui->two_two_4->toPlainText();
    two_two_four = two_two_four.trimmed();
    if (two_two_four.isEmpty()){
        two_two_four = '0';
    }
    if (two_two_four.length() != 1){
        // display an error message
    }
    QString two_three_four = ui->two_three_4->toPlainText();
    two_three_four = two_three_four.trimmed();
    if (two_three_four.isEmpty()){
        two_three_four = '0';
    }
    if (two_three_four.length() != 1){
        // display an error message
    }
    QString three_one_four = ui->three_one_4->toPlainText();
    three_one_four = three_one_four.trimmed();
    if (three_one_four.isEmpty()){
        three_one_four = '0';
    }
    if (three_one_four.length() != 1){
        // display an error message
    }
    QString three_two_four = ui->three_two_4->toPlainText();
    three_two_four = three_two_four.trimmed();
    if (three_two_four.isEmpty()){
        three_two_four = '0';
    }
    if (three_two_four.length() != 1){
        // display an error message
    }
    QString three_three_four = ui->three_three_4->toPlainText();
    three_three_four = three_three_four.trimmed();
    if (three_three_four.isEmpty()){
        three_three_four = '0';
    }
    if (three_three_four.length() != 1){
        // display an error message
    }




    QString one_one_five = ui->one_one_5->toPlainText();
    one_one_five = one_one_five.trimmed();
    if (one_one_five.isEmpty()){
        one_one_five = '0';
    }
    if (one_one_five.length() != 1){
        // display an error message
    }
    QString one_two_five = ui->one_two_5->toPlainText();
    one_two_five = one_two_five.trimmed();
    if (one_two_five.isEmpty()){
        one_two_five = '0';
    }
    if (one_two_five.length() != 1){
        // display an error message
    }
    QString one_three_five = ui->one_three_5->toPlainText();
    one_three_five = one_three_five.trimmed();
    if (one_three_five.isEmpty()){
        one_three_five = '0';
    }
    if (one_three_five.length() != 1){
        // display an error message
    }
    QString two_one_five = ui->two_one_5->toPlainText();
    two_one_five = two_one_five.trimmed();
    if (two_one_five.isEmpty()){
        two_one_five = '0';
    }
    if (two_one_five.length() != 1){
        // display an error message
    }
    QString two_two_five = ui->two_two_5->toPlainText();
    two_two_five = two_two_five.trimmed();
    if (two_two_five.isEmpty()){
        two_two_five = '0';
    }
    if (two_two_five.length() != 1){
        // display an error message
    }
    QString two_three_five = ui->two_three_5->toPlainText();
    two_three_five = two_three_five.trimmed();
    if (two_three_five.isEmpty()){
        two_three_five = '0';
    }
    if (two_three_five.length() != 1){
        // display an error message
    }
    QString three_one_five = ui->three_one_5->toPlainText();
    three_one_five = three_one_five.trimmed();
    if (three_one_five.isEmpty()){
        three_one_five = '0';
    }
    if (three_one_five.length() != 1){
        // display an error message
    }
    QString three_two_five = ui->three_two_5->toPlainText();
    three_two_five = three_two_five.trimmed();
    if (three_two_five.isEmpty()){
        three_two_five = '0';
    }
    if (three_two_five.length() != 1){
        // display an error message
    }
    QString three_three_five = ui->three_three_5->toPlainText();
    three_three_five = three_three_five.trimmed();
    if (three_three_five.isEmpty()){
        three_three_five = '0';
    }
    if (three_three_five.length() != 1){
        // display an error message
    }



    QString one_one_six = ui->one_one_6->toPlainText();
    one_one_six = one_one_six.trimmed();
    if (one_one_six.isEmpty()){
        one_one_six = '0';
    }
    if (one_one_six.length() != 1){
        // display an error message
    }
    QString one_two_six = ui->one_two_6->toPlainText();
    one_two_six = one_two_six.trimmed();
    if (one_two_six.isEmpty()){
        one_two_six = '0';
    }
    if (one_two_six.length() != 1){
        // display an error message
    }
    QString one_three_six = ui->one_three_6->toPlainText();
    one_three_six = one_three_six.trimmed();
    if (one_three_six.isEmpty()){
        one_three_six = '0';
    }
    if (one_three_six.length() != 1){
        // display an error message
    }
    QString two_one_six = ui->two_one_6->toPlainText();
    two_one_six = two_one_six.trimmed();
    if (two_one_six.isEmpty()){
        two_one_six = '0';
    }
    if (two_one_six.length() != 1){
        // display an error message
    }
    QString two_two_six = ui->two_two_6->toPlainText();
    two_two_six = two_two_six.trimmed();
    if (two_two_six.isEmpty()){
        two_two_six = '0';
    }
    if (two_two_six.length() != 1){
        // display an error message
    }
    QString two_three_six = ui->two_three_6->toPlainText();
    two_three_six = two_three_six.trimmed();
    if (two_three_six.isEmpty()){
        two_three_six = '0';
    }
    if (two_three_six.length() != 1){
        // display an error message
    }
    QString three_one_six = ui->three_one_6->toPlainText();
    three_one_six = three_one_six.trimmed();
    if (three_one_six.isEmpty()){
        three_one_six = '0';
    }
    if (three_one_six.length() != 1){
        // display an error message
    }
    QString three_two_six = ui->three_two_6->toPlainText();
    three_two_six = three_two_six.trimmed();
    if (three_two_six.isEmpty()){
        three_two_six = '0';
    }
    if (three_two_six.length() != 1){
        // display an error message
    }
    QString three_three_six = ui->three_three_6->toPlainText();
    three_three_six = three_three_six.trimmed();
    if (three_three_six.isEmpty()){
        three_three_six = '0';
    }
    if (three_three_six.length() != 1){
        // display an error message
    }



    QString one_one_seven = ui->one_one_7->toPlainText();
    one_one_seven = one_one_seven.trimmed();
    if (one_one_seven.isEmpty()){
        one_one_seven = '0';
    }
    if (one_one_seven.length() != 1){
        // display an error message
    }
    QString one_two_seven = ui->one_two_7->toPlainText();
    one_two_seven = one_two_seven.trimmed();
    if (one_two_seven.isEmpty()){
        one_two_seven = '0';
    }
    if (one_two_seven.length() != 1){
        // display an error message
    }
    QString one_three_seven = ui->one_three_7->toPlainText();
    one_three_seven = one_three_seven.trimmed();
    if (one_three_seven.isEmpty()){
        one_three_seven = '0';
    }
    if (one_three_seven.length() != 1){
        // display an error message
    }
    QString two_one_seven = ui->two_one_7->toPlainText();
    two_one_seven = two_one_seven.trimmed();
    if (two_one_seven.isEmpty()){
        two_one_seven = '0';
    }
    if (two_one_seven.length() != 1){
        // display an error message
    }
    QString two_two_seven = ui->two_two_7->toPlainText();
    two_two_seven = two_two_seven.trimmed();
    if (two_two_seven.isEmpty()){
        two_two_seven = '0';
    }
    if (two_two_seven.length() != 1){
        // display an error message
    }
    QString two_three_seven = ui->two_three_7->toPlainText();
    two_three_seven = two_three_seven.trimmed();
    if (two_three_seven.isEmpty()){
        two_three_seven = '0';
    }
    if (two_three_seven.length() != 1){
        // display an error message
    }
    QString three_one_seven = ui->three_one_7->toPlainText();
    three_one_seven = three_one_seven.trimmed();
    if (three_one_seven.isEmpty()){
        one_one_seven = '0';
    }
    if (three_one_seven.length() != 1){
        // display an error message
    }
    QString three_two_seven = ui->three_two_7->toPlainText();
    three_two_seven = three_two_seven.trimmed();
    if (three_two_seven.isEmpty()){
        three_two_seven = '0';
    }
    if (three_two_seven.length() != 1){
        // display an error message
    }
    QString three_three_seven = ui->three_three_7->toPlainText();
    three_three_seven = three_three_seven.trimmed();
    if (three_three_seven.isEmpty()){
        three_three_seven = '0';
    }
    if (three_three_seven.length() != 1){
        // display an error message
    }



    QString one_one_eight = ui->one_one_8->toPlainText();
    one_one_eight = one_one_eight.trimmed();
    if (one_one_eight.isEmpty()){
        one_one_eight = '0';
    }
    if (one_one_eight.length() != 1){
        // display an error message
    }
    QString one_two_eight = ui->one_two_8->toPlainText();
    one_two_eight = one_two_eight.trimmed();
    if (one_two_eight.isEmpty()){
        one_two_eight = '0';
    }
    if (one_two_eight.length() != 1){
        // display an error message
    }
    QString one_three_eight = ui->one_three_8->toPlainText();
    one_three_eight = one_three_eight.trimmed();
    if (one_three_eight.isEmpty()){
        one_three_eight = '0';
    }
    if (one_three_eight.length() != 1){
        // display an error message
    }
    QString two_one_eight = ui->two_one_8->toPlainText();
    two_one_eight = two_one_eight.trimmed();
    if (two_one_eight.isEmpty()){
        two_one_eight = '0';
    }
    if (two_one_eight.length() != 1){
        // display an error message
    }
    QString two_two_eight = ui->two_two_8->toPlainText();
    two_two_eight = two_two_eight.trimmed();
    if (two_two_eight.isEmpty()){
        two_two_eight = '0';
    }
    if (two_two_eight.length() != 1){
        // display an error message
    }
    QString two_three_eight = ui->two_three_8->toPlainText();
    two_three_eight = two_three_eight.trimmed();
    if (two_three_eight.isEmpty()){
        two_three_eight = '0';
    }
    if (two_three_eight.length() != 1){
        // display an error message
    }
    QString three_one_eight = ui->three_one_8->toPlainText();
    three_one_eight = three_one_eight.trimmed();
    if (three_one_eight.isEmpty()){
        three_one_eight = '0';
    }
    if (three_one_eight.length() != 1){
        // display an error message
    }
    QString three_two_eight = ui->three_two_8->toPlainText();
    three_two_eight = three_two_eight.trimmed();
    if (three_two_eight.isEmpty()){
        three_two_eight = '0';
    }
    if (three_two_eight.length() != 1){
        // display an error message
    }
    QString three_three_eight = ui->three_three_8->toPlainText();
    three_three_eight = three_three_eight.trimmed();
    if (three_three_eight.isEmpty()){
        three_three_eight = '0';
    }
    if (three_three_eight.length() != 1){
        // display an error message
    }

    QString one_one_nine = ui->one_one_9->toPlainText();
    one_one_nine = one_one_nine.trimmed();
    if (one_one_nine.isEmpty()){
        one_one_nine = '0';
    }
    if (one_one_nine.length() != 1){
        // display an error message
    }
    QString one_two_nine = ui->one_two_9->toPlainText();
    one_two_nine = one_two_nine.trimmed();
    if (one_two_nine.isEmpty()){
        one_two_nine = '0';
    }
    if (one_two_nine.length() != 1){
        // display an error message
    }
    QString one_three_nine = ui->one_three_9->toPlainText();
    one_three_nine = one_three_nine.trimmed();
    if (one_three_nine.isEmpty()){
        one_three_nine = '0';
    }
    if (one_three_nine.length() != 1){
        // display an error message
    }
    QString two_one_nine = ui->two_one_9->toPlainText();
    two_one_nine = two_one_nine.trimmed();
    if (two_one_nine.isEmpty()){
        two_one_nine = '0';
    }
    if (two_one_nine.length() != 1){
        // display an error message
    }
    QString two_two_nine = ui->two_two_9->toPlainText();
    two_two_nine = two_two_nine.trimmed();
    if (two_two_nine.isEmpty()){
        two_two_nine = '0';
    }
    if (two_two_nine.length() != 1){
        // display an error message
    }
    QString two_three_nine = ui->two_three_9->toPlainText();
    two_three_nine = two_three_nine.trimmed();
    if (two_three_nine.isEmpty()){
        two_three_nine = '0';
    }
    if (two_three_nine.length() != 1){
        // display an error message
    }
    QString three_one_nine = ui->three_one_9->toPlainText();
    three_one_nine = three_one_nine.trimmed();
    if (three_one_nine.isEmpty()){
        three_one_nine = '0';
    }
    if (three_one_nine.length() != 1){
        // display an error message
    }
    QString three_two_nine = ui->three_two_9->toPlainText();
    three_two_nine = three_two_nine.trimmed();
    if (three_two_nine.isEmpty()){
        three_two_nine = '0';
    }
    if (three_two_nine.length() != 1){
        // display an error message
    }
    QString three_three_nine = ui->three_three_9->toPlainText();
    three_three_nine = three_three_nine.trimmed();
    if (three_three_nine.isEmpty()){
        three_three_nine = '0';
    }
    if (three_three_nine.length() != 1){
        // display an error message
    }

    SudokuBoard board = SudokuBoard();
    board.updatePossibilities();
    // Create cells using above values
    int i_one_one_one = one_one_one.toInt();
    int i_one_one_two = one_one_two.toInt();
    int i_one_one_three = one_one_three.toInt();
    int i_one_two_one = one_two_one.toInt();
    int i_one_two_two = one_two_two.toInt();
    int i_one_two_three = one_two_three.toInt();
    int i_one_three_one = one_three_one.toInt();
    int i_one_three_two = one_three_two.toInt();
    int i_one_three_three = one_three_three.toInt();

    int i_two_one_one = two_one_one.toInt();
    int i_two_one_two = two_one_two.toInt();
    int i_two_one_three = two_one_three.toInt();
    int i_two_two_one = two_two_one.toInt();
    int i_two_two_two = two_two_two.toInt();
    int i_two_two_three = two_two_three.toInt();
    int i_two_three_one = two_three_one.toInt();
    int i_two_three_two = two_three_two.toInt();
    int i_two_three_three = two_three_three.toInt();

    int i_three_one_one = three_one_one.toInt();
    int i_three_one_two = three_one_two.toInt();
    int i_three_one_three = three_one_three.toInt();
    int i_three_two_one = three_two_one.toInt();
    int i_three_two_two = three_two_two.toInt();
    int i_three_two_three = three_two_three.toInt();
    int i_three_three_one = three_three_one.toInt();
    int i_three_three_two = three_three_two.toInt();
    int i_three_three_three = three_three_three.toInt();

    int i_one_one_four = one_one_four.toInt();
    int i_one_one_five = one_one_five.toInt();
    int i_one_one_six = one_one_six.toInt();
    int i_one_two_four = one_two_four.toInt();
    int i_one_two_five = one_two_five.toInt();
    int i_one_two_six = one_two_six.toInt();
    int i_one_three_four = one_three_four.toInt();
    int i_one_three_five = one_three_five.toInt();
    int i_one_three_six = one_three_six.toInt();

    int i_two_one_four = two_one_four.toInt();
    int i_two_one_five = two_one_five.toInt();
    int i_two_one_six = two_one_six.toInt();
    int i_two_two_four = two_two_four.toInt();
    int i_two_two_five = two_two_five.toInt();
    int i_two_two_six = two_two_six.toInt();
    int i_two_three_four = two_three_four.toInt();
    int i_two_three_five = two_three_five.toInt();
    int i_two_three_six = two_three_six.toInt();

    int i_three_one_four = three_one_four.toInt();
    int i_three_one_five = three_one_five.toInt();
    int i_three_one_six = three_one_six.toInt();
    int i_three_two_four = three_two_four.toInt();
    int i_three_two_five = three_two_five.toInt();
    int i_three_two_six = three_two_six.toInt();
    int i_three_three_four = three_three_four.toInt();
    int i_three_three_five = three_three_five.toInt();
    int i_three_three_six = three_three_six.toInt();

    int i_one_one_seven = one_one_seven.toInt();
    int i_one_one_eight = one_one_eight.toInt();
    int i_one_one_nine = one_one_nine.toInt();
    int i_one_two_seven = one_two_seven.toInt();
    int i_one_two_eight = one_two_eight.toInt();
    int i_one_two_nine = one_two_nine.toInt();
    int i_one_three_seven = one_three_seven.toInt();
    int i_one_three_eight = one_three_eight.toInt();
    int i_one_three_nine = one_three_nine.toInt();

    int i_two_one_seven = two_one_seven.toInt();
    int i_two_one_eight = two_one_eight.toInt();
    int i_two_one_nine = two_one_nine.toInt();
    int i_two_two_seven = two_two_seven.toInt();
    int i_two_two_eight = two_two_eight.toInt();
    int i_two_two_nine = two_two_nine.toInt();
    int i_two_three_seven = two_three_seven.toInt();
    int i_two_three_eight = two_three_eight.toInt();
    int i_two_three_nine = one_three_nine.toInt();

    int i_three_one_seven = three_one_seven.toInt();
    int i_three_one_eight = three_one_eight.toInt();
    int i_three_one_nine = three_one_nine.toInt();
    int i_three_two_seven = three_two_seven.toInt();
    int i_three_two_eight = three_two_eight.toInt();
    int i_three_two_nine = three_two_nine.toInt();
    int i_three_three_seven = three_three_seven.toInt();
    int i_three_three_eight = three_three_eight.toInt();
    int i_three_three_nine = three_three_nine.toInt();

    Cell cell0 = Cell(i_one_one_one, 0 , 0 , 1);
    Cell cell1 = Cell(i_one_two_one, 0 , 1 , 1);
    Cell cell2 = Cell(i_one_three_one, 0 , 2 , 1);
    Cell cell3 = Cell(i_one_one_two, 0 , 3 , 2);
    Cell cell4 = Cell(i_one_two_two, 0 , 4 , 2);
    Cell cell5 = Cell(i_one_three_two, 0 , 5 , 2);
    Cell cell6 = Cell(i_one_one_three, 0 , 6 , 3);
    Cell cell7 = Cell(i_one_two_three, 0 , 7, 3);
    Cell cell8 = Cell(i_one_three_three, 0 , 8, 3);

    Cell cell9 = Cell(i_two_one_one, 1 , 0 , 1);
    Cell cell10 = Cell(i_two_two_one, 1 , 1 , 1);
    Cell cell11 = Cell(i_two_three_one, 1 , 2 , 1);
    Cell cell12 = Cell(i_two_one_two, 1 , 3 , 2);
    Cell cell13 = Cell(i_two_two_two, 1 , 4 , 2);
    Cell cell14 = Cell(i_two_three_two, 1 , 5 , 2);
    Cell cell15 = Cell(i_two_one_three, 1 , 6 , 3);
    Cell cell16 = Cell(i_two_two_three, 1 , 7, 3);
    Cell cell17 = Cell(i_two_three_three, 1 , 8, 3);

    Cell cell18 = Cell(i_three_one_one, 2 , 0 , 1);
    Cell cell19 = Cell(i_three_two_one, 2 , 1 , 1);
    Cell cell20 = Cell(i_three_three_one, 2 , 2 , 1);
    Cell cell21 = Cell(i_three_one_two, 2 , 3 , 2);
    Cell cell22 = Cell(i_three_two_two, 2 , 4 , 2);
    Cell cell23 = Cell(i_three_three_two, 2 , 5 , 2);
    Cell cell24 = Cell(i_three_one_three, 2 , 6 , 3);
    Cell cell25 = Cell(i_three_two_three, 2 , 7, 3);
    Cell cell26 = Cell(i_three_three_three, 2 , 8, 3);

    Cell cell27 = Cell(i_one_one_four, 3, 0, 4);
    Cell cell28 = Cell(i_one_two_four, 3, 1, 4);
    Cell cell29 = Cell(i_one_three_four, 3, 2, 4);
    Cell cell30 = Cell(i_one_one_five, 3, 3, 5);
    Cell cell31 = Cell(i_one_two_five, 3, 4, 5);
    Cell cell32 = Cell(i_one_three_five, 3, 5, 5);
    Cell cell33 = Cell(i_one_one_six, 3, 6, 6);
    Cell cell34 = Cell(i_one_two_six, 3, 7, 6);
    Cell cell35 = Cell(i_one_three_six, 3, 8, 6);

    Cell cell36 = Cell(i_two_one_four, 4, 0, 4);
    Cell cell37 = Cell(i_two_two_four, 4, 1, 4);
    Cell cell38 = Cell(i_two_three_four, 4, 2, 4);
    Cell cell39 = Cell(i_two_one_five, 4, 3, 5);
    Cell cell40 = Cell(i_two_two_five, 4, 4, 5);
    Cell cell41 = Cell(i_two_three_five, 4, 5, 5);
    Cell cell42 = Cell(i_two_one_six, 4, 6, 6);
    Cell cell43 = Cell(i_two_two_six, 4, 7, 6);
    Cell cell44 = Cell(i_two_three_six, 4, 8, 6);

    Cell cell45 = Cell(i_three_one_four, 5, 0, 4);
    Cell cell46 = Cell(i_three_two_four, 5, 1, 4);
    Cell cell47 = Cell(i_three_three_four, 5, 2, 4);
    Cell cell48 = Cell(i_three_one_five, 5, 3, 5);
    Cell cell49 = Cell(i_three_two_five, 5, 4, 5);
    Cell cell50 = Cell(i_three_three_five, 5, 5, 5);
    Cell cell51 = Cell(i_three_one_six, 5, 6, 6);
    Cell cell52 = Cell(i_three_two_six, 5, 7, 6);
    Cell cell53 = Cell(i_three_three_six, 5, 8, 6);

    Cell cell54 = Cell(i_one_one_seven, 6 , 0 , 7);
    Cell cell55 = Cell(i_one_two_seven, 6 , 1 , 7);
    Cell cell56 = Cell(i_one_three_seven, 6 , 2 , 7);
    Cell cell57 = Cell(i_one_one_eight, 6 , 3 , 8);
    Cell cell58 = Cell(i_one_two_eight, 6 , 4 , 8);
    Cell cell59 = Cell(i_one_three_eight, 6 , 5 , 8);
    Cell cell60 = Cell(i_one_one_nine, 6 , 6 , 9);
    Cell cell61 = Cell(i_one_two_nine, 6 , 7, 9);
    Cell cell62 = Cell(i_one_three_nine, 6 , 8, 9);

    Cell cell63 = Cell(i_two_one_seven, 7 , 0 , 7);
    Cell cell64 = Cell(i_two_two_seven, 7 , 1 , 7);
    Cell cell65 = Cell(i_two_three_seven, 7 , 2 , 7);
    Cell cell66 = Cell(i_two_one_eight, 7 , 3 , 8);
    Cell cell67 = Cell(i_two_two_eight, 7 , 4 , 8);
    Cell cell68 = Cell(i_two_three_eight, 7 , 5 , 8);
    Cell cell69 = Cell(i_two_one_nine, 7 , 6 , 9);
    Cell cell70 = Cell(i_two_two_nine, 7 , 7, 9);
    Cell cell71 = Cell(i_two_three_nine, 7 , 8, 9);

    Cell cell72 = Cell(i_three_one_seven, 8 , 0 , 7);
    Cell cell73 = Cell(i_three_two_seven, 8 , 1 , 7);
    Cell cell74 = Cell(i_three_three_seven, 8 , 2 , 7);
    Cell cell75 = Cell(i_three_one_eight, 8 , 3 , 8);
    Cell cell76 = Cell(i_three_two_eight, 8 , 4 , 8);
    Cell cell77 = Cell(i_three_three_eight, 8 , 5 , 8);
    Cell cell78 = Cell(i_three_one_nine, 8 , 6 , 9);
    Cell cell79 = Cell(i_three_two_nine, 8 , 7, 9);
    Cell cell80 = Cell(i_three_three_nine, 8 , 8, 9);

    board.setValue(cell0);
    board.setValue(cell1);
    board.setValue(cell2);
    board.setValue(cell3);
    board.setValue(cell4);
    board.setValue(cell5);
    board.setValue(cell6);
    board.setValue(cell7);
    board.setValue(cell8);

    board.setValue(cell9);
    board.setValue(cell10);
    board.setValue(cell11);
    board.setValue(cell12);
    board.setValue(cell13);
    board.setValue(cell14);
    board.setValue(cell15);
    board.setValue(cell16);
    board.setValue(cell17);

    board.setValue(cell18);
    board.setValue(cell19);
    board.setValue(cell20);
    board.setValue(cell21);
    board.setValue(cell22);
    board.setValue(cell23);
    board.setValue(cell24);
    board.setValue(cell25);
    board.setValue(cell26);

    board.setValue(cell27);
    board.setValue(cell28);
    board.setValue(cell29);
    board.setValue(cell30);
    board.setValue(cell31);
    board.setValue(cell32);
    board.setValue(cell33);
    board.setValue(cell34);
    board.setValue(cell35);

    board.setValue(cell36);
    board.setValue(cell37);
    board.setValue(cell38);
    board.setValue(cell39);
    board.setValue(cell40);
    board.setValue(cell41);
    board.setValue(cell42);
    board.setValue(cell43);
    board.setValue(cell44);

    board.setValue(cell45);
    board.setValue(cell46);
    board.setValue(cell47);
    board.setValue(cell48);
    board.setValue(cell49);
    board.setValue(cell50);
    board.setValue(cell51);
    board.setValue(cell52);
    board.setValue(cell53);

    board.setValue(cell54);
    board.setValue(cell55);
    board.setValue(cell56);
    board.setValue(cell57);
    board.setValue(cell58);
    board.setValue(cell59);
    board.setValue(cell60);
    board.setValue(cell61);
    board.setValue(cell62);

    board.setValue(cell63);
    board.setValue(cell64);
    board.setValue(cell65);
    board.setValue(cell66);
    board.setValue(cell67);
    board.setValue(cell68);
    board.setValue(cell69);
    board.setValue(cell70);
    board.setValue(cell71);

    board.setValue(cell72);
    board.setValue(cell73);
    board.setValue(cell74);
    board.setValue(cell75);
    board.setValue(cell76);
    board.setValue(cell77);
    board.setValue(cell78);
    board.setValue(cell79);
    board.setValue(cell80);

    board.updatePossibilities();
    board.print(std::cout);
    for(Row row : board.columns_){
        for (int i = 0; i < 9; ++i) {
            std::cout << row.cells_[i].getValue() << std::endl;
        }
    }
    solver s = solver();
    SudokuBoard solvedBoard = s.solve(board);
    if (solvedBoard.rows_[0].cells_[0].getValue() == 100) {
       //we couldn't make the board, make some sort of error message
    }
    else { // Place the values of the solved board in the ui
        solvedBoard.print(std::cout);

    }
}
