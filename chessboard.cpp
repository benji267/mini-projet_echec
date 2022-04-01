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
using namespace std;



enum class Color{White, Black};

class Echiquier{
public:
  Echiquier();
  ~Echiquier();

private:
  Square *tab[8][8];


Echiquier::Echiquier() {
  for (unsigned i = 0; i < 8; i++) {
    for (unsigned j = 0; j < 8; j++) {
      tab[i][j] = new Square(8,8);
    }
  }
}

Echiquier::~Echiquier() {
  for (unsigned i = 0; i < 8; i++) {
    for (unsigned j = 0; j < 8; j++) {
      delete tab[i][j];
    }
  }
}

  void alloc_mem_echiquier(){

    Square *tab[8][8];
    vector <int> piecesb;
    vector <int> piecesn;
    vector <int> pionsb;
    vector <int> pionsn;
    int i;
    int j;
    for(i=0; i<8; i++){
      for(j=0; j<8; j++){
        tab[i][j]=nullptr;
      }
    }
  }

    Echiquier() {

    alloc_mem_echiquier(); // --> alloue un tableau équivalent à un Piece *[8][8]
                           //     en initialisant les cases à nullptr 
                           //     et alloue des vecteurs piecesb, piecesn, pionsb
    // Constructeur (Couleur,nom_affiché, case)
    Rook piece = new Rook    (Color::White," \u2656 ",  Square(0,0));
    Knight piece= new Knight (Color::White," \u2658 ",  Square(0,1));
    Bishop piece = new Bishop     (Color::White," \u2657 ",  Square(0,2));
    Queen piece = new Queen    (Color::White," \u2655 ",  Square(0,3));
    King piece = new King     (Color::White," \u2654 ",  Square(0,4));
    Bishop piece = new Bishop     (Color::White," \u2657 ",  Square(0,5));
    Knight piece= new Knight (Color::White," \u2658 ",  Square(0,6));
    Rook piece = new Rook    (Color::White," \u2656 ",  Square(0,7));
    Rook piece [0] = new Rook    (Color::Black, " \u265C ",  Square(7,0));
    Knight piece[1] = new Knight (Color::Black, " \u265E ",  Square(7,1));
    Bishop piece[2] = new Bishop     (Color::Black, " \u265D ",  Square(7,2));
    Queen piece[3] = new Queen    (Color::Black, " \u265B ",  Square(7,3));
    King piece[4] = new King     (Color::Black, " \u265A ",  Square(7,4));
    Bishop piece[5] = new Bishop     (Color::Black, " \u265D ",  Square(7,5));
    Knight piece[6] = new Knight (Color::Black, " \u265E ",  Square(7,6));
    Rook piece [7] = new Rook    (Color::Black, " \u265C ",  Square(7,7));

    // allocation des pions
    for (unsigned char i(0);i<NBCOL;i++) {
         pionsb[i] =  new Pion(White, " \u2659 ", Square(1,i));
         pionsn[i] =  new Pion(Black,  " \u265F ", Square(6,i));
    }
    // Pose des pieces en position initiale
    // pose des pieces Whitehes
    for (unsigned char i(0);i<NBCOL;i++){
        // met à jour le tableau echiquier, à la case donnée par 
        // la position courante de la pièce obtenue avec 
        // piecesb[i]->get_pos(),
        // avec le pointeur vers la pièce (piecesb[i])
        pose_piece(piecesb[i],piecesb[i]->get_pos());
    }   

        // puis pose des pièces Blackes, pions Whites, pions Blacks
        // ....
    }tab
};


void affiche () const {

        string space5 = string(5,' ');
        cout << endl;
        cout << "     a     b     c     d     e     f     g     h    "<< endl;
        cout << "  +-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
        for (int i(NBCOL-1);i>=0;i--) {
                cout << i+1 << " "; // numérotation ligne dans affichage
                for (int j(0);j<NBCOL;j++) {
                        cout << "|" ;
                        if (echiquier[i][j]) { 
                          cout << "\u0020\u0020";  //U+0020 est un esapce utf-8 taille police
                          echiquier[i][j]-> affiche();
                          cout << "\u0020" << " ";
                        }
                        else 
                                cout << space5;  // 2 ascii spaces
                }
                cout << "|\n  +-----+-----+-----+-----+-----+-----+-----+-----+";
                cout << endl;
        }
}
