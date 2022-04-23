#include "rook.h"
#include <stdlib.h>
using namespace std;



Rook::Rook(Color color, const string &name, Square location) : Piece(color, name, location, rook){}
       
bool Rook::is_moovement_legal(Square position, Square destination, int mvmt){
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
    
    else if(mvmt==3){
        if(has_moove){
            cerr<<" petit roque impossible"<<endl;
            return false;
        }
        else if(abs(destination.getLigne()-position.getLigne())==0
                &&
                abs(destination.getColonne()-position.getColonne())==2){
                    return true;
                }
    }

    else if(mvmt==4){
        if(has_moove){
            cerr<<" grand roque impossible"<<endl;
            return false;
        }
        else if(abs(destination.getLigne()-position.getLigne())==0
                &&
                abs(destination.getColonne()-position.getColonne())==3){
                    return true;
                }
    }
    return false;
}

