/**
 * \class Cell
 * \brief Stores data for each individual cell in our Sudoku Board
 *
 * \details
 *  Stores the default value of the cell, the possibilities of values 
 *  the cell could contain, and the location of the cell within the board
 *
 */

//includes go here


#ifndef CELL_H
#define CELL_H

#include <cstddef>

using namespace std;
class Cell
{
    
public:
    //data members 
    size_t value_;
    size_t possibilities_ [9];
    size_t location_[3];

    //default constructor 
    Cell();

    //paramaterized constructor
    Cell(int value, int row, int col, int squareNum);

    //copy constructor 
    Cell(const Cell&) = delete;

    //destructor
    ~Cell() = default;

    //member functions
    bool isEmpty();
    size_t getValue();
    size_t getLocation();
    size_t numPossibilities();
};
#endif