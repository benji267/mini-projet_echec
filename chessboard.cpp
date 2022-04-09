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

    // allocation des pions
    for (unsigned char i(0); i < NBCOL; i++) {
        pionsb[i] = new Pawn(White, " \u2659 ", Square(1, i));
        pionsn[i] = new Pawn(Black, " \u265F ", Square(6, i));
    }
    // Pose des pieces en position initiale
    // pose des pieces blanches
    for (unsigned char i(0); i < NBCOL; i++) {
        // met à jour le tableau Chessboard, à la case
        // donnée par la position courante de la pièce
        // obtenue avec piecesb[i]->get_pos(), avec le
        // pointeur vers la pièce (piecesb[i])
        pose_piece(piecesb[i], piecesb[i]->get_pos());
        pose_piece(piecesn[i], piecesn[i]->get_pos());
        pose_piece(pionsn[i], pionsn[i]->get_pos());
        pose_piece(pionsb[i], pionsb[i]->get_pos());
    }
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