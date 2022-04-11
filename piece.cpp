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
        Color color;
        string piece_name;
        Square square;
        Def_Piece dpiece;

    public:
        Piece(){
            piece_name='rien';
            square=Square(0,0);
        }
        
        Piece( Color color, string &piece_name,Square square, Def_Piece p);
        ~Piece();

    

    Piece(string piece_name, Color color, Square square) : color(color), piece_name(piece_name), square(square)
    {}

     Piece::~Piece(){     
    }

    Piece(string piece_name, Color color, Square square){
        this->color=color;
        this->square=square;
    } 

   

    string getNompiece(){
        return piece_name;
    }

    Color getColor() const{
        return color;
    }
   


    void show(){
        cout << "Le nom de la pièce est : " << piece_name <<  endl;
    }

};