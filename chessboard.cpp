#include <iostream>
#include <vector>
#include <stdlib.h>
#include "square.cpp"
#include "queen.cpp"
#include "king.cpp"
#include "knight.cpp"
#include "pawn.cpp"
#include "rook.cpp"
#include "bishop.cpp"
#include "chessboard.h"
using namespace std;

#define NBCOL 8






   Chessboard::Chessboard() {

    chessboard= new Piece**[8];

    for(int i=0; i<8; i++){
        chessboard[i]=new Piece*[8];
        for(int j=0; j<8; j++){
            chessboard[i][j]=nullptr;
        }
    }

    chessboard[0][0] = new Rook(White, " \u2656 ", Square(0, 0));
    chessboard[0][1] = new Knight(White, " \u2658 ", Square(0, 1));
    chessboard[0][2] = new Bishop(White, " \u2657 ", Square(0, 2));
    chessboard[0][3] = new Queen(White, " \u2655 ", Square(0, 3));
    chessboard[0][4] = new King(White, " \u2654 ", Square(0, 4));
    chessboard[0][5] = new Bishop(White, " \u2657 ", Square(0, 5));
    chessboard[0][6] = new Knight(White, " \u2658 ", Square(0, 6));
    chessboard[0][7] = new Rook(White, " \u2656 ", Square(0, 7));
    chessboard[7][0] = new Rook(Black, " \u265C ", Square(7, 0));
    chessboard[7][1] = new Knight(Black, " \u265E ", Square(7, 1));
    chessboard[7][2] = new Bishop(Black, " \u265D ", Square(7, 2));
    chessboard[7][3] = new Queen(Black, " \u265B ", Square(7, 3));
    chessboard[7][4] = new King(Black, " \u265A ", Square(7, 4));
    chessboard[7][5] = new Bishop(Black, " \u265D ", Square(7, 5));
    chessboard[7][6] = new Knight(Black, " \u265E ", Square(7, 6));
    chessboard[7][7] = new Rook(Black, " \u265C ", Square(7, 7));

    for(int i=0; i<8; i++){
        chessboard[1][i] = new Pawn(White, " \u2659 ", Square(1, i));
        chessboard[6][i] = new Pawn(Black, " \u265F ", Square(6, i));
}


Chessboard::~Chessboard(){}

void Chessboard::remove_piece(Square location){
    chessboard[location.getLigne()][location.getColonne()]=nullptr;
    }
}

Piece* Chessboard::get_piece(Square location) const{
    if(location.getLigne()<0 && location.getLigne()>7 && location.getColonne()<0 && location.getColonne()>7){
        return chessboard[location.getLigne()][location.getColonne()];;
    }
    return nullptr;
}







void Chessboard::affiche() {

    string space5 = string(5, ' ');
    cout << endl;
    cout << "     a     b     c     d     e     f     "
            "g    "
            " h    "
         << endl;
    cout << "  "
            "+-----+-----+-----+-----+-----+-----+-----"
            "+---"
            "--+"
         << endl;
    for (int i(NBCOL - 1); i >= 0; i--) {
        cout << i + 1 << " "; // numérotation ligne dans affichage
        for (int j(0); j < NBCOL; j++) {
            cout << "|";
            if (chessboard[i][j]) {
                cout << "\u0020"; // U+0020 est un esapce
                                  // utf-8 taille police
                chessboard[i][j]->affiche();
                cout << "\u0020";
            } else
                cout << space5; // 2 ascii spaces
        }
        cout << "|\n  "
                "+-----+-----+-----+-----+-----+-----+-"
                "----"
                "+-----+";
        cout << endl;
    }
}


