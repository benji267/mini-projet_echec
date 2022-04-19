#include "bishop.h"
#include <stdlib.h>


Bishop::Bishop(Color color, const string &name, Square location) : Piece(color, name, location, bishop) {}
       



bool Bishop::is_moovement_legal(Square position, Square destination, int mvmt) {
        if(abs(destination.getLigne()-position.getLigne())>7 || abs(destination.getColonne()-position.getColonne())>7){
            cerr<<"Mouvement illégal"<<endl;
            return false;
        }
        else if(abs(destination.getLigne()-position.getLigne())-abs(destination.getColonne()-position.getColonne())==0){
            return true;

        }
        return false;
    }   