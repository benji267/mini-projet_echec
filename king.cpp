#include <iostream>
#include <stdlib.h>

#include "piece.cpp"

using namespace std;

class King : public Piece{

    King(bool couleur, string nom_piece, Square square);
        ~King();

        King(bool couleur, string nom_piece, Square square){
            this->nom_piece=nom_piece;
        }

        King::~King(){
        }

    bool est_mouvement_legale(Square origine, Square destination){
        if(abs(destination.getLigne()-origine.getLigne())>7 || abs(destination.getColonne()-origine.getColonne())>7){
            cout<<"Mouvement illégal"<<endl;
            return false;
        }
        if(destination.getLigne()==origine.getLigne()){
            if(abs(origine.getColonne()-destination.getColonne())==1){
                return true;
            }
            
            else{
                cout<<"Mouvement illégal"<<endl;
                return false;
            }
        }
        if(origine.getColonne()==destination.getColonne()){
            if(abs(destination.getLigne()-origine.getLigne())==1){
                return true;
            }
            
            else{
                cout<<"Mouvement illégal"<<endl;
                return false;
            }
        }
        if(abs(origine.getColonne()-destination.getColonne())==1 && abs(origine.getLigne()-destination.getLigne())==1){
            return true;
        }
        cout<<"Mouvement illégal"<<endl;
        return false;
    }

};