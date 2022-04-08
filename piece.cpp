#include <iostream>
#include "square.cpp"
#include <stdlib.h>
#include <color.h>
using namespace std;

enum Def_Piece{
    Unknown=0,
    Rook,
    Knight,
    Bishop,
    Queen,
    King,
    Pawn
};

class Piece{
    protected:
        Color couleur;
        string nom_piece;
        Square square;
        Def_Piece dpiece;

    public:
        Piece(){
            nom_piece='rien';
            square=Square(0,0);
        }
        
        Piece( Color couleur, string &nom_piece,Square square, Def_Piece p=Unknown);
        ~Piece();

    

    Piece(string nom_piece, Color couleur, Square square) : couleur(couleur), nom_piece(nom_piece), square(square), d_piece(p)
    {}

     Piece::~Piece(){     
    }

    Piece(string nom_piece, Color couleur, Square square){
        this->couleur=couleur;
        this->square=square;
    } 

   

    string getNompiece(){
        return nom_piece;
    }

    Color getColor(){
        return couleur;
    }
   


    void affiche(Piece &p){
        cout << "Le nom de la pièce est : " << getNompiece() <<  endl;
    }

};