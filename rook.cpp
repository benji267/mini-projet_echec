#include <iostream>
#include "piece.cpp"
#include <stdlib.h>
using namespace std;


class Rook : public Piece{

    bool est_mouvement_legal(Square origine, Square destination){
        if(origine.getLigne()==destination.getLigne()){
            
            if(abs(origine.getColonne()-destination.getColonne())>7){
                cout<<"Mouvement illégal"<<endl;
                return false;
            }

            else{
                return true;
            }
        }

        else if(origine.getColonne()==destination.getColonne()){

            if(abs(destination.getLigne()-origine.getLigne())>7){
                cout<<"Mouvement illégal"<<endl;
                return false;
            }

            else{
                return true;
            }
        }
    }

};