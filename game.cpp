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

bool Game::deplace(Square positon, Square location, int mvmt){
}
