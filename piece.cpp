#include "piece.h"



    Piece::Piece() : color(Unknown), piece_name(""), square(1,1){}
    Piece(Color color, Square square) : color(color), piece_name(piece_name), square(square)
    {}

     Piece::~Piece(){     
    }

    Piece(string piece_name, Color color, Square square){
        this->color=color;
        this->square=square;
    } 

   


    Piece::Color get_Color() const{
        return color;
    }
    
    Piece::string get_Name_Piece() const{
        return piece_name;
    }    

    Piece::Square get_location() const{
        return square;
    }

    Piece::Def_Piece get_def() const{
        return dpiece;
    }

    Piece::bool get_moovement() const{
        return has_moove;
    }

    Piece::void show() const{
        cout << "Le nom de la pièce est : " << piece_name <<  endl;
    }

};