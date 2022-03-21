#include <iostream>
#include <stdlib.h>
#include "square.cpp"
#include "queen.cpp"
#include "king.cpp"
#include "knight.cpp"
#include "pawn.cpp"
#include "rook.cpp"
#include "bishop.cpp"


using namespace std;

class Echiquier{
// constructeur
    Echiquier::Echiquier () {

    alloc_mem_echiquier(); // --> alloue un tableau équivalent à un Piece *[8][8]
                           //     en initialisant les cases à nullptr 
                           //     et alloue des vecteurs piecesb, piecesn, pionsb
    // Constructeur (Couleur,nom_affiché, case)
    piecesb[0] = new Tour    (Blanc," \u2656 ",  Square(0,0));
    piecesb[1] = new Cavalier(Blanc," \u2658 ",  Square(0,1));
    piecesb[2] = new Fou     (Blanc," \u2657 ",  Square(0,2));
    piecesb[3] = new Dame    (Blanc," \u2655 ",  Square(0,3));
    piecesb[4] = new Roi     (Blanc," \u2654 ",  Square(0,4));
    piecesb[5] = new Fou     (Blanc," \u2657 ",  Square(0,5));
    piecesb[6] = new Cavalier(Blanc," \u2658 ",  Square(0,6));
    piecesb[7] = new Tour    (Blanc," \u2656 ",  Square(0,7));
    piecesn[0] = new Tour    (Noir, " \u265C ",  Square(7,0));
    piecesn[1] = new Cavalier(Noir, " \u265E ",  Square(7,1));
    piecesn[2] = new Fou     (Noir, " \u265D ",  Square(7,2));
    piecesn[3] = new Dame    (Noir, " \u265B ",  Square(7,3));
    piecesn[4] = new Roi     (Noir, " \u265A ",  Square(7,4));
    piecesn[5] = new Fou     (Noir, " \u265D ",  Square(7,5));
    piecesn[6] = new Cavalier(Noir, " \u265E ",  Square(7,6));
    piecesn[7] = new Tour    (Noir, " \u265C ",  Square(7,7));

    // allocation des pions
    for (unsigned char i(0);i<NBCOL;i++) {
         pionsb[i] =  new Pion(Blanc, " \u2659 ", Square(1,i));
         pionsn[i] =  new Pion(Noir,  " \u265F ", Square(6,i));
    }
    // Pose des pieces en position initiale
    // pose des pieces blanches
    for (unsigned char i(0);i<NBCOL;i++){
        // met à jour le tableau echiquier, à la case donnée par 
        // la position courante de la pièce obtenue avec 
        // piecesb[i]->get_pos(),
        // avec le pointeur vers la pièce (piecesb[i])
        pose_piece(piecesb[i],piecesb[i]->get_pos());
    }   

        // puis pose des pièces noires, pions blancs, pions noirs
        // ....
    }
};


void Echiquier::affiche () const {

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
