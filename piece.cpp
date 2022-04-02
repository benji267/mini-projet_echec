#include <iostream>
#include "square.cpp"
#include <stdlib.h>
#include <color.h>
using namespace std;

// White=true and Black=false

class Piece{
    protected:
        Color couleur;
        string nom_piece;
        Square square;

    public:
        Piece(){
            nom_piece='rien';
            square=Square(0,0);
        }
        
        Piece(string nom_piece, Color couleur, Square square);
        ~Piece();

    Piece(string nom_piece, Color couleur, Square square) : nom_piece(nom_piece), couleur(couleur), square(square)
    {}

    Piece(string nom_piece, Color couleur, Square square){
        this->couleur=couleur;
        this->square=square;
    } 

    Piece::~Piece(){     
    }

    string getNompiece(){
        return nom_piece;
    }

    Color getCouleur(){
        return couleur;
    }
   


    virtual void affiche(Piece &p){
        cout << "Le nom de la pièce est : " << getNompiece() <<  endl;
    }

};