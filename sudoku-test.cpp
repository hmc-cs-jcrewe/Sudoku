/*
* \file sudoku-test.cpp
*
* \brief Tests a SudokuBoard and all related classes for correctness
* \remarks Only works in UNIX environments
*/

#include "testing-logger.hpp"
#include "Board.hpp"

#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include<cassert>
#include<iostream>
#include "signal.h"

//helper functions -- if necessary

//testing functions 

bool exampleTest()
{
	TestingLogger log("Example test");
	affirm(true);
	return log.summarize();
}


//Cell Tests


bool cellDefaultConstuctorTest()
{
	TestingLogger log("Cell Default Constructor Test");

	Cell testCell = Cell();
	list<size_t> pos = list<size_t>();
	for ( size_t i = 1; i < 10 ; ++i)
	{
		pos.push_back(i);
	}
	size_t testLocation[3];
	for (size_t i = 0; i < 3; ++i)
	{
		testLocation[i] = (size_t) 0;
	}

	affirm(testCell.empty_ == true);
	affirm(testCell.value_ == 0);
	for (size_t i = 0; i < 3; i++)
	{
		affirm(testCell.location_[i] == testLocation[i]);
	}
	affirm(testCell.possibilities_ == pos);
	affirm(testCell.possibilities_.size() == 9);

	return log.summarize();
}

bool cellValueConstructorTest()
{
	TestingLogger log("Cell Value Constructor Test");
	int value = 4;
	Cell testCell = Cell(value);

	list<size_t> pos = list<size_t>();
	pos.push_back(value);
	size_t testLocation[3] = { 0 ,0 ,0 };

	affirm(testCell.empty_ == false);
	affirm(testCell.value_ == (size_t)value);
	for ( size_t i = 0 ; i < 3; ++i)
	{
		affirm(testCell.location_[i] == testLocation[i]);
	}
	affirm(testCell.possibilities_ == pos);
	affirm(testCell.possibilities_.size() == 1);

	return log.summarize();

}

bool cellLocationConstructorTest()
{
	TestingLogger log("Cell Location Constructor Test");
	// sets the cell in the 1st row, 3rd column and first square
	//		ex: row < 10 ; col < 10 ; row and column intersect in square; value isn't already located in the row / col?

	size_t testLocation[3] = { 1 , 3, 1 };
	int value = 8;
	list<size_t> pos = list<size_t>();
	pos.push_back(value);

	Cell testCell = Cell(value, 1, 3, 1);

	affirm(testCell.empty_ == false);
	affirm(testCell.value_ = value);
	for(size_t i = 0; i < 3 ; ++i)
	{
		affirm(testCell.location_[i] == testLocation[i]);
	}	
	affirm(testCell.possibilities_ == pos);
	affirm(testCell.possibilities_.size() == 1);

	return log.summarize();
}

bool cellCopyConstructorTest()
{
	TestingLogger log("Cell Copy Constructor Test");

	Cell cell = Cell(3, 3, 4, 2);
	Cell testCell = Cell(cell);
	affirm(testCell.empty_ == cell.empty_);
	affirm(testCell.value_ == cell.value_);
	for (size_t i = 0; i < 3; ++i)
	{
		affirm(testCell.location_[i] == cell.location_[i]);
	}
	affirm(testCell.possibilities_ == cell.possibilities_);

	return log.summarize();
}

bool cellEqualsTest()
{
	TestingLogger log( "Cell Operator Equals Test");
	Cell cell1 = Cell();
	Cell cell2 = Cell();
	Cell cell3 = Cell(3);
	Cell cell4 = Cell(3, 0 , 0 , 1);
	Cell cell5 = Cell(3 , 0 , 0 ,1);

	affirm(cell1 == cell2);
	affirm(!(cell1 == cell3));
	affirm(!(cell1 == cell4));
	affirm(!(cell1 == cell5));
	affirm(!(cell2 == cell3));
	affirm(!(cell2 == cell4));
	affirm(!(cell2 == cell5));
	affirm(!(cell3 == cell4));
	affirm(!(cell3 == cell5));
	affirm(cell4 == cell5);

	return log.summarize();
}

bool cellAssignmentTest()
{
	TestingLogger log("Cell Assignment Operator Test");

	Cell baseCell = Cell();
	Cell testCell = baseCell;
	affirm(testCell == baseCell);

	Cell baseCell2 = Cell(3, 1, 1, 1);
	Cell testCell2 = baseCell2;
	affirm(testCell2 == baseCell2);
	affirm(!(testCell2 == baseCell));

	return log.summarize();
}

bool cellIsEmptyTest()
{
	TestingLogger log("Cell isEmpty Test");
	Cell testCell = Cell();
	affirm(testCell.isEmpty() == true);

	Cell testCell2 = Cell(4);
	affirm(testCell2.isEmpty() == false);

	return log.summarize();
}

bool cellGetValueTest()
{
	TestingLogger log("Cell getValue Test");
	Cell testCell = Cell();
	affirm(testCell.getValue() == 0);
	testCell.value_ = 3; 
	affirm(testCell.getValue() == (size_t)3);
	Cell testCell2 = Cell(7);
	affirm(testCell2.getValue() == 7);

	return log.summarize();
}

bool cellNumPossibilitiesTest()
{
	TestingLogger log("Cell numPossibilities Test");
	Cell testCell = Cell();
	affirm(testCell.numPossibilities() == 9);
	
	Cell testCell2 = Cell(4);
	affirm(testCell2.numPossibilities() == 1);

	return log.summarize();
}

//Row tests


bool rowDefaulConstructorTest()
{
	TestingLogger log("Row Default Constructor Test");
	Row testRow = Row();
	affirm(testRow.rowSize_ == 0);
	affirm(testRow.isCol_ == false);
	for (Cell cell : testRow.cells_)
	{
		affirm(cell.isEmpty() == true);
		affirm(cell.getValue() == 0);
		affirm(cell.numPossibilities() == 9);
	}
	return log.summarize();
}

bool rowListConstructorTest()
{
	TestingLogger log("Row List Constructor Test");
	Cell cell1 = Cell(1, 1, 0, 1);
	Cell cell2 = Cell(2, 1, 1, 1);
	Cell cell3 = Cell(3, 1, 2, 1);
	Cell cell4 = Cell(4, 1, 3, 4);
	Cell cell5 = Cell(5, 1, 4, 4);
	Cell cell6 = Cell(6, 1, 5, 4);
	Cell cell7 = Cell(7, 1, 6, 7);
	Cell cell8 = Cell(8, 1, 7, 7);
	Cell cell9 = Cell(9, 1, 8, 7);
	list<Cell> cellList = list<Cell>();
	cellList.push_back(cell1);
	cellList.push_back(cell2);
	cellList.push_back(cell3);
	cellList.push_back(cell4);
	cellList.push_back(cell5);
	cellList.push_back(cell6);
	cellList.push_back(cell7);
	cellList.push_back(cell8);
	cellList.push_back(cell9);
	bool isColumn = false;

	Row testRow = Row(cellList, isColumn);

	affirm(testRow.rowSize_ == 9);
	affirm(testRow.isCol_ == false);
	size_t j = 0;
	for (auto i = cellList.begin(); i != cellList.end(); ++i)
	{
		affirm(testRow.cells_[j].empty_ == (*i).empty_);
		affirm(testRow.cells_[j].isEmpty() == (*i).isEmpty());

		affirm(testRow.cells_[j].value_ == (*i).value_);
		
		for ( size_t k = 0; k < 3; ++k )
		{
			affirm(testRow.cells_[j].location_[k] == (*i).location_[k]);
		}
		affirm(testRow.cells_[j].possibilities_ == (*i).possibilities_);
		++j;
	}
	return log.summarize();
}

