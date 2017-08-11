/**
 * \file Board.hpp
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
    /**
     * \brief Default constructor
     *
     * \note Creates a board with every cell's location defined with full possiibilities and a value of 0.
     *
     */
    SudokuBoard();
 
    /**
     * \brief Parameterized constructor
     *
     * \param cells[81]     An array of all 81 cells to place in the board
     *
     */
    SudokuBoard(Cell cells[81]);
 
    /**
     * \brief Copy constructor
     *
     * \param other     A constant reference to the SudokuBoard which is being copied
     *
     */
    SudokuBoard(const SudokuBoard& other);



    /**
     * \brief Destructor
     *
     * \note At its base, all the data within the SudokuBoard are primitives created 
     *       in the stack so the default destructor can handle cleanup  
     *
     */
    ~SudokuBoard() = default;
 
    /**
     * \brief Standard getter function for the rows_ data member
     *
     * \param r     A size_t index of the desired row, the rows are indexed from 0 to 8
     *
     * \returns The row located at index r
     *
     */
    Row getRow(size_t r);

    /**
     * \brief Standard getter function for the columns_ data member
     *
     * \param c     A size_t index of the desired column, the columns are indexed from 0 to 8
     *
     * \returns The row located at index c
     *
     */
    Row getCol(size_t c);

    /**
     * \brief Standard getter function for the squares_ data member
     *
     * \param s     A size_t index of the desired square, the squares are indexed from 0 to 8
     *
     * \returns The square located at index s
     *
     */
	Square getSquare(size_t s);

	//operators
    /**
     * \brief Standard comparison operator for SudokuBoards
     *
     * \param other     The SudokuBoard to which this is being compared
     *
     * \returns A boolean describing whether the boards are the same or not
     *
     */
	bool operator==(const SudokuBoard& other);

    /**
     * \brief Standard not-comparison operator for SudokuBoards
     *
     * \param other     The SudokuBoard to which this is being compared
     *
     * \returns A boolean describing whether the boards are the same or not
     *
     */
	bool operator!=(const SudokuBoard& other);

 
    /**
     * \brief Checks to see if this board is complete
     *
     * \returns A boolean describing whether the boardis complete
     *
     */
    bool isComplete();

    /**
     * \brief Sets the value of the provided cell into the board
     *
     * \param cell     The cell containing information on the value and 
     *                  location of the desired cell to set
     *
     * \returns A size_t of the value which was just set 
     *
     */
    size_t setValue(Cell cell);


    /**
     * \brief Updates the possibilities list in every cell throughout the SudokuBoard
     *
     */
    void updatePossibilities();

    //data members
    Row rows_[9];
    Row columns_[9];
	//index reads row then column
    Square squares_[9];
private:

    /**
     * \brief Calculates the intersect between two linked lists
     *
     * \param list1     The first list 
     *
     * \param list2     The second list
     *
     * \returns A list containing the mathematical intersection of the two lists, 
     *           exclusively the values contained in both lists
     *
     * \note This function is used to consolidate the possibilities for each cell based on its row, column and square
     */
list<size_t> intersect(list<size_t> list1, list<size_t> list2);

};
#endif