#include <iostream>
#include <stdlib.h>

#include "piece.cpp"

using namespace std;

class King : public Piece{
    bool est_mouvement_legale(Square origine, Square destination){
        tuple<int,int> origine_coord = origine.convertion();
        tuple<int,int> destination_coord = destination.convertion();
        if(abs(get<0>(destination_coord)-get<0>(origine_coord))>7 || abs(destination.position[1]-origine.position[1])>7){
            cout<<"Mouvement illégal"<<endl;
            return false;
        }
        if(get<0>(destination_coord)==get<0>(origine_coord)){
            if(abs(origine.position[1]-destination.position[1])==1){
                return true;
            }
            
            else{
                cout<<"Mouvement illégal"<<endl;
                return false;
            }
        }
        if(origine.position[1]==destination.position[1]){
            if(abs(get<0>(destination_coord)-get<0>(origine_coord))==1){
                return true;
            }
            
            else{
                cout<<"Mouvement illégal"<<endl;
                return false;
            }
        }
        if(abs(origine.position[1]-destination.position[1])==1 && abs(get<0>(origine_coord)-get<0>(destination_coord))==1){
            return true;
        }
        cout<<"Mouvement illégal"<<endl;
        return false;
    }

};