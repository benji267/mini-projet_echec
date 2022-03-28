#include <iostream>
#include "piece.cpp"
#include <stdlib.h>
using namespace std;

/* diff de gap=0 */
class Bishop : public Piece{

    Bishop(bool couleur, string nom_piece, Square square);
        ~Bishop();

        Bishop(bool couleur, string nom_piece, Square square){
            this->nom_piece=nom_piece;
        }

        Bishop::~Bishop(){
        }

    bool est_mouvement_legal(Square origine, Square destination){
        if(abs(destination.getLigne()-origine.getLigne())>7 || abs(destination.getColonne()-origine.getColonne())>7){
            cout<<"Mouvement illégal"<<endl;
            return false;
        }
        else if(abs(destination.getLigne()-origine.getLigne())-abs(destination.getColonne()-origine.getColonne())==0){
            return true;

        }
        return false;
    }   
};