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



Bishop::Bishop(Color color, const string &name, Square location) : Piece(color, name, location, bishop) {}
       



bool Bishop::is_moovement_legal(Square position, Square destination, int mvmt) const{
    if(abs(destination.getLigne()-position.getLigne())>7 || abs(destination.getColonne()-position.getColonne())>7){
        cerr<<"Mouvement illégal"<<endl;
        return false;
    }
    else if(abs(destination.getLigne()-position.getLigne())-abs(destination.getColonne()-position.getColonne())==0){
        return true;
    }
    return false;
}

King::King(Color color, const string &name, Square location) : Piece(color, name, location, king){}


        

    
bool King::is_moovement_legal(Square position, Square destination, int mvmt) const{
    if(abs(destination.getLigne()-position.getLigne())>7 || abs(destination.getColonne()-position.getColonne())>7){
        cout<<"Mouvement illégal"<<endl;
        return false;
    }
    if(mvmt==2){
        if(destination.getLigne()==position.getLigne()){
            if(abs(position.getColonne()-destination.getColonne())==1){
                return true;
            }
            
            else{
                cout<<"Mouvement illégal"<<endl;
                return false;
            }
        }
        if(position.getColonne()==destination.getColonne()){
            if(abs(destination.getLigne()-position.getLigne())==1){
                return true;
            }
        
            else{
                cout<<"Mouvement illégal"<<endl;
                return false;
            }
        }
        if(abs(position.getColonne()-destination.getColonne())==1 && abs(position.getLigne()-destination.getLigne())==1){
            return true;
        }
    }
    else if(mvmt==3){
        if(has_moove){
            cerr<<" petit roque impossible"<<endl;
            return false;
        }
        else if(abs(destination.getLigne()-position.getLigne())==0
                &&
                abs(destination.getColonne()-position.getColonne())==2){
                    return true;
                }
    }
    else if(mvmt==4){
        if(has_moove){
            cerr<<" grand roque impossible"<<endl;
            return false;
        }
        else if(abs(destination.getLigne()-position.getLigne())==0
                &&
                abs(destination.getColonne()-position.getColonne())==3){
                    
                    return true;
        }
    }
    cout<<"Mouvement illégal"<<endl;
    return false;
}



Knight::Knight(Color color, const string &name, Square location) : Piece(color, name, location, knight) {}


bool Knight::is_moovement_legal(Square position, Square destination, int mvmt) const{
    if(abs(destination.getLigne()-position.getLigne())>7 || abs(destination.getColonne()-position.getColonne())>7){
        cout<<"Mouvement illégal"<<endl;
        return false;
    }
    if(abs(position.getColonne()-destination.getColonne())%2==0 || abs(destination.getLigne()-position.getLigne())%2==0){
        if(abs(position.getColonne()-destination.getColonne())+abs(destination.getLigne()-position.getLigne())==3){
            return true;
        }
    }
    cout<<"Mouvement illégal"<<endl;
    return false;  
}



Pawn::Pawn(Color color, const string &name, Square location) : Piece(color, name, location, pawn){}


bool Pawn::is_moovement_legal(Square position, Square destination, int mvmt) const{
    if(abs(destination.getLigne()-position.getLigne())>7 || abs(destination.getColonne()-position.getColonne())>7){
        cout<<"Mouvement illégal"<<endl;
        return false;
    }
    Color color_piece=get_Color();
    
    if(color_piece==White){
        if((destination.getLigne()==1+position.getLigne())
            &&
            (destination.getColonne()==position.getColonne())
            &&
            (mvmt!=6)){
                return true;
            }
        else if(destination.getLigne()==2+position.getLigne()
                &&
                (!has_moove)
                &&
                mvmt!=6){
                    return true;
                }
        else if(mvmt==5){
            return true;
        }
        else{
            cout<<"Mouvement illégal"<<endl;
            return false;
        }
    }
    else if(color_piece==Black){
        if((destination.getLigne()==6+position.getLigne())
            &&
            (destination.getColonne()==position.getColonne())
            &&
            (mvmt!=6)){
                return true;
            }
        else if(destination.getLigne()==5+position.getLigne()
                &&
                (!has_moove)
                &&
                mvmt!=6){
                    return true;
                }
        else if(mvmt==5){
            return true;
        }
        else{
            cout<<"Mouvement illégal"<<endl;
            return false;
        }
    }
    cout<<"Mouvement illégal"<<endl;
    return false;
}

Queen::Queen(Color color, const string &name, Square location) : Piece(color, name, location, queen){}

bool Queen::is_moovement_legal(Square origine, Square destination, int mvmt) const{
    if(abs(origine.getLigne()-destination.getLigne())>7 || abs(destination.getColonne()-origine.getColonne())>7){
        cout<<"Mouvement illégal"<<endl;
        return false;
    }
    if(origine.getLigne()==destination.getLigne()){
            
        if(abs(origine.getColonne()-destination.getColonne())>7){
            cout<<"Mouvement illégal"<<endl;
            return false;
        }

        else{
            return true;
        }
    }

    else if(origine.getColonne()==destination.getColonne()){

        if(abs(destination.getLigne()-origine.getLigne())>7){
            cout<<"Mouvement illégal"<<endl;
            return false;
        }

        else{
            return true;
        }
    }
    else if(abs(destination.getLigne()-origine.getLigne())-abs(destination.getColonne()-origine.getColonne())==0){
        return true;
    }

    cout<<"Mouvement illégal"<<endl;
    return false;
}


Rook::Rook(Color color, const string &name, Square location) : Piece(color, name, location, rook){}
       
bool Rook::is_moovement_legal(Square position, Square destination, int mvmt) const{
    if(position.getLigne()==destination.getLigne()){
        
        if(abs(position.getColonne()-destination.getColonne())>7){
            cout<<"Mouvement illégal"<<endl;
            return false;
        }

        else{
            return true;
        }
    }
    else if(position.getColonne()==destination.getColonne()){
        if(abs(destination.getLigne()-position.getLigne())>7){
            cout<<"Mouvement illégal"<<endl;
            return false;
        }

        else{
            return true;
        }
    }
    
    else if(mvmt==3){
        if(has_moove){
            cerr<<" petit roque impossible"<<endl;
            return false;
        }
        else if(abs(destination.getLigne()-position.getLigne())==0
                &&
                abs(destination.getColonne()-position.getColonne())==2){
                    return true;
                }
    }

    else if(mvmt==4){
        if(has_moove){
            cerr<<" grand roque impossible"<<endl;
            return false;
        }
        else if(abs(destination.getLigne()-position.getLigne())==0
                &&
                abs(destination.getColonne()-position.getColonne())==3){
                    return true;
                }
    }
    return false;
}




