#include <iostream>
#include "piece.cpp"
#include <stdlib.h>
using namespace std;

class Knight : public Piece{

    Knight(Color couleur, string nom_piece, Square square);
        ~Knight();

        Knight(Color couleur, string nom_piece, Square square){
            this->nom_piece=nom_piece;
        }

        Knight::~Knight(){
        }
    
    bool est_mouvement_legal(Square origine, Square destination){
        if(abs(destination.getLigne()-origine.getLigne())>7 || abs(destination.getColonne()-origine.getColonne())>7){
            cerr<<"Mouvement illégal"<<endl;
            return false;
        }
        if(abs(origine.getColonne()-destination.getColonne())%2==0 || abs(destination.getLigne()-origine.getLigne())%2==0){
            if(abs(origine.getColonne()-destination.getColonne())+abs(destination.getLigne()-origine.getLigne())==3){
                return true;
            }
        }
        cerr<<"Mouvement illégal"<<endl;
        return false;  
    }
};