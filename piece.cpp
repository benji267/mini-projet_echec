#include "piece.h"



    Piece::Piece() : color(Unknown), piece_name(""), square(1,1){}

    Piece::Piece(Color color, const string &name, Square square, Def_Piece def) : color(color), piece_name(name), square(square), dpiece(def)
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

    Def_Piece Piece::get_def() const{
        return dpiece;
    }

    bool Piece::get_moovement() const{
        return has_moove;
    }

    void Piece::show() const{
        cout << "Le nom de la pièce est : " << piece_name <<  endl;
    }