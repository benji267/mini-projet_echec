CC=g++
CFLAGS=-std=c++11 -Wall -g #-DDEBUG
EXE=chess

SRC=chess.cc square.cc chessboard.cc piece.cc game.cc
OBJ=chess.o  square.o  chessboard.o  piece.o  game.o

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -o $@

SUFFIXES:.cc .o

chess-main.o : chess.cc chessboard.cc game.cc
	$(CC) $(CFLAGS) -c $<

game.o: game.cc chessboard.h piece.h square.h
	$(CC) $(CFLAGS) -c $<

chessboard.o : chessboard.cc piece.h square.h
	$(CC) $(CFLAGS) -c $<

piece.o: piece.cc piece.h square.h chessboard.h
	$(CC) $(CFLAGS) -c $<

square.o : square.cc square.h
	$(CC) $(CFLAGS) -c $<

doc: html/index.html
	doxygen

clean:
	rm -rf $(EXE) *.o *.dSYM *~ 
