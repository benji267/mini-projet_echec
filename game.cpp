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
    if(!(chess.is_empty(location))){
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
    if(chess.is_empty(position)){
        cerr<<"La case est vide"<<endl;
        return false;
    }
    Piece *piece = chess.get_piece(position);
    if(piece->get_Color() != couleur_){
        cerr<<"Cette pièce n'est pas de votre couleur"<<endl;
        return false;
    }
    if(piece->get_def() == Pawn){
        mvmt = Check_Pawn(piece, position, location, mvmt);
    }
    if(!(piece->is_moovement_legal(position, location, mvmt))){
        cerr<<"Mouvement illégal"<<endl;
        return false;
    }
}
