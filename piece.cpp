#include <iostream>
#include "square.cpp"
#include <stdlib.h>
using namespace std;

// White=true and Black=false

class Piece{
    protected:
        bool couleur;
        string nom_piece;
        Square square;

    public:
        Piece(){
            couleur=true;
            nom_piece='rien';
            square=Square(0,0);
        }
        
        Piece(string nom_piece, bool couleur, Square square);
        ~Piece();

    Piece(string nom_piece, bool couleur, Square square) : nom_piece(nom_piece), couleur(couleur)
    {}

    Piece(string nom_piece, bool couleur, Square square){
        this->couleur=couleur;
        this->square=square;
    } 

    Piece::~Piece(){     
    }

    string getNompiece(){
        return nom_piece;
    }

    bool getCouleur(){
        return couleur;
    }
   


    virtual void affiche(Piece &p){
        cout << "Le nom de la pièce est : " << getNompiece() <<  endl;
    }

};