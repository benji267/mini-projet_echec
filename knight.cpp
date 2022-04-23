#include "knight.h"
#include <stdlib.h>


Knight::Knight(Color color, const string &name, Square location) : Piece(color, name, location, knight) {}


bool Knight::is_moovement_legal(Square position, Square destination) {
    if(abs(destination.getLigne()-position.getLigne())>7 || abs(destination.getColonne()-position.getColonne())>7){
        cout<<"Mouvement illégal"<<endl;
        return false;
    }
    if(abs(position.getColonne()-destination.getColonne())%2==0 || abs(destination.getLigne()-position.getLigne())%2==0){
        if(abs(position.getColonne()-destination.getColonne())+abs(destination.getLigne()-position.getLigne())==3){
            return true;
        }
    }
    cout<<"Mouvement illégal"<<endl;
    return false;  
}