#include <iostream>
#include "piece.cpp"
#include <stdlib.h>
using namespace std;

class Knight : public Piece{
    
    bool est_mouvement_legal(Square origine, Square destination){
        tuple<int,int> origine_coord = origine.convertion();
        tuple<int,int> destination_coord = destination.convertion();  
    }
};