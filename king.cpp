#include <iostream>
#include <piece.cpp>
#include <stdlib.h>
using namespace std;

class King : public Piece{
    bool est_mouvement_legale(Square origine, Square destination){
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
        if(position_origine==position_destination){
            if(abs(origine.position[1]-destination.position[1])==1){
                return true;
            }
            
            else{
                cout<<"Mouvement illégal"<<endl;
                return false;
            }
        }
        if(origine.position[1]==destination.position[1]){
            if(abs(position_destination-position_origine)==1){
                return true;
            }
            
            else{
                cout<<"Mouvement illégal"<<endl;
                return false;
            }
        }
        if(abs(origine.position[1]-destination.position[1])==1 && abs(position_origine-position_destination)==1){
            return true;
        }
        cout<<"Mouvement illégal"<<endl;
        return false;
    }

};