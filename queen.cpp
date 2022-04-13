#include "queen.h"
#include <stdlib.h>
using namespace std;

Queen::Queen(Color color, const string &name, Square location) : Piece(color, name, location, queen){}

bool Queen::is_moovement_legal(Square origine, Square destination){
        if(abs(origine.getLigne()-destination.getLigne())>7 || abs(destination.getColonne()-origine.getColonne())>7){
            cout<<"Mouvement illégal"<<endl;
            return false;
        }
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
        else if(abs(destination.getLigne()-origine.getLigne())-abs(destination.getColonne()-origine.getColonne())==0){
            return true;
        }

    cout<<"Mouvement illégal"<<endl;
    return false;
}