bool rowCopyConstructorTest()
{
	TestingLogger log("Row Copy Constructor Test");
	Cell cell1 = Cell(1, 1, 0, 1);
	Cell cell2 = Cell(2, 1, 1, 1);
	Cell cell3 = Cell(3, 1, 2, 1);
	Cell cell4 = Cell(4, 1, 3, 4);
	Cell cell5 = Cell(0, 1, 4, 4);
	Cell cell6 = Cell(6, 1, 5, 4);
	Cell cell7 = Cell(7, 1, 6, 7);
	Cell cell8 = Cell(0, 1, 7, 7);
	Cell cell9 = Cell(9, 1, 8, 7);
	list<Cell> cellList = list<Cell>();
	cellList.push_back(cell1);
	cellList.push_back(cell2);
	cellList.push_back(cell3);
	cellList.push_back(cell4);
	cellList.push_back(cell5);
	cellList.push_back(cell6);
	cellList.push_back(cell7);
	cellList.push_back(cell8);
	cellList.push_back(cell9);
	bool isColumn = false;

	Row baseRow = Row(cellList, isColumn);
	Row testRow = Row(baseRow);
	affirm(testRow.rowSize_ == baseRow.rowSize_);
	for (size_t i = 0; i < 9; ++i)
	{
		affirm(testRow.cells_[i].empty_ == baseRow.cells_[i].empty_);
		affirm(testRow.cells_[i].value_ == baseRow.cells_[i].value_);
		affirm(testRow.cells_[i].possibilities_ == baseRow.cells_[i].possibilities_);
		for (size_t k = 0; k < 3; ++k)
		{
			affirm(testRow.cells_[i].location_[k] == baseRow.cells_[i].location_[k]);
		}
	}

	list<Cell> cellList2 = list<Cell>();
	Cell newCell1 = Cell(5 , 1, 4, 4);
	Cell newCell2 = Cell(8,1,7,7);
	cellList2.push_back(cell1);
	cellList2.push_back(cell2);
	cellList2.push_back(cell3);
	cellList2.push_back(cell4);
	cellList2.push_back(newCell1);
	cellList2.push_back(cell6);
	cellList2.push_back(cell7);
	cellList2.push_back(newCell2);
	cellList2.push_back(cell9);

	Row baseRow2 = Row(cellList2, isColumn);
	Row testRow2 = Row(baseRow2);

	affirm(testRow2.rowSize_ == baseRow2.rowSize_);
	for (size_t i = 0; i < 9; ++i)
	{
		affirm(testRow2.cells_[i].empty_ == baseRow2.cells_[i].empty_);
		affirm(testRow2.cells_[i].value_ == baseRow2.cells_[i].value_);
		affirm(testRow2.cells_[i].possibilities_ == baseRow2.cells_[i].possibilities_);
		for (size_t k = 0; k < 3; ++k)
		{
			affirm(testRow2.cells_[i].location_[k] == baseRow2.cells_[i].location_[k]);
		}
	}
	return log.summarize();
}

bool rowEqualsTest()
{
	TestingLogger log ("Row Operator Equals Test");

	Row row1 = Row();
	Row row2 = Row();
	affirm(row1 == row2);
	affirm(row1.rowSize_ == row2.rowSize_);
	for (size_t i = 0; i < 9; ++i)
	{
		affirm(row1.cells_[i] == row2.cells_[i]);
	}

	Cell cell1 = Cell(4, 1 , 3, 5);
	row1.setValue(cell1);
	row2.setValue(cell1);

	affirm(row1 == row2);
	affirm(row1.rowSize_ == row2.rowSize_);
	for (size_t i = 0; i < 9; ++i)
	{
		affirm(row1.cells_[i] == row2.cells_[i]);
	}

	return log.summarize();
}

bool rowIsCompleteTest()
{
	TestingLogger log("Row is complete Test");

	Row row1 = Row();
	affirm(row1.isCompleteRow() == false);

	Cell cell1 = Cell(1, 1, 0, 1);
	Cell cell2 = Cell(2, 1, 1, 1);
	Cell cell3 = Cell(3, 1, 2, 1);
	Cell cell4 = Cell(4, 1, 3, 4);
	Cell cell5 = Cell(0, 1, 4, 4);
	Cell cell6 = Cell(6, 1, 5, 4);
	Cell cell7 = Cell(7, 1, 6, 7);
	Cell cell8 = Cell(0, 1, 7, 7);
	Cell cell9 = Cell(9, 1, 8, 7);
	list<Cell> cellList = list<Cell>();
	cellList.push_back(cell1);
	cellList.push_back(cell2);
	cellList.push_back(cell3);
	cellList.push_back(cell4);
	cellList.push_back(cell5);
	cellList.push_back(cell6);
	cellList.push_back(cell7);
	cellList.push_back(cell8);
	cellList.push_back(cell9);
	bool isColumn = false;

	Row row2 = Row(cellList, isColumn);
	affirm(row2.isCompleteRow() == false);

	list<Cell> cellList2 = list<Cell>();
	Cell newCell1 = Cell(5 , 1, 4, 4);
	Cell newCell2 = Cell(8,1,7,7);
	cellList2.push_back(cell1);
	cellList2.push_back(cell2);
	cellList2.push_back(cell3);
	cellList2.push_back(cell4);
	cellList2.push_back(newCell1);
	cellList2.push_back(cell6);
	cellList2.push_back(cell7);
	cellList2.push_back(newCell2);
	cellList2.push_back(cell9);

	Row row3 = Row(cellList2, isColumn);
	affirm(row3.isCompleteRow() == true);

	return log.summarize();
}

bool rowSetValueTest()
{
	TestingLogger log("Row Set Value Test");
	//Empty row 
	Row row1 = Row();
	Cell testCell = Cell(5, 7, 4, 8);
	row1.setValue(testCell);
	affirm(row1.cells_[4] == testCell);
	affirm(row1.cells_[7] == Cell());

	return log.summarize();
}

