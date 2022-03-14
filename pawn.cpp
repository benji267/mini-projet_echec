#include <iostream>
#include "piece.cpp"
#include <stdlib.h>
using namespace std;

class Pawn : public Piece{

    bool est_mouvement_legal(Square origine, Square destination){
        tuple<int,int> origine_coord = origine.convertion();
        tuple<int,int> destination_coord = destination.convertion();
        if(abs(get<0>(destination_coord)-get<0>(origine_coord))>7 || abs(destination.position[1]-origine.position[1])>7){
            cout<<"Mouvement illégal"<<endl;
            return false;
        }
        if(origine.position[0]==destination.position[0])
            if(destination.position[1]-origine.position[1]<=2){
                return true;
            }

            else{
                cout<<"Mouvement illégal"<<endl;
                return false;
            }
            
        else if(abs(get<0>(destination_coord)-get<0>(origine_coord))==1){

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

};