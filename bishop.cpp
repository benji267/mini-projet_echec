#include <iostream>
#include <piece.cpp>
#include <stdlib.h>
using namespace std;

/* diff de gap=0 */
class Bishop : public Piece{

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
        }
        if(abs(position_destination-position_origine)>7 || abs(destination.position[1]-origine.position[1])>7){
            return false;
        }
        else if(abs(position_destination-position_origine)-abs(destination.position[1]-origine.position[1])==0){
            return true;

        }
        return false;
    }   
};