bool rowGetPossibilitiesTest()
{
	TestingLogger log("Row Get PossibilitiesTest Test");

	Row row1 = Row();
	list<size_t> pos = list<size_t>();
	for ( size_t i = 1; i < 10 ; ++i)
	{
		pos.push_back(i);
	}
	row1.getPossibilities();
	for ( size_t i = 0; i < 9; ++i)
	{
		affirm(row1.cells_[i].possibilities_ == pos);
	}
	Cell setVal = Cell(3, 4 , 5 , 5);
	row1.setValue(setVal);
	row1.getPossibilities();
	auto i = pos.begin(); //pointing at 1
	++i; 	//pointing at 2
	++i; 	//pointing at 3
	pos.erase(i);
	for ( size_t i = 0; i < 9; ++i)
	{
		if ( i == 5)
		{
			affirm(row1.cells_[i].possibilities_.size() == 1);
			affirm(row1.cells_[i].isEmpty() == false);
		}
		else 
		{
			affirm(row1.cells_[i].possibilities_ == pos);
		}
	}

	Cell setVal2 = Cell(2, 4 ,7 ,6);
	row1.setValue(setVal2);
	auto j = pos.begin();
	++j;
	pos.erase(j);

	row1.getPossibilities();

	for ( size_t i = 0; i < 9; ++i)
	{
		if ( i == 7 || i == 5)
		{
			affirm(row1.cells_[i].possibilities_.size() == 1);
			affirm(row1.cells_[i].isEmpty() == false);
		}
		else 
		{
			affirm(row1.cells_[i].possibilities_ == pos);				
		}
	}

	return log.summarize();
}

bool rowMinPossibilitiesTest()
{
	TestingLogger log("Row minPossibilities Test");
	Row row = Row();
	affirm(row.minPossibilities() == Cell());


	list<Cell> cellList = list<Cell>();
	Cell minCell = Cell(0, 1, 1, 2);
	minCell.possibilities_.remove(4);
	minCell.possibilities_.remove(2);
	minCell.possibilities_.remove(7);
	cellList.push_back(minCell);
	for (size_t i = 0; i < 4; ++i)
	{
		cellList.push_front(Cell());
		cellList.push_back(Cell());
	}
	Row testRow = Row(cellList, false);
	affirm(testRow.minPossibilities() == minCell);
	affirm((testRow.minPossibilities()).possibilities_ == minCell.possibilities_);

	return log.summarize();
}



//Square tests



bool squareDefaultConstructorTest()
{
	TestingLogger log("Square Default Constructor Test");
	Square testSquare = Square();
	affirm (testSquare.squareSize_ == 0);
	for (Cell cell : testSquare.cells_)
	{
		affirm(cell.isEmpty() == true);
		affirm(cell.getValue() == 0);
		affirm(cell.numPossibilities() == 9);
	}
	return log.summarize();
}

bool squareListConstructorTest()
{
	TestingLogger log("Square List Constructor Test");
	Cell cell1 = Cell(1, 1, 0, 1);
	Cell cell2 = Cell(2, 1, 1, 1);
	Cell cell3 = Cell(3, 1, 2, 1);
	Cell cell4 = Cell(4, 1, 3, 4);
	Cell cell5 = Cell(5, 1, 4, 4);
	Cell cell6 = Cell(6, 1, 5, 4);
	Cell cell7 = Cell(7, 1, 6, 7);
	Cell cell8 = Cell(8, 1, 7, 7);
	Cell cell9 = Cell(9, 1, 8, 7);
	list<Cell> cellList = list<Cell>();
	cellList.push_back(cell1);
	cellList.push_back(cell2);
	cellList.push_back(cell3);
	cellList.push_back(cell4);
	cellList.push_back(cell5);
	cellList.push_back(cell6);
	cellList.push_back(cell7);
	cellList.push_back(cell8);
	cellList.push_back(cell9);

	Square testSquare = Square(cellList);

	affirm(testSquare.squareSize_ == 9);
	size_t j = 0;
	for (auto i = cellList.begin(); i != cellList.end(); ++i)
	{
		affirm(testSquare.cells_[j] == (*i));
		++j;
	}
	return log.summarize();
}

bool squareCopyConstructorTest()
{
	TestingLogger log("Square List Constructor Test");

	Cell cell1 = Cell(1, 1, 0, 1);
	Cell cell2 = Cell(2, 1, 1, 1);
	Cell cell3 = Cell(3, 1, 2, 1);
	Cell cell4 = Cell(4, 1, 3, 4);
	Cell cell5 = Cell(5, 1, 4, 4);
	Cell cell6 = Cell(6, 1, 5, 4);
	Cell cell7 = Cell(7, 1, 6, 7);
	Cell cell8 = Cell(8, 1, 7, 7);
	Cell cell9 = Cell(9, 1, 8, 7);
	list<Cell> cellList = list<Cell>();
	cellList.push_back(cell1);
	cellList.push_back(cell2);
	cellList.push_back(cell3);
	cellList.push_back(cell4);
	cellList.push_back(cell5);
	cellList.push_back(cell6);
	cellList.push_back(cell7);
	cellList.push_back(cell8);
	cellList.push_back(cell9);

	Square baseSquare = Square(cellList);
	
	Square testSquare  = Square(baseSquare);
	affirm (testSquare.squareSize_ == baseSquare.squareSize_);
	for (size_t i = 0; i < 9; ++i)
	{
		affirm(testSquare.cells_[i] == baseSquare.cells_[i]);
	}

	return log.summarize();

}

bool squareEqualsTest()
{
	TestingLogger log("Square Operator Equals Test");
	Square square1 = Square();
	Square square2 = Square();
	affirm(square1 == square2);

	Cell cell1 = Cell(1 , 0 , 0, 1);
	square1.setValue(cell1);
	square2.setValue(cell1);

	affirm(square1 == square2);
	return log.summarize();
}

bool squareAssignmentTest()
{
	TestingLogger log("Square Assignment Operator");
	Square square1 = Square();
	Square square2 = square1;
	affirm(square1 == square2);
	Cell cell1 = Cell(1 , 1 , 0 , 1);
	square1.setValue(cell1);
	Square square3 = square1;
	affirm(square1 == square3);
	return log.summarize();
}

bool squareIsCompleteTest()
{
	TestingLogger log("Square isComplete Test");

	Square square1 = Square();
	affirm(square1.isCompleteSquare() == false);

	Cell cell1 = Cell(1, 1, 0, 1);
	Cell cell2 = Cell(2, 1, 1, 1);
	Cell cell3 = Cell(3, 1, 2, 1);
	Cell cell4 = Cell(4, 1, 3, 4);
	Cell cell5 = Cell(0, 1, 4, 4);
	Cell cell6 = Cell(6, 1, 5, 4);
	Cell cell7 = Cell(7, 1, 6, 7);
	Cell cell8 = Cell(8, 1, 7, 7);
	Cell cell9 = Cell(9, 1, 8, 7);
	list<Cell> cellList = list<Cell>();
	cellList.push_back(cell1);
	cellList.push_back(cell2);
	cellList.push_back(cell3);
	cellList.push_back(cell4);
	cellList.push_back(cell5);
	cellList.push_back(cell6);
	cellList.push_back(cell7);
	cellList.push_back(cell8);
	cellList.push_back(cell9);

	Square testSquare = Square(cellList);
	affirm(testSquare.isCompleteSquare() == false);
	testSquare.cells_[4] = Cell(5,1,4,4);
	affirm(testSquare.isCompleteSquare() == true);

	return log.summarize();
}

