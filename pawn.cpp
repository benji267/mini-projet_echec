#include <iostream>
#include "piece.cpp"
#include <stdlib.h>
using namespace std;

class Pawn : public Piece{

    Pawn(Color couleur, string nom_piece, Square square);
        ~Pawn();

        Pawn(Color couleur, string nom_piece, Square square){
            this->nom_piece=nom_piece;
        }

        Pawn::~Pawn(){
        }

    bool est_mouvement_legal(Square origine, Square destination){
        if(abs(destination.getLigne()-origine.getLigne())>7 || abs(destination.getColonne()-origine.getColonne())>7){
            cerr<<"Mouvement illégal"<<endl;
            return false;
        }
        if(origine.getLigne()==destination.getLigne())
            if(destination.getColonne()-origine.getColonne()<=2){
                return true;
            }

            else{
                cerr<<"Mouvement illégal"<<endl;
                return false;
            }
            
        else if(abs(destination.getLigne()-origine.getLigne())==1){

            if((destination.getColonne()-origine.getColonne())==1){
                return true;
            }

            else{
                cerr<<"Mouvement illégal"<<endl;
                return false;
            }
        }

        else{
            cerr<<"Mouvement illégal"<<endl;
            return false;
        }

    }

};