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

   /**
     * \brief Default constructor for squares
     *
     */    Square();

    /**
     * \brief Parameterized constructor for squares 
     *
     * \param cells     The standard list of cells to be added to the square
     *
     */
    Square(list<Cell> cells);

    /**
     * \brief Copy constructor for squares 
     *
     * \param square      A constant reference to the square we wish to copy
     *
     */  
	Square(const Square& square);

    /**
     * \brief Standard comparison operator for squares  
     *
     * \param rhs     The square to which this is being compared
     *
     * \returns A boolean describing whether or not the squares are equal
     *
     */
    bool operator==(const Square& rhs);

    /**
     * \brief Standard not-comparison operator for squares  
     *
     * \param rhs     The square to which this is being compared
     *
     * \returns A boolean describing whether or not the squares are equal
     *
     */
    bool operator!=(const Square& rhs);

    /**
     * \brief Standard assignment operator for squares  
     *
     * \param rhs     The square to which this is being assigned
     *
     * \returns A square equaling the rhs parameter
     *
     */
    Square& operator=(const Square& rhs);
    
    /**
     * \brief  Checks if the square is complete
     *
     * \returns A boolean describing whether or not every cell 
     *           in the square contains a value
     *
     */
    bool isCompleteSquare();

    /**
     * \brief Updates the possibilities for every cell in the square
     *
     */
	void getPossibilities();

    /**
     * \brief Sets the value of the provided cell into the square
     *
     * \param cell     The cell containing information on the value and 
     *                  location of the desired cell to set
     *
     * \returns A size_t of the value which was just set 
     *
     */
	size_t setValue(Cell cell); 

};
#endif