bool squareSetValueTest()
{
	TestingLogger log("Square setValue Test");
	Square testSquare = Square();

	Cell testCell = Cell(3 , 1 , 2 , 1);
	affirm(testSquare.setValue(testCell) == 3);
	affirm(testSquare.squareSize_ == 1);
	affirm(testSquare.cells_[5] == testCell);

	Cell testCell2 = Cell(4,0,2,1);
	affirm(testSquare.setValue(testCell2) == 4);
	affirm(testSquare.squareSize_ == 2);
	affirm(testSquare.cells_[2] == testCell2);

	Cell testCell3 = Cell(1, 0 , 0 , 1);
	affirm(testSquare.setValue(testCell3) == 1);
	affirm(testSquare.squareSize_ == 3);
	affirm(testSquare.cells_[0] == testCell3);

	Cell testCell4 = Cell(7, 2 ,2 ,1);
	affirm(testSquare.setValue(testCell4) == 7);
	affirm(testSquare.squareSize_ == 4);
	affirm(testSquare.cells_[8] == testCell4);
	
	Cell testCell5 = Cell (4, 2 , 1, 1);
	affirm(testSquare.setValue(testCell5) == 4);
	affirm(testSquare.squareSize_ == 5);
	affirm(testSquare.cells_[7] == testCell5);
	affirm(!(testSquare.cells_[8] ==testCell5));

	return log.summarize();
}

bool squareGetPossibilitiesTest()
{
	TestingLogger log("Square Get Possibilities Test");

	list<size_t> pos = list<size_t>();
	for(size_t i = 1; i < 10; ++i) 
	{
		pos.push_back(i);
	}

	Square square1 = Square();
	square1.getPossibilities();
	for(size_t i = 0; i < 9; ++i)
	{
		affirm(square1.cells_[i].possibilities_ == pos);
	}
	
	Cell setVal = Cell(2 , 0 , 0 , 1);
	square1.setValue(setVal);
	
	auto i = pos.begin(); // points at 1
	++i;				  // points at 2
	pos.erase(i);

	square1.getPossibilities();

	for(size_t i = 0; i < 9; ++i)
	{
		if (i == 0)
		{
			affirm(square1.cells_[i].possibilities_.size() == 1);
			affirm(square1.cells_[i].getValue() == 2);
			affirm(square1.cells_[i].isEmpty() == false);
		} else {
			affirm(square1.cells_[i].possibilities_ == pos);
		}
	}

	Cell setVal2 = Cell (4, 2 , 1, 1);
	square1.setValue(setVal2);

	auto j = pos.begin(); // pointing at 1
	++j; 				  // pointing at 3
	++j;				  // pointing at 4
	pos.erase(j);

	square1.getPossibilities();
	
	for (size_t i = 0 ; i < 9; ++i)
	{
		if (i == 0)
		{
			affirm(square1.cells_[i].possibilities_.size() == 1);
			affirm(square1.cells_[i].getValue() == 2);
			affirm(square1.cells_[i].isEmpty() == false);
		}
		else if ( i == 7)
		{
			affirm(square1.cells_[i].possibilities_.size() == 1);
			affirm(square1.cells_[i].getValue() == 4);
			affirm(square1.cells_[i].isEmpty() == false);
		} else {
			affirm(square1.cells_[i].possibilities_ == pos);
		}
	}

	return log.summarize();
}


//BoardTests


bool boardDefaultConstructorTest()
{
	TestingLogger log( "Board Default Constructor Test");
	SudokuBoard testBoard = SudokuBoard();
	Cell defaultCell = Cell();
	for (size_t i = 0; i < 9; ++i)
	{
		for (Cell testCell : (testBoard.getRow(i)).cells_)
		{
			affirm(testCell.possibilities_ == defaultCell.possibilities_);
		}
		for (Cell testCell : (testBoard.getRow(i)).cells_)
		{
			affirm(testCell.possibilities_ == defaultCell.possibilities_);
		}
		for (Cell testCell : testBoard.getSquare(i).cells_)
		{
			affirm(testCell.possibilities_ == defaultCell.possibilities_);
		}
	}
	
	return log.summarize();
}

bool boardCellConstructorTest()
{
	TestingLogger log ("Board Cell Constructor Test");
	//Create all 81 cells -- first test of empty board
	Cell cells[81];
	for(size_t i = 0; i < 81; ++i)
	{
		cells[i] = Cell();
	}


	SudokuBoard testBoard1 = SudokuBoard(cells);	
	affirm(testBoard1.rows_[0] == Row());
	affirm(testBoard1.rows_[1] == Row());
	affirm(testBoard1.rows_[2] == Row());
	affirm(testBoard1.rows_[3] == Row());
	affirm(testBoard1.rows_[4] == Row());
	affirm(testBoard1.rows_[5] == Row());
	affirm(testBoard1.rows_[6] == Row());
	affirm(testBoard1.rows_[7] == Row());
	affirm(testBoard1.rows_[8] == Row());

	affirm(testBoard1.squares_[0] == Square());
	affirm(testBoard1.squares_[1] == Square());
	affirm(testBoard1.squares_[2] == Square());
	affirm(testBoard1.squares_[3] == Square());
	affirm(testBoard1.squares_[4] == Square());
	affirm(testBoard1.squares_[5] == Square());
	affirm(testBoard1.squares_[6] == Square());
	affirm(testBoard1.squares_[7] == Square());
	affirm(testBoard1.squares_[8] == Square());



	Cell cells2[81];
	for ( size_t i  = 0; i < 81; ++i )
	{
		cells2[i] = Cell();
	}

	//firt row
	cells2[0] = Cell (1 , 0 , 0 , 1);
	cells2[1] = Cell (2 , 0 , 1 , 1);
	cells2[2] = Cell (3 , 0 , 2 , 1);
	cells2[3] = Cell (4 , 0 , 3 , 2);
	cells2[4] = Cell (5 , 0 , 4 , 2);
	cells2[5] = Cell (6 , 0 , 5 , 2);
	cells2[6] = Cell (7 , 0 , 6 , 3);
	cells2[7] = Cell (8 , 0 , 7 , 3);
	cells2[8] = Cell (9 , 0 , 8 , 3);
 	// random cells scattered throughout 
	cells2[13] = Cell (6 , 1 , 4 , 2);
	cells2[18] = Cell (6 , 2 , 0 , 1);
	cells2[57] = Cell (4 , 6 , 3 , 8);
	
	SudokuBoard testBoard2 = SudokuBoard(cells2);	

	affirm(testBoard2.rows_[3] == Row());
	affirm(testBoard2.rows_[4] == Row());
	affirm(testBoard2.rows_[5] == Row());
	affirm(testBoard2.rows_[7] == Row());
	affirm(testBoard2.rows_[8] == Row());
					
					
	affirm(testBoard2.squares_[3] == Square());
	affirm(testBoard2.squares_[4] == Square());
	affirm(testBoard2.squares_[5] == Square());
	affirm(testBoard2.squares_[6] == Square());
	affirm(testBoard2.squares_[8] == Square());
					
	affirm(testBoard2.rows_[0].cells_[0] == Cell (1, 0, 0, 1));
	affirm(testBoard2.rows_[0].cells_[1] == Cell (2, 0, 1, 1));
	affirm(testBoard2.rows_[0].cells_[2] == Cell (3, 0, 2, 1));
	affirm(testBoard2.rows_[0].cells_[3] == Cell (4, 0, 3, 2));
	affirm(testBoard2.rows_[0].cells_[4] == Cell (5, 0, 4, 2));
	affirm(testBoard2.rows_[0].cells_[5] == Cell (6, 0, 5, 2));
	affirm(testBoard2.rows_[0].cells_[6] == Cell (7, 0, 6, 3));
	affirm(testBoard2.rows_[0].cells_[7] == Cell (8, 0, 7, 3));
	affirm(testBoard2.rows_[0].cells_[8] == Cell (9, 0, 8, 3));
					
	affirm(testBoard2.rows_[1].cells_[4] == Cell (6 , 1 , 4 , 2));
	affirm(testBoard2.rows_[2].cells_[0] == Cell (6 , 2 , 0 , 1));
	affirm(testBoard2.rows_[6].cells_[3] == Cell (4 , 6 , 3 , 8));
					
	affirm(testBoard2.columns_[0].cells_[0] == Cell(1, 0, 0, 1));
	affirm(testBoard2.columns_[1].cells_[0] == Cell(2, 0, 1, 1));
	affirm(testBoard2.columns_[2].cells_[0] == Cell(3, 0, 2, 1));
	affirm(testBoard2.columns_[3].cells_[0] == Cell(4, 0, 3, 2));
	affirm(testBoard2.columns_[4].cells_[0] == Cell(5, 0, 4, 2));
	affirm(testBoard2.columns_[5].cells_[0] == Cell(6, 0, 5, 2));
	affirm(testBoard2.columns_[6].cells_[0] == Cell(7, 0, 6, 3));
	affirm(testBoard2.columns_[7].cells_[0] == Cell(8, 0, 7, 3));
	affirm(testBoard2.columns_[8].cells_[0] == Cell(9, 0, 8, 3));
					
	affirm(testBoard2.columns_[4].cells_[1] == Cell(6, 1, 4, 2));
	affirm(testBoard2.columns_[0].cells_[2] == Cell(6, 2, 0, 1));
	affirm(testBoard2.columns_[3].cells_[6] == Cell(4, 6, 3, 8));
					
	affirm(testBoard2.squares_[0].cells_[0] == Cell(1, 0, 0, 1));
	affirm(testBoard2.squares_[0].cells_[1] == Cell(2, 0, 1, 1));
	affirm(testBoard2.squares_[0].cells_[2] == Cell(3, 0, 2, 1));
	affirm(testBoard2.squares_[1].cells_[0] == Cell(4, 0, 3, 2));
	affirm(testBoard2.squares_[1].cells_[1] == Cell(5, 0, 4, 2));
	affirm(testBoard2.squares_[1].cells_[2] == Cell(6, 0, 5, 2));
	affirm(testBoard2.squares_[2].cells_[0] == Cell(7, 0, 6, 3));
	affirm(testBoard2.squares_[2].cells_[1] == Cell(8, 0, 7, 3));
	affirm(testBoard2.squares_[2].cells_[2] == Cell(9, 0, 8, 3));
					
	affirm(testBoard2.squares_[1].cells_[4] == Cell(6, 1, 4, 2));
	affirm(testBoard2.squares_[0].cells_[6] == Cell(6, 2, 0, 1));
	affirm(testBoard2.squares_[7].cells_[0] == Cell(4, 6, 3, 8));

	return log.summarize();
}

bool boardCopyConstructorTest()	
{
	TestingLogger log("Board Copy Constructor Test");

	Cell cells2[81];
	for (size_t i = 0; i < 81; ++i)
	{
		cells2[i] = Cell();
	}
	//firt row
	cells2[0] = Cell(1, 0, 0, 1);
	cells2[1] = Cell(2, 0, 1, 1);
	cells2[2] = Cell(3, 0, 2, 1);
	cells2[3] = Cell(4, 0, 3, 2);
	cells2[4] = Cell(5, 0, 4, 2);
	cells2[5] = Cell(6, 0, 5, 2);
	cells2[6] = Cell(7, 0, 6, 3);
	cells2[7] = Cell(8, 0, 7, 3);
	cells2[8] = Cell(9, 0, 8, 3);
	// random cells scattered throughout 
	cells2[13] = Cell(6, 1, 4, 2);
	cells2[18] = Cell(6, 2, 0, 1);
	cells2[57] = Cell(4, 6, 3, 8);

	SudokuBoard baseBoard = SudokuBoard(cells2);

	SudokuBoard testBoard = SudokuBoard(baseBoard);
	for (size_t i = 0; i < 9; ++i)
	{
		affirm(testBoard.rows_[i] == baseBoard.rows_[i]);
		affirm(testBoard.columns_[i] == baseBoard.columns_[i]);
		affirm(testBoard.squares_[i] == baseBoard.squares_[i]);
	}

	affirm(testBoard == baseBoard);

	return log.summarize();
}

bool boardGetRowTest()
{
	TestingLogger log("Board Get Row Test");


	Cell cells2[81];
	for (size_t i = 0; i < 81; ++i)
	{
		cells2[i] = Cell();
	}
	//firt row
	cells2[0] = Cell(1, 0, 0, 1);
	cells2[1] = Cell(2, 0, 1, 1);
	cells2[2] = Cell(3, 0, 2, 1);
	cells2[3] = Cell(4, 0, 3, 2);
	cells2[4] = Cell(5, 0, 4, 2);
	cells2[5] = Cell(6, 0, 5, 2);
	cells2[6] = Cell(7, 0, 6, 3);
	cells2[7] = Cell(8, 0, 7, 3);
	cells2[8] = Cell(9, 0, 8, 3);
	// random cells scattered throughout 
	cells2[13] = Cell(6, 1, 4, 2);
	cells2[18] = Cell(6, 2, 0, 1);
	cells2[57] = Cell(4, 6, 3, 8);

	list<Cell> cells = list<Cell>();
	for (size_t i = 0; i < 9; ++i)
	{
		cells.push_back(cells2[i]);
	}
	SudokuBoard testBoard = SudokuBoard(cells2);
	affirm(testBoard.getRow(0) == Row(cells, false));
	Row testRow = Row(cells, false);
	list<Cell> cells3 = list<Cell>();
	
	cells3.push_back(cells2[18]);
	for (size_t i = 0; i < 8; ++i)
	{
		cells3.push_back(Cell());
	}

	Row row3 = Row(cells3, false);

	affirm(testBoard.getRow(2) == row3);

	return log.summarize();
	
}

bool boardGetColumnTest()
{
	TestingLogger log("Board getColumn Test");

	SudokuBoard board = SudokuBoard();


	Cell cells2[81];
	for (size_t i = 0; i < 81; ++i)
	{
		cells2[i] = Cell();
	}
	cells2[0] = Cell(1, 0, 0, 1);
	cells2[1] = Cell(2, 1, 0, 1);
	cells2[2] = Cell(3, 2, 0, 1);
	cells2[3] = Cell(4, 3, 0, 4);
	cells2[4] = Cell(5, 4, 0, 4);
	cells2[5] = Cell(6, 5, 0, 4);
	cells2[6] = Cell(7, 6, 0, 7);
	cells2[7] = Cell(8, 7, 0, 7);
	cells2[8] = Cell(9, 8, 0, 7);
	// random cells scattered throughout 
	cells2[13] = Cell(6, 1, 4, 2);
	cells2[57] = Cell(4, 6, 3, 8);

	list<Cell> cells = list<Cell>();
	for (size_t i = 0; i < 9; ++i)
	{
		cells.push_back(cells2[i]);
	}
	SudokuBoard testBoard = SudokuBoard(cells2);
	affirm(testBoard.getCol(0) == Row(cells, true));


	return log.summarize();
}

