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
    }
};