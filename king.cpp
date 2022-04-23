#include "king.h"
#include <stdlib.h>
using namespace std;



King::King(Color color, const string &name, Square location) : Piece(color, name, location, king){}


        

    bool is_moovement_legal(Square position, Square destination, int mvmt){
        if(abs(destination.getLigne()-position.getLigne())>7 || abs(destination.getColonne()-position.getColonne())>7){
            cout<<"Mouvement illégal"<<endl;
            return false;
        }
        if(mvmt=2){
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
        cout<<"Mouvement illégal"<<endl;
        return false;
    }
