CC=g++
CFLAGS=-std=c++11 -Wall -g #-DDEBUG
EXE=echecs

SRC=echecs.cpp square.cpp chessboard.cpp piece.cpp game.cpp
OBJ=echecs.o  square.o  chessboard.o  piece.o  game.o

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -o $@

SUFFIXES:.cpp .o

echecs-main.o : echecs.cpp chessboard.cpp game.cpp
	$(CC) $(CFLAGS) -c $<

game.o: game.cpp chessboard.h piece.h square.h
	$(CC) $(CFLAGS) -c $<

chessboard.o : chessboard.cpp piece.h square.h
	$(CC) $(CFLAGS) -c $<

piece.o: piece.cpp piece.h square.h chessboard.h
	$(CC) $(CFLAGS) -c $<

square.o : square.cpp square.h
	$(CC) $(CFLAGS) -c $<

doc: html/index.html
	doxygen

clean:
	rm -rf $(EXE) *.o *.dSYM *~ 
