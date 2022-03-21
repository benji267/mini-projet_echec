#include <iostream>
#include "square.cpp"
#include <stdlib.h>
using namespace std;

// White=true and Black=false

class Piece{
    private:
    string nom_piece;
    bool couleur;
    Square square;

    Piece(string nom_piece, bool couleur, Square square) : nom_piece(nom_piece), couleur(couleur), square(square)
    {}

    string getNompiece(){
        return nom_piece;
    }

    bool getCouleur(){
        return couleur;
    }
    Square getSquare(){
        return square;
    }


    virtual void affiche(Piece &p){
        cout << "Le nom de la pièce est : " << getNompiece() <<  endl;
    }

};