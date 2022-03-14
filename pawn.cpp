#include <iostream>
#include <piece.cpp>
#include <stdlib.h>
using namespace std;

class Pawn : public Piece{

    bool est_mouvement_legal(Square origine, Square destination){
        string chaine="abcdefgh";
        int position_origine;
        int position_destination;
        for(int k=0;k<7;k++){
            if(origine.position[0]==chaine.at(k)){
                position_origine=k+1;
        }
            else if(destination.position[0]==chaine.at(k)){
                position_destination=k+1;
            }
        if(origine.position[0]==destination.position[0])
            if(destination.position[1]-origine.position[1]<=2){
                return true;
            }

            else{
                cout<<"Mouvement illégal"<<endl;
                return false;
            }
            
        else if(abs(position_destination-position_origine)==1){

            if((destination.position[1]-origine.position[1])==1){
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
    }

};