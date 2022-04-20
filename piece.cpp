#include "piece.h"



    Piece::Piece() : color(Unknown), piece_name(""), square(1,1){}

    Piece(Color color, Square square) : color(color), piece_name(piece_name), square(square)
    {}

    Piece::~Piece(){}


    Color Piece::get_Color() const{
        return color;
    }
    
    string Piece::get_Name_Piece() const{
        return piece_name;
    }    

    Square Piece::get_location() const{
        return square;
    }

    Def_PiecePiece::get_def() const{
        return dpiece;
    }

    bool Piece::get_moovement() const{
        return has_moove;
    }

    void Piece::show() const{
        cout << "Le nom de la pièce est : " << piece_name <<  endl;
    }