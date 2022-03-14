#include <iostream>
#include "piece.cpp"
#include <stdlib.h>
using namespace std;

class Queen : public Piece{
    bool est_mouvement_legal(Square origine, Square destination){
        tuple<int,int> origine_coord = origine.convertion();
        tuple<int,int> destination_coord = destination.convertion();
        if(abs(get<0>(destination_coord)-get<0>(origine_coord))>7 || abs(destination.position[1]-origine.position[1])>7){
            cout<<"Mouvement illégal"<<endl;
            return false;
        }
        if(get<0>(origine_coord)==get<0>(destination_coord)){
            
            if(abs(origine.position[1]-destination.position[1])>7){
                cout<<"Mouvement illégal"<<endl;
                return false;
            }

            else{
                return true;
            }
        }

        else if(origine.position[1]==destination.position[1]){

            if(abs(get<0>(destination_coord)-get<0>(origine_coord))>7){
                cout<<"Mouvement illégal"<<endl;
                return false;
            }

            else{
                return true;
            }
        }
        else if(abs(get<0>(destination_coord)-get<0>(origine_coord))-abs(destination.position[1]-origine.position[1])==0){
            return true;
        }

    cout<<"Mouvement illégal"<<endl;
    return false;
    
    }
};