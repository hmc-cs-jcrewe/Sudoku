#ifndef SOLVER_H
#define SOLVER_H
using namespace std;
#include "Board.hpp"
class solver
{
public:
    solver() = default;
    ~solver() = default;
    SudokuBoard solve(SudokuBoard board);
};
#endif // SOLVER_H