bool boardGetSquareTest()
{
	TestingLogger log("Board getSquare Test");

	Cell cells[81];
	for (size_t i = 0; i < 81; ++i)
	{
		cells[i] = Cell();
	}
	//make the first square
	list<Cell> cellList = list<Cell>();
	cells[0] = (Cell(1, 0, 0, 1));
	cells[1] = (Cell(2, 0, 1, 1));
	cells[2] = (Cell(3, 0, 2, 1));
	cells[3] = (Cell(4, 1, 0, 1));
	cells[4] = (Cell(5, 1, 1, 1));
	cells[5] = (Cell(6, 1, 2, 1));
	cells[6] = (Cell(7, 2, 0, 1));
	cells[7] = (Cell(8, 2, 1, 1));
	cells[8] = (Cell(9, 2, 2, 1));
	for (size_t i = 0; i < 9; ++i)
	{
		cellList.push_back(cells[i]);
	}

	Square testSquare = Square(cellList);
	SudokuBoard board2 = SudokuBoard(cells);
	affirm(board2.getSquare(0) == testSquare);
	affirm(board2.getSquare(1) == Square());
	affirm(board2.getSquare(2) == Square());
	affirm(board2.getSquare(3) == Square());
	affirm(board2.getSquare(4) == Square());
	affirm(board2.getSquare(5) == Square());
	affirm(board2.getSquare(6) == Square());
	affirm(board2.getSquare(7) == Square());
	affirm(board2.getSquare(8) == Square());

	return log.summarize();
}

bool boardIsCompleteTest()
{
	TestingLogger log ("Board Complete Test");

	SudokuBoard empty = SudokuBoard();
	affirm(!empty.isComplete());

	Cell cells[81]; 
	cells[0] = Cell(1, 0 , 0 , 1);
	for (size_t i = 1; i < 81; ++i)
	{
		cells[i] = Cell();
	}
	
	SudokuBoard singleCell = SudokuBoard(cells);
	affirm(!singleCell.isComplete());

	Cell cells2[81]; 
	//first column
	cells2[0] = Cell(1 , 0 , 0 , 1);
	cells2[9] = Cell(2 , 1 , 0 , 1);
	cells2[18] = Cell(3 , 2 , 0 , 1);
	cells2[27] = Cell(4 , 3 , 0 , 4);
	cells2[36] = Cell(5 , 4 , 0 , 4);
	cells2[45] = Cell(6 , 5 , 0 , 4);
	cells2[54] = Cell(7 , 6 , 0 , 7);
	cells2[63] = Cell(8 , 7 , 0 , 7);
	cells2[72] = Cell(9 , 8 , 0 , 7);

	//second column
	cells2[0 + 1] = Cell(2, 0 , 1 , 1);
	cells2[9 + 1] = Cell(3, 1 , 1 , 1);
	cells2[18 + 1] = Cell(4, 2 , 1 , 1);
	cells2[27 + 1] = Cell(5, 3 , 1 , 4);
	cells2[36 + 1] = Cell(6, 4 , 1 , 4);
	cells2[45 + 1] = Cell(7, 5 , 1 , 4);
	cells2[54 + 1] = Cell(8, 6 , 1 , 7);
	cells2[63 + 1] = Cell(9, 7 , 1 , 7);
	cells2[72 + 1] = Cell(1, 8 , 1 , 7);

	//third column
	cells2[0 + 2] = Cell(3, 0 , 2 , 1);
	cells2[9 + 2] = Cell(4, 1 , 2 , 1);
	cells2[18 + 2] = Cell(5, 2 , 2 , 1);
	cells2[27 + 2] = Cell(6, 3 , 2 , 4);
	cells2[36 + 2] = Cell(7, 4 , 2 , 4);
	cells2[45 + 2] = Cell(8, 5 , 2 , 4);
	cells2[54 + 2] = Cell(9, 6 , 2 , 7);
	cells2[63 + 2] = Cell(1, 7 , 2 , 7);
	cells2[72 + 2] = Cell(2, 8 , 2 , 7);

	//fourth column
	cells2[0 + 3] = Cell(1 + 3 , 0 , 3 , 1 + 1);
	cells2[9 + 3] = Cell(2 + 3 , 1 , 3 , 1 + 1);
	cells2[18 + 3] = Cell(3 + 3, 2 , 3 , 1 + 1);
	cells2[27 + 3] = Cell(4 + 3, 3 , 3 , 4 + 1);
	cells2[36 + 3] = Cell(5 + 3, 4 , 3 , 4 + 1);
	cells2[45 + 3] = Cell(6 + 3, 5 , 3 , 4 + 1);
	cells2[54 + 3] = Cell(1, 6 , 3 , 7 + 1);
	cells2[63 + 3] = Cell(2, 7 , 3 , 7 + 1);
	cells2[72 + 3] = Cell(3, 8 , 3 , 7 + 1);

	//fifth column
	cells2[0 + 4] = Cell(1 + 4 , 0 , 4 , 1 + 1);
	cells2[9 + 4] = Cell(2 + 4 , 1 , 4 , 1 + 1);
	cells2[18 + 4] = Cell(3 + 4, 2 , 4 , 1 + 1);
	cells2[27 + 4] = Cell(4 + 4, 3 , 4 , 4 + 1);
	cells2[36 + 4] = Cell(5 + 4, 4 , 4 , 4 + 1);
	cells2[45 + 4] = Cell(1, 5 , 4 , 4 + 1);
	cells2[54 + 4] = Cell(2,  6 , 4 , 7 + 1);
	cells2[63 + 4] = Cell(3, 7 , 4 , 7 + 1);
	cells2[72 + 4] = Cell(4, 8 , 4 , 7 + 1);

	//sixth column
	cells2[0 + 5] = Cell(1 + 5 , 0 , 5 , 1 + 1);
	cells2[9 + 5] = Cell(2 + 5 , 1 , 5 , 1 + 1);
	cells2[18 + 5] = Cell(3 + 5, 2 , 5 , 1 + 1);
	cells2[27 + 5] = Cell(4 + 5, 3 , 5 , 4 + 1);
	cells2[36 + 5] = Cell(1, 4 , 5 , 4 + 1);
	cells2[45 + 5] = Cell(2, 5 , 5 , 4 + 1);
	cells2[54 + 5] = Cell(3, 6 , 5 , 7 + 1);
	cells2[63 + 5] = Cell(4, 7 , 5 , 7 + 1);
	cells2[72 + 5] = Cell(5, 8 , 5 , 7 + 1);

	//seventh column
	cells2[0 + 6] = Cell(1 + 6 , 0 , 6 , 1 + 2);
	cells2[9 + 6] = Cell(2 + 6 , 1 , 6 , 1 + 2);
	cells2[18 + 6] = Cell(3 + 6, 2 , 6 , 1 + 2);
	cells2[27 + 6] = Cell(1, 3 , 6 , 4 + 2);
	cells2[36 + 6] = Cell(2, 4 , 6 , 4 + 2);
	cells2[45 + 6] = Cell(3, 5 , 6 , 4 + 2);
	cells2[54 + 6] = Cell(4, 6 , 6 , 7 + 2);
	cells2[63 + 6] = Cell(5, 7 , 6 , 7 + 2);
	cells2[72 + 6] = Cell(6, 8 , 6 , 7 + 2);

	//eigth column
	cells2[0 + 7] = Cell(1 + 7 , 0 , 7 , 1 + 2);
	cells2[9 + 7] = Cell(2 + 7 , 1 , 7 , 1 + 2);
	cells2[18 + 7] = Cell(1, 2 , 7 , 1 + 2);
	cells2[27 + 7] = Cell(2, 3 , 7 , 4 + 2);
	cells2[36 + 7] = Cell(3, 4 , 7 , 4 + 2);
	cells2[45 + 7] = Cell(4, 5 , 7 , 4 + 2);
	cells2[54 + 7] = Cell(5, 6 , 7 , 7 + 2);
	cells2[63 + 7] = Cell(6, 7 , 7 , 7 + 2);
	cells2[72 + 7] = Cell(7, 8 , 7 , 7 + 2);

	//ninth column
	cells2[0 + 8] = Cell(1 + 8 , 0 , 8 , 1 + 2);
	cells2[9 + 8] = Cell(1 , 1 , 8 , 1 + 2);
	cells2[18 + 8] = Cell(2, 2 , 8 , 1 + 2);
	cells2[27 + 8] = Cell(3, 3 , 8 , 4 + 2);
	cells2[36 + 8] = Cell(4, 4 , 8 , 4 + 2);
	cells2[45 + 8] = Cell(5, 5 , 8 , 4 + 2);
	cells2[54 + 8] = Cell(6, 6 , 8 , 7 + 2);
	cells2[63 + 8] = Cell(7, 7 , 8 , 7 + 2);
	cells2[72 + 8] = Cell(8, 8 , 8 , 7 + 2);

	SudokuBoard fullBoard = SudokuBoard(cells2);
	affirm(fullBoard.isComplete());

	return log.summarize();
}

bool boardSetValueTest()
{
	TestingLogger log ("Board Set Value Test");

	Cell cells[81];
	for (size_t i = 0; i < 81; ++i)
	{
		cells[i] = Cell();
	}
	SudokuBoard empty = SudokuBoard(cells);
	Cell input1 = Cell (2 , 0 , 1 , 1);
	affirm (empty.setValue(input1) == 2);
	affirm(empty.rows_[0].cells_[1] == input1);
	affirm(empty.columns_[1].cells_[0] == input1);
	affirm(empty.squares_[0].cells_[1] == input1);

	Cell input2 = Cell (6 , 4 , 7 , 6);
	affirm(empty.setValue(input2) == 6);
	affirm(empty.rows_[4].cells_[7] == input2);
	affirm(empty.columns_[7].cells_[4] == input2);
	affirm(empty.squares_[5].cells_[4] == input2);

	return log.summarize();
}
bool boardUpdatePossibilitiesTest()
{
	TestingLogger log("Board boardUpdatePossibilitiesTest");

	list<size_t> possibilities; 
	for (size_t i = 1; i < 10; ++i)
	{
		possibilities.push_back(i);
	}

	Cell cells[81];
	for (size_t i = 0; i < 81; ++i)
	{
		cells[i] = Cell();
	}
	SudokuBoard empty = SudokuBoard(cells);

	for (size_t i = 0; i < 9; ++ i)
	{
		for (size_t j = 0; j < 9; ++j )
		{
			affirm(empty.rows_[i].cells_[j].possibilities_ == possibilities);
			affirm(empty.columns_[i].cells_[j].possibilities_ == possibilities);
			affirm(empty.squares_[i].cells_[j].possibilities_ == possibilities);
		}
	}

	Cell input1 = Cell (2 , 0 , 1 , 1);
	empty.setValue(input1);
	possibilities.remove(2);
	empty.updatePossibilities();



	Cell input3 = Cell (1 , 0 , 0 , 1);
	empty.setValue(input3);
	empty.updatePossibilities();

	Cell cells20 = Cell (1, 0 , 0 , 1);
	Cell cells29 = Cell(2 , 1 , 0 , 1);
	Cell cells218 = Cell(3 , 2 , 0 , 1);
	Cell cells227 = Cell(4 , 3 , 0 , 4);
	Cell cells236 = Cell(5 , 4 , 0 , 4);
	Cell cells245 = Cell(6 , 5 , 0 , 4);
	Cell cells254 = Cell(7 , 6 , 0 , 7);
	Cell cells263 = Cell(8 , 7 , 0 , 7);
	Cell cells272 = Cell(9 , 8 , 0 , 7);

	empty.setValue(cells29);
	empty.setValue(cells218);
	empty.setValue(cells227);
	empty.setValue(cells236);
	empty.setValue(cells245);
	empty.setValue(cells254);
	empty.setValue(cells263);
	empty.setValue(cells272);

	//second column
	cells29  = Cell(3, 1 , 1 , 1);
	cells218 = Cell(4, 2 , 1 , 1);
	cells227 = Cell(5, 3 , 1 , 4);
	cells236 = Cell(6, 4 , 1 , 4);
	cells245 = Cell(7, 5 , 1 , 4);
	cells254 = Cell(8, 6 , 1 , 7);
	cells263 = Cell(9, 7 , 1 , 7);
	cells272 = Cell(1, 8 , 1 , 7);

	empty.setValue(cells29);
	empty.setValue(cells218);
	empty.setValue(cells227);
	empty.setValue(cells236);
	empty.setValue(cells245);
	empty.setValue(cells254);
	empty.setValue(cells263);
	empty.setValue(cells272);

	//third column
	cells20 = Cell(3, 0 , 2 , 1);
	cells29 = Cell(4, 1 , 2 , 1);
	cells218 = Cell(5, 2 , 2 , 1);
	cells227 = Cell(6, 3 , 2 , 4);
	cells236 = Cell(7, 4 , 2 , 4);
	cells245 = Cell(8, 5 , 2 , 4);
	cells254 = Cell(9, 6 , 2 , 7);
	cells263 = Cell(1, 7 , 2 , 7);
	cells272 = Cell(2, 8 , 2 , 7);

	empty.setValue(cells20);
	empty.setValue(cells29);
	empty.setValue(cells218);
	empty.setValue(cells227);
	empty.setValue(cells236);
	empty.setValue(cells245);
	empty.setValue(cells254);
	empty.setValue(cells263);
	empty.setValue(cells272);

	//fourth column
	cells20 = Cell(1 + 3 , 0 , 3 , 1 + 1);
	cells29 = Cell(2 + 3 , 1 , 3 , 1 + 1);
	cells218 = Cell(3 + 3, 2 , 3 , 1 + 1);
	cells227 = Cell(4 + 3, 3 , 3 , 4 + 1);
	cells236 = Cell(5 + 3, 4 , 3 , 4 + 1);
	cells245 = Cell(6 + 3, 5 , 3 , 4 + 1);
	cells254 = Cell(1, 6 , 3 , 7 + 1);
	cells263 = Cell(2, 7 , 3 , 7 + 1);
	cells272 = Cell(3, 8 , 3 , 7 + 1);

	empty.setValue(cells20);
	empty.setValue(cells29);
	empty.setValue(cells218);
	empty.setValue(cells227);
	empty.setValue(cells236);
	empty.setValue(cells245);
	empty.setValue(cells254);
	empty.setValue(cells263);
	empty.setValue(cells272);

	//fifth column
	cells20 = Cell(1 + 4 , 0 , 4 , 1 + 1);
	cells29 = Cell(2 + 4 , 1 , 4 , 1 + 1);
	cells218 = Cell(3 + 4, 2 , 4 , 1 + 1);
	cells227 = Cell(4 + 4, 3 , 4 , 4 + 1);
	cells236 = Cell(5 + 4, 4 , 4 , 4 + 1);
	cells245 = Cell(1, 5 , 4 , 4 + 1);
	cells254 = Cell(2,  6 , 4 , 7 + 1);
	cells263 = Cell(3, 7 , 4 , 7 + 1);
	cells272 = Cell(4, 8 , 4 , 7 + 1);

	empty.setValue(cells20);
	empty.setValue(cells29);
	empty.setValue(cells218);
	empty.setValue(cells227);
	empty.setValue(cells236);
	empty.setValue(cells245);
	empty.setValue(cells254);
	empty.setValue(cells263);
	empty.setValue(cells272);

	//sixth column
	cells20 = Cell(1 + 5 , 0 , 5 , 1 + 1);
	cells29 = Cell(2 + 5 , 1 , 5 , 1 + 1);
	cells218 = Cell(3 + 5, 2 , 5 , 1 + 1);
	cells227 = Cell(4 + 5, 3 , 5 , 4 + 1);
	cells236 = Cell(1, 4 , 5 , 4 + 1);
	cells245 = Cell(2, 5 , 5 , 4 + 1);
	cells254 = Cell(3, 6 , 5 , 7 + 1);
	cells263 = Cell(4, 7 , 5 , 7 + 1);
	cells272 = Cell(5, 8 , 5 , 7 + 1);

	empty.setValue(cells20);
	empty.setValue(cells29);
	empty.setValue(cells218);
	empty.setValue(cells227);
	empty.setValue(cells236);
	empty.setValue(cells245);
	empty.setValue(cells254);
	empty.setValue(cells263);
	empty.setValue(cells272);

	//seventh column
	cells20 = Cell(1 + 6 , 0 , 6 , 1 + 2);
	cells29 = Cell(2 + 6 , 1 , 6 , 1 + 2);
	cells218 = Cell(3 + 6, 2 , 6 , 1 + 2);
	cells227 = Cell(1, 3 , 6 , 4 + 2);
	cells236 = Cell(2, 4 , 6 , 4 + 2);
	cells245 = Cell(3, 5 , 6 , 4 + 2);
	cells254 = Cell(4, 6 , 6 , 7 + 2);
	cells263 = Cell(5, 7 , 6 , 7 + 2);
	cells272 = Cell(6, 8 , 6 , 7 + 2);

	empty.setValue(cells20);
	empty.setValue(cells29);
	empty.setValue(cells218);
	empty.setValue(cells227);
	empty.setValue(cells236);
	empty.setValue(cells245);
	empty.setValue(cells254);
	empty.setValue(cells263);
	empty.setValue(cells272);

	//eigth column
	cells20 = Cell(1 + 7 , 0 , 7 , 1 + 2);
	cells29 = Cell(2 + 7 , 1 , 7 , 1 + 2);
	cells218 = Cell(1, 2 , 7 , 1 + 2);
	cells227 = Cell(2, 3 , 7 , 4 + 2);
	cells236 = Cell(3, 4 , 7 , 4 + 2);
	cells245 = Cell(4, 5 , 7 , 4 + 2);
	cells254 = Cell(5, 6 , 7 , 7 + 2);
	cells263 = Cell(6, 7 , 7 , 7 + 2);
	cells272 = Cell(7, 8 , 7 , 7 + 2);

	empty.setValue(cells20);
	empty.setValue(cells29);
	empty.setValue(cells218);
	empty.setValue(cells227);
	empty.setValue(cells236);
	empty.setValue(cells245);
	empty.setValue(cells254);
	empty.setValue(cells263);
	empty.setValue(cells272);

	//ninth column
	cells20 = Cell(1 + 8 , 0 , 8 , 1 + 2);
	cells29 = Cell(1 , 1 , 8 , 1 + 2);
	cells218 = Cell(2, 2 , 8 , 1 + 2);
	cells227 = Cell(3, 3 , 8 , 4 + 2);
	cells236 = Cell(4, 4 , 8 , 4 + 2);
	cells245 = Cell(5, 5 , 8 , 4 + 2);
	cells254 = Cell(6, 6 , 8 , 7 + 2);
	cells263 = Cell(7, 7 , 8 , 7 + 2);
	cells272 = Cell(8, 8 , 8 , 7 + 2);

	empty.setValue(cells20);
	empty.setValue(cells29);
	empty.setValue(cells218);
	empty.setValue(cells227);
	empty.setValue(cells236);
	empty.setValue(cells245);
	empty.setValue(cells254);
	empty.setValue(cells263);
	empty.setValue(cells272);

	empty.updatePossibilities();
	
	affirm (empty.isComplete());
	return log.summarize();
}



