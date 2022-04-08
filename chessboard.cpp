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




class Chessboard{

   Chessboard::Chessboard() {

    chessboard= new Piece**[8];

    chessboard[0][0] = new Rook(Color::White, " \u2656 ", Square(0, 0));
    piecesb[1] = new Knight(Color::White, " \u2658 ", Square(0, 1));
    piecesb[2] = new Bishop(Color::White, " \u2657 ", Square(0, 2));
    piecesb[3] = new Queen(Color::White, " \u2655 ", Square(0, 3));
    piecesb[4] = new Kiœ(Color::White, " \u2654 ", Square(0, 4));
    piecesb[5] = new Bishop(Color::White, " \u2657 ", Square(0, 5));
    piecesb[6] = new Knight(Color::White, " \u2658 ", Square(0, 6));
    piecesb[7] = new Rook(Color::White, " \u2656 ", Square(0, 7));
    piecesn[0] = new Rook(Color::Black, " \u265C ", Square(7, 0));
    piecesn[1] = new Knight(Color::Black, " \u265E ", Square(7, 1));
    piecesn[2] = new Bishop(Color::Black, " \u265D ", Square(7, 2));
    piecesn[3] = new Queen(Color::Black, " \u265B ", Square(7, 3));
    piecesn[4] = new Kiœ(Color::Black, " \u265A ", Square(7, 4));
    piecesn[5] = new Bishop(Color::Black, " \u265D ", Square(7, 5));
    piecesn[6] = new Knight(Color::Black, " \u265E ", Square(7, 6));
    piecesn[7] = new Rook(Color::Black, " \u265C ", Square(7, 7));

    // allocation des pions
    for (unsigned char i(0); i < NBCOL; i++) {
        pionsb[i] = new Pawn(Color::White, " \u2659 ", Square(1, i));
        pionsn[i] = new Pawn(Color::Black, " \u265F ", Square(6, i));
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
