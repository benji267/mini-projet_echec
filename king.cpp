#include <stdlib.h>

#include "king.h"


King::King(Color color, const string &name, Square location) : Piece(color, name, location, king){}


        

    bool is_moovement_legal(Square position, Square destination){
        if(abs(destination.getLigne()-position.getLigne())>7 || abs(destination.getColonne()-position.getColonne())>7){
            cout<<"Mouvement illégal"<<endl;
            return false;
        }
        if(destination.getLigne()==position.getLigne()){
            if(abs(position.getColonne()-destination.getColonne())==1){
                return true;
            }
            
            else{
                cout<<"Mouvement illégal"<<endl;
                return false;
            }
        }
        if(position.getColonne()==destination.getColonne()){
            if(abs(destination.getLigne()-position.getLigne())==1){
                return true;
            }
            
            else{
                cout<<"Mouvement illégal"<<endl;
                return false;
            }
        }
        if(abs(position.getColonne()-destination.getColonne())==1 && abs(position.getLigne()-destination.getLigne())==1){
            return true;
        }
        cout<<"Mouvement illégal"<<endl;
        return false;
    }