// --------------------------
//		Running the tests
// --------------------------


int main()
{
	//Initialize testing environment 

	TestingLogger alltests{ "All tests" };

	// Add all calls to tests here 
	affirm(exampleTest());   
	affirm(cellDefaultConstuctorTest());
	affirm(cellValueConstructorTest());
	affirm(cellLocationConstructorTest());
	affirm(cellCopyConstructorTest());
	affirm(cellEqualsTest());
	affirm(cellIsEmptyTest());
	affirm(cellGetValueTest());
	affirm(cellNumPossibilitiesTest());
	affirm(cellAssignmentTest());
	affirm(rowDefaulConstructorTest());
	affirm(rowListConstructorTest());
	affirm(rowCopyConstructorTest());
	affirm(rowEqualsTest());
	affirm(rowIsCompleteTest());
	affirm(rowSetValueTest());
	affirm(rowGetPossibilitiesTest());
	affirm(rowMinPossibilitiesTest());
	affirm(squareDefaultConstructorTest());
	affirm(squareListConstructorTest());
	affirm(squareCopyConstructorTest());
	affirm(squareEqualsTest());
	affirm(squareAssignmentTest());
	affirm(squareIsCompleteTest());
	affirm(squareSetValueTest());
	affirm(squareGetPossibilitiesTest());
	affirm(boardDefaultConstructorTest());
	affirm(boardCellConstructorTest());
	affirm(boardCopyConstructorTest());
	affirm(boardGetRowTest());
	affirm(boardGetColumnTest());
	affirm(boardGetSquareTest());
	affirm(boardIsCompleteTest());
	affirm(boardSetValueTest());
	affirm(boardUpdatePossibilitiesTest());

	if (alltests.summarize(true))
	{
		return 0;	//exit code 0 = success
	}
	else
	{
		return 2;	// exit code of 2 means failure 
	}
}