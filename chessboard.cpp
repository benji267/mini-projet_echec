#include "chessboard.h"

#define NBCOL 8






   Chessboard::Chessboard() {

    chessboard= new Piece**[8];

    for(int i=0; i<8; i++){
        chessboard[i]=new Piece*[8];
        for(int j=0; j<8; j++){
            chessboard[i][j]=nullptr;
        }
    }


    chessboard[0][0] = new Rook(White, " \u2656 ", Square(0, 0));
    chessboard[0][1] = new Knight(White, " \u2658 ", Square(0, 1));
    chessboard[0][2] = new Bishop(White, " \u2657 ", Square(0, 2));
    chessboard[0][3] = new Queen(White, " \u2655 ", Square(0, 3));
    chessboard[0][4] = new King(White, " \u2654 ", Square(0, 4));
    chessboard[0][5] = new Bishop(White, " \u2657 ", Square(0, 5));
    chessboard[0][6] = new Knight(White, " \u2658 ", Square(0, 6));
    chessboard[0][7] = new Rook(White, " \u2656 ", Square(0, 7));
    chessboard[7][0] = new Rook(Black, " \u265C ", Square(7, 0));
    chessboard[7][1] = new Knight(Black, " \u265E ", Square(7, 1));
    chessboard[7][2] = new Bishop(Black, " \u265D ", Square(7, 2));
    chessboard[7][3] = new Queen(Black, " \u265B ", Square(7, 3));
    chessboard[7][4] = new King(Black, " \u265A ", Square(7, 4));
    chessboard[7][5] = new Bishop(Black, " \u265D ", Square(7, 5));
    chessboard[7][6] = new Knight(Black, " \u265E ", Square(7, 6));
    chessboard[7][7] = new Rook(Black, " \u265C ", Square(7, 7));

    for(int i=0; i<8; i++){
        chessboard[1][i] = new Pawn(White, " \u2659 ", Square(1, i));
        chessboard[6][i] = new Pawn(Black, " \u265F ", Square(6, i));
    }
}


Chessboard::~Chessboard() 
    {}


void Chessboard::remove_piece(Square location){
    chessboard[location.getLigne()][location.getColonne()]=nullptr;
}


Piece* Chessboard::get_piece(Square location) const{
    if(location.getLigne()<0 || location.getLigne()>7 || location.getColonne()<0 || location.getColonne()>7){
        return chessboard[location.getLigne()][location.getColonne()];;
    }
    return nullptr;
}


bool Chessboard::put_piece(Piece* piece, Square const &location, bool &is_capture){
    if(location.getLigne()<0 || location.getLigne()>7 || location.getColonne()<0 || location.getColonne()>7){
        return false;
    }
    if(chessboard[location.getLigne()][location.getColonne()]==nullptr){
        chessboard[location.getLigne()][location.getColonne()]=piece;
        return true;
    }
    else{
        if(chessboard[location.getLigne()][location.getColonne()]->get_Color()!=piece->get_Color()){
            is_capture=true;
            remove_piece(location);
            chessboard[location.getLigne()][location.getColonne()]=piece;
            return true;
        }
        else{
            return false;
        }
    }
}

bool Chessboard::is_empty_bloc(Square location) const{
    {
    if (get_piece(location)==nullptr)
        return true;
    return false;
    }
}



string Chessboard::pgn_piece_name(string const name, bool view_pawn, bool view_color) const {

  string psymb;
  if      (name=="\u2656") psymb="R";  // Rook W
  else if (name=="\u2658") psymb="N";  // Knight W
  else if (name=="\u2657") psymb="B";  // Bishop W
  else if (name=="\u2655") psymb="Q";  // Queen W
  else if (name=="\u2654") psymb="K";  // King W
  else if (name.rfind("\u2659",0)==0 && view_pawn) psymb= "P"; // Pawn W
  if (psymb.size()>0) { // one of the white piece has been found
          if (view_color)
                return "w"+psymb;
          else
                return psymb;
  } 
  if      (name=="\u265C") psymb= "R";  // Rook B
  else if (name=="\u265E") psymb= "N";  // Knight B
  else if (name=="\u265D") psymb= "B"; // Bishop B
  else if (name=="\u265B")  psymb= "Q"; // Queen B
  else if (name=="\u265A")  psymb= "K"; // King B
  else if (name.rfind("\u265F",0)==0 && view_pawn) psymb= "P"; // Pawn B
  if (psymb.size()>0) { // one of the black piece has been found
          if (view_color)
                return "b"+psymb;
          else
                return psymb;
  } 
  else return "";
}




string Chessboard::final_position() const {
    string output;
    for (size_t row(1); row<=8; row++){
        for (char col('a');col<='h';col++) {
            Square square(col+to_string(row)); 
            if (!(is_empty_bloc(square)))
                 output += pgn_piece_name(get_piece(square)->get_Name_Piece(),true,true);
            output += ",";
        }
    }
    return output;
}







void Chessboard::show() const{
    string space5 = string(5,' ');
    cout << endl;
    cout << "     a     b     c     d     e     f     g     h    "<< endl;
    cout << "  +-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
    for (int i(8-1);i>=0;i--) {
        cout << i+1 << " "; /* numérotation ligne dans affichage */
        for (int j(0);j<8;j++) {
            cout << "|" ;
            if (chessboard[i][j]) {                           	
				cout << "\u0020\u0020";  /* U+0020 est un esapce utf-8 taille police */
        	  	chessboard[i][j]-> show();
              	cout << "\u0020" << " ";
            }
            else 
                cout << space5;  /* 2 ascii spaces */
        }
        cout << "|\n  +-----+-----+-----+-----+-----+-----+-----+-----+";
        cout << endl;
    }
}


