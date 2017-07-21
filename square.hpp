/**
 * \class Square
 * \brief Stores 9 cells for each of the small squares in the Sudoku Board 
 *
 *
 */

#ifndef SQUARE_H
#define SQUARE_H
//includes go here 
#include <cstddef>
#include <list>

#include "cell.hpp"

using namespace std;
class Square 
{

public:

    //data members
	Cell cells_[9];
    //number of cells in the square that contain a value
    size_t squareSize_;

    //default constructor
    Square();

    //paramaterized constructor 
    Square(size_t size, list<Cell> cells);

	//copy constructor 
	Square(const Square& square) = default;

    //member functions
    bool isCompleteSquare();

	void getPossibilities();
};
#endif