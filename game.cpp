#include <iostream>
#include "game.h"
using namespace std;


/**
 * @brief Cette classe a pour vocation de représenter le jeu en cours.
 * 
 * 
 * 
 * 
 * 
 **/

Game::Game(): chess(Chessboard()), couleur_(White), en_passant_(false), roque_en_cours(false) {}

/**
 * @brief destructeur
 * 
 **/ 
Game::~Game(){}


void Game::affiche(){
    chess.affiche();
    cout<<"C'est au tour des "<<affiche_couleur(couleur_)<< "de jouer" <<endl;
}

string Game::affiche_couleur(Color couleur){
    if(couleur == White){
        return "Blancs";
    }else if(couleur == Black){
        return "Noirs";
    }else{
        return "Vide";
    }
}

void Game::affiche_png(){
    cout<< endl << chess.final_position << endl;
}

void Game::set_roque(bool roque){
    roque_en_cours = roque;
}

int Game::Check_Pawn(Piece *piece, Square position, Square location, int mvmt){
    if(!(chess.is_empty_bloc(location))){
        if(abs(location.getLigne()- position.getLigne())==
            abs(location.getColonne() - position.getColonne())){
        mvmt=5;
        }
        else if(((abs(location.getLigne() - position.getLigne())) == 1)
                ||
                ((abs(location.getLigne() - position.getLigne())) == 2)
                &&
                ((abs(location.getColonne() - position.getColonne())) == 0)){
                    mvmt=6;
                }
    return mvmt;
    }
}

bool Game::moove(Square positon, Square location, int mvmt){
    if(chess.is_empty_bloc(position)){
        cerr<<"La case est vide"<<endl;
        return false;
    }
    Piece *piece = chess.get_piece(position);
    if(piece->get_Color() != couleur_){
        cerr<<"Cette pièce n'est pas de votre couleur"<<endl;
        return false;
    }
    if(piece->get_def() == pawn){
        mvmt = Check_Pawn(piece, position, location, mvmt);
    }
    if(!(piece->is_moovement_legal(position, location, mvmt))){
        cerr<<"Mouvement illégal"<<endl;
        return false;
    }

    /* Maintenant on code la possibilité qu'il y ait un obstacle
    */
   if((piece->get_def() == rook) && (roque_en_cours)
        ||
        (piece->get_def() == queen)
        ||
        (piece->get_def() == pawn))
        {
            if
        }

}

bool Game::hurdle(Piece * piece,Square position, Square location){
    /* Pour commencer je vais calculer des constantes qui me seront utiles dans ce code  */

    int gap_line=abs(location.getLigne() - position.getLigne());
    int gap_col= abs(location.getColonne() - position.getColonne());
    int i;
    
    /* on commence par coder la détection d'obstacles horizontales donc sur une même ligne */

    if(gap_line=0 && gap_col !=0){
        /* On commence par les déplacements sur la droite*/
        if(gap_col > 0){
            for(i=1; i<gap_col; i++){
                if(!(chess.is_empty_bloc(Square(position.getLigne(),position.getColonne()+i))) == false){
                    return true;
                }

        /* On enchaine avec les déplacements sur la gauche */
        else{
            for(i=gap_col; i>1; i--){
                if(!(chess.is_empty_bloc(Square(position.getLigne(),position.getColonne()+i))) == false){
                    return true;
                }
            }
        }
            }
        }
    }

    /* Désormais on regarde les déplacements sur une même colonne */

    if(gap_col==0 && gap_line!=0){
        /* On commence pâr les déplacements ascendants*/
        if(gap_line > 0){
            for(i=1; i<gap_line; i++){
                if(chess.is_empty_bloc(Square(position.getLigne()+i,position.getColonne()))==false){
                    return true;
                }
            }
        }
        /* Cette foic ci les déplacements descendants*/ 
        else{
            for(i=gap_line; i>1; i--){
                if(chess.is_empty_bloc(Square(position.getLigne()+i,position.getColonne()))==false){
                    return true;
                }
            }
        }
    }
    /* Il ne reste que les déplacements diagonaux dans les 4 diagonales */

    if(gap_col==gap_line){

        /* vers la diagonale supérieur gauche */
        if(gap_col < 0 && gap_line > 0){
            for(i=1; i<gap_line; i++){
                if(chess.is_empty_bloc(Square(position.getLigne()+i,position.getColonne()-i))==false){
                    return true;
                }
            }
        }

        /* vers la diagonale inférieur gauche */
        if(gap_col < 0 && gap_line < 0){
            for(i=1; i<gap_line; i++){
                if(chess.is_empty_bloc(Square(position.getLigne()-i,position.getColonne()-i))==false){
                    return true;
                }
            }
        }

        /* vers la diagonale supérieur droite*/
        if(gap_col > 0 && gap_line > 0){
            for(i=1; i<gap_line; i++){
                if(chess.is_empty_bloc(Square(position.getLigne()+i,position.getColonne()+i))==false){
                    return true;
                }
            }
        }

        /* vers la diagonale inférieure droite*/
        if(gap_col > 0 && gap_line < 0){
            for(i=1; i<gap_line; i++){
                if(chess.is_empty_bloc(Square(position.getLigne()-i,position.getColonne()+i))==false){
                    return true;
                }
            }
        }
    }

    return false;
}


