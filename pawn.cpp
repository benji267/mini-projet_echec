#include "pawn.h"
#include <stdlib.h>


Pawn::Pawn(Color color, const string &name, Square location) : Piece(color, name, location, pawn){}


bool is_moovement_legal(Square position, Square destination){
        if(abs(destination.getLigne()-position.getLigne())>7 || abs(destination.getColonne()-position.getColonne())>7){
            cout<<"Mouvement illégal"<<endl;
            return false;
        }
        if(position.getLigne()==destination.getLigne())
            if(destination.getColonne()-position.getColonne()<=2){
                return true;
            }

            else{
                cout<<"Mouvement illégal"<<endl;
                return false;
            }
            
        else if(abs(destination.getLigne()-position.getLigne())==1){

            if((destination.getColonne()-position.getColonne())==1){
                return true;
            }

            else{
                cout<<"Mouvement illégal"<<endl;
                return false;
            }
        }

        else{
            cout<<"Mouvement illégal"<<endl;
            return false;
        }

    }
