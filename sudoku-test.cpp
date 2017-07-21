/*
* \file sudoku-test.cpp
*
* \brief Tests a SudokuBoard and all related classes for correctness
*/

#include "testing-logger.hpp"
#include "Board.hpp"

#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include<cassert>
#include "signal.h"

//helper functions -- if necessary

//testing functions 

bool exampleTest()
{
	throw new exception();
}
//Cell Tests


bool cellDefaultConstuctorTest()
{
	TestingLogger log("Cell Default Constructor Test");

	Cell testCell = Cell();
	list<size_t> pos = list<size_t>();
	for ( size_t i = 0; i < 10 ; ++i)
	{
		pos.push_back(i);
	}
	size_t testLocation[3] = { 0 , 0 , 0 };

	affirm(testCell.empty_ == true);
	affirm(testCell.value_ == 0);
	affirm(testCell.location_ == testLocation);
	affirm(testCell.possibilities_ == pos);
	affirm(testCell.possibilities_.size() == 10);
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
	affirm(testCell.value_ == value);
	affirm(testCell.location_ == testLocation);
	affirm(testCell.possibilities_ == pos);
	affirm(testCell.possibilities_.size() == 1);

}

bool cellLocationConstructorTest()
{
	TestingLogger log("Cell Location Constructor Test");
	// sets the cell in the 1st row, 3rd column and first square
	// TODO -- place limits in the constructor that make sense with the board
	//		ex: row < 10 ; col < 10 ; row and column intersect in sqaure; value isn't already located in the row / col?

	//TODO -- fix this and the value constructor
	size_t testLocation[3] = { 1 , 3, 1 };
	int value = 8;
	list<size_t> pos = list<size_t>();
	pos.push_back(value);

	Cell testCell = Cell(value, 1, 3, 1);

	affirm(testCell.empty_ == false);
	affirm(testCell.value_ = value);
	affirm(testCell.location_ == testLocation);
	affirm(testCell.possibilities_ == pos);
	affirm(testCell.possibilities_.size() == 1);
}

bool cellCopyConstructorTest()
{
	TestingLogger log("Cell Default Constructor Test");

	Cell cell = Cell(3, 3, 4, 2);
	Cell testCell = Cell(cell);
	affirm(testCell.empty_ == cell.empty_);
	affirm(testCell.value_ == cell.value_);
	affirm(testCell.location_ == cell.location_);
	affirm(testCell.possibilities_ == cell.possibilities_);
}

bool cellIsEmptyTest()
{
	TestingLogger log("Cell isEmpty Test");
	Cell testCell = Cell();
	affirm(testCell.isEmpty() == true);
	testCell.empty_ == false;
	affirm(testCell.isEmpty() == false);

	Cell testCell2 = Cell(4);
	affirm(testCell2.isEmpty() == false);
}

bool cellGetValueTest()
{
	TestingLogger log("Cell getValue Test");
	Cell testCell = Cell();
	affirm(testCell.getValue() == 0);
	testCell.value_ = 3; 
	affirm(testCell.getValue == 3);
	Cell testCell2 = Cell(7);
	affirm(testCell2.getValue() == 7);
}

bool cellNumPossibilitiesTest()
{
	TestingLogger log("Cell numPossibilities Test");
	Cell testCell = Cell();
	affirm(testCell.numPossibilities() == 10);
	
	Cell testCell2 = Cell(4);
	affirm(testCell2.numPossibilities() == 1);
}

//Row tests
bool rowDefaulConstructorTest()
{
	throw new exception();
}

bool rowListConstructorTest()
{
	throw new exception();
}

bool rowCopyConstructorTest()
{
	throw new exception();
}

bool rowIsCompleteTest()
{
	throw new exception();
}

bool rowGetPossibilitiesTest()
{
	throw new exception();
}

bool rowSetValueTest()
{
	throw new exception();
}

//Square tests
bool squareDefaultConstructorTest()
{
	throw new exception();
}

bool squareListConstructorTest()
{
	throw new exception();
}

bool squareCopyConstructorTest()
{
	throw new exception();
}

bool squareIsCompleteTest()
{
	throw new exception();
}

bool squareGetPossibilitiesTest()
{
	throw new exception();
}

//BoardTests
bool boardDefaultConstructorTest()
{
	throw new exception();
}

bool boardCellConstructorTest()
{
	throw new exception();
}

bool boardCopyConstructorTest()
{
	throw new exception();
}

bool boardGetRowTest()
{
	throw new exception();
}

bool boardGetColumnTest()
{
	throw new exception();
}

bool boardGetSquareTest()
{
	throw new exception();
}

bool boardMakeRowTest()
{
	throw new exception();
}

bool boardMakeSquareTest()
{
	throw new exception();
}

bool boardIsCompleteTest()
{
	throw new exception();
}

bool boardInValidSolutionTest()
{
	throw new exception();
}

bool boardUpdatePossibilitiesTest()
{
	throw new exception();
}



// --------------------------
//		Running the tests
// --------------------------

// Called if the tests run too long
// taken from 

int main(int argc, char** argv)
{
	//Initialize testing environment 

	TestingLogger alltests{ "All tests" };

	// Add all calls to tests here 
	affirm(exampleTest());   
	affirm(cellDefaultConstuctorTest());
	affirm(cellValueConstructorTest());
	affirm(cellLocationConstructorTest());
	affirm(cellCopyConstructorTest());
	affirm(cellIsEmptyTest());
	affirm(cellGetValueTest());
	affirm(cellNumPossibilitiesTest());
	affirm(rowDefaulConstructorTest());
	affirm(rowListConstructorTest());
	affirm(rowCopyConstructorTest());
	affirm(rowIsCompleteTest());
	affirm(rowGetPossibilitiesTest());
	affirm(rowSetValueTest());
	affirm(squareDefaultConstructorTest());
	affirm(squareListConstructorTest());
	affirm(squareCopyConstructorTest());
	affirm(squareIsCompleteTest());
	affirm(squareGetPossibilitiesTest());
	affirm(boardDefaultConstructorTest());
	affirm(boardCellConstructorTest());
	affirm(boardCopyConstructorTest());
	affirm(boardGetRowTest());
	affirm(boardGetColumnTest());
	affirm(boardGetSquareTest());
	affirm(boardMakeRowTest());
	affirm(boardMakeSquareTest());
	affirm(boardIsCompleteTest());
	affirm(boardInValidSolutionTest());
	affirm(boardUpdatePossibilitiesTest());

	if (alltests.summarize(true))
	{
		return 0;	//exit code 0 = success
	}
	else
	{
		return 2;	// arbitratily chosen 
					// exit code of 2 means failure 
	}
}