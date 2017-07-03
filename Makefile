# Makefile for ChunkySting Tester
# 
# As usual, you can build this software by typing
#
#     make
#

# ----- Make Macros -----

CXXFLAGS    =	-g -stdlib=libc++ -std=c++11 -Wall -Wextra -pedantic 
CXX	    =	clang++
TARGETS 	    =	board solver
BOARD_OBJS     =	board.o cell.o row.o square.o
SOLVER_OBJS    =    solver.o board.o row.o square.o cell.o 
ALL_OBJS	    =   $(BOARD_OBJS) $(SOLVER_OBJS)

LIBS        =   -ldl -rdynamic -stdlib=libc++

# ----- Make Rules -----

all:	$(TARGETS)

board:	$(BOARD_OBJS)
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -o $@ -lpthread $(BOARD_OBJS) \
		$(LIBS)

solver: $(SOLVER_OBJS)
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -o $@ -lpthread $(SOLVER_OBJS) \
		$(LIBS)

clean:
	rm -f $(TARGETS) $(ALL_OBJS)

# ---- Dependencies (generated by typing ``clang++ -MM *.cpp'') ----

board.o: board.cpp board.hpp
cell.o: cell.cpp cell.hpp
square.o: square.cpp square.hpp
row.o: row.cpp row.hpp
solver.o: solver.cpp board.cpp board.hpp
