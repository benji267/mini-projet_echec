#include <iostream>
#include "square.cpp"
#include <stdlib.h>
using namespace std;

enum Def_Piece{
    Unknown=0,
    rook,
    knight,
    bishop,
    queen,
    king,
    pawn
};

enum Color{
    Unknown=0,
    White,
    Black
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
        
        Piece( Color couleur, string &nom_piece,Square square, Def_Piece p);
        ~Piece();

    

    Piece(string nom_piece, Color couleur, Square square) : couleur(couleur), nom_piece(nom_piece), square(square)
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

    Color getColor() const{
        return couleur;
    }
   


    void show(){
        cout << "Le nom de la pièce est : " << nom_piece <<  endl;
    }

};