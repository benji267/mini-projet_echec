CC=g++
CFLAGS=-std=c++11 -Wall -g #-DDEBUG
EXE=echecs

SRC=echecs.cpp square.cpp chessboard.cpp piece.cpp game.cpp
OBJ=echecs.o  square.o  chessboard.o  piece.o  game.o

all: $(EXE)

$(EXE): $(OBJ)
	$(cpp) $(CFLAGS) $(OBJ)  -o $@

SUFFIXES:.cpp .o

echecs-main.o : echecs.cpp chessboard.cpp game.cpp
	$(cpp) $(CFLAGS) -c $<

game.o: game.cpp chessboard.h piece.h square.h
	$(cpp) $(CFLAGS) -c $<

chessboard.o : chessboard.cpp piece.h square.h
	$(cpp) $(CFLAGS) -c $<

piece.o: piece.cpp piece.h square.h chessboard.h
	$(cpp) $(CFLAGS) -c $<

square.o : square.cpp square.h
	$(cpp) $(CFLAGS) -c $<

doc: html/index.html
	doxygen

clean:
	rm -rf $(EXE) *.o *.dSYM *~ 
