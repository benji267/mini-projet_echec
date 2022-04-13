#include "rook.h"
#include <stdlib.h>
using namespace std;



Rook::Rook(Color color, const string &name, Square location) : Piece(color, name, location, rook){}
       
bool Rook::is_moovement_legal(Square position, Square destination){
    if(position.getLigne()==destination.getLigne()){
        
        if(abs(position.getColonne()-destination.getColonne())>7){
            cout<<"Mouvement illégal"<<endl;
            return false;
        }

        else{
            return true;
        }
    }

    else if(position.getColonne()==destination.getColonne()){
        if(abs(destination.getLigne()-position.getLigne())>7){
            cout<<"Mouvement illégal"<<endl;
            return false;
        }

        else{
            return true;
        }
    }
}

