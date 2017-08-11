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
#include <list>

using namespace std;
class Cell
{
public:
    //data members 
    size_t value_;
	bool empty_;
	list<size_t> possibilities_;
    //row , column, square 
    size_t location_[3];

    /**
     * \brief Default constructor for cells
     *
     */
    Cell();

    /**
     * \brief Parameterized constructor for cells 
     *
     * \param value     The numeric value of the cell from 1 - 9
     *
     * \param row       The row of the board where the cell exists from 0 - 8
     *
     * \param col       The col of the board where the cell exists from 0 - 8
     *
     * \param squareNum       The square of the board where the cell exists from 1 - 9
     *                          The squares are set from 1 - 9 to distinguish these cells
     *                          from default cells which contain a square location of 0
     *
     */
    Cell(int value, size_t row, size_t col, size_t squareNum);

    /**
     * \brief Parameterized constructor for cells with a default location
     *
     * \param value     The numeric value of the cell from 1 - 9
     *
     */
	Cell(int value);

    /**
     * \brief Copy constructor for cells 
     *
     * \param cell      A constant reference to the cell we wish to copy
     *
     */
    Cell(const Cell& cell);

    /**
     * \brief Destructor for cells 
     *
     */
    ~Cell() = default;

    /**
     * \brief Standard comparison operator for cells  
     *
     * \param rhs     The cell to which this is being compared
     *
     * \returns A boolean describing whether or not the cells are equal
     *
     */
    bool operator==(const Cell& rhs);

    /**
     * \brief Standard not-comparison operator for cells  
     *
     * \param rhs     The cell to which this is being compared
     *
     * \returns A boolean describing whether or not the cells are equal
     *
     */
    bool operator!=(const Cell& rhs);

    /**
     * \brief Standard assignment operator for cells  
     *
     * \param rhs     The cell to which this is being assigned
     *
     * \returns A cell equaling the rhs parameter
     *
     */
    Cell& operator=(const Cell& rhs);
    

    /**
     * \brief Evaluates whether the cell contains a value
     *
     * \returns A boolean describing whether or not the cell has a value
     *
     */
    bool isEmpty();

    /**
     * \brief Standard getter for the cell's value_ data member
     *
     * \returns The value parameter of this cell
     *
     */
    size_t getValue();

    /**
     * \brief Gets the number of possibilities for the value of this cell 
     *
     * \returns A size_t of the number of possibilities for the value of this cell
     *
     */
    size_t numPossibilities();
};
#endif