/**
 * \file SudokuBoard.hpp
 *
 * \authors Jackson Crewe
 *
 * \brief Declares the SudokuBoard class.
 */

#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

//Anything to include goes here
#include <cstddef>
#include <stdexcept>
#include <list>




#include "row.hpp"
#include "cell.hpp"
#include "square.hpp"

using namespace std;
/**
 * \class SudokuBoard
 * \brief A 2D array of all the cells in the sudoku board
 *
 * \details
 *  Stores an array of characters that will be displayed to the screen, and
 * a Sprite that will be added to the screen.
 *
 */
class SudokuBoard {
public:
   // default constructor 
    SudokuBoard();
 
    //paramaterized constructor
    SudokuBoard(Cell cells[81]);
 
    //copy constructor
    SudokuBoard(const SudokuBoard& other);

	//TODO -- add assignment operator?
	 
    //destructor
    ~SudokuBoard() = default;
 
    //getters
    Row getRow(size_t r);
    Row getCol(size_t c);
	Square getSquare(size_t r, size_t c);
 
    //setters
    Row makeRow(int values [9]);
	Row makeCol(int values[9]);
    Square makeSquare(int values [9]);
 
    //member functions 
    bool isComplete();
    bool inValidSolution();
    void updatePossibilities();

private:
    Row rows_[9];
    Row columns_[9];
	//index reads row then column
    Square squares_[3][3];

};
#endif