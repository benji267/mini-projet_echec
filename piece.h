#pragma once

#include "square.h"
#include <iostream>
#include <string>

/**
 * @brief Color est une structe de type enum qui va affecter une valeur
 * à chaque couleurs. Unknown=0; White=1; Black=2;
 */
enum Color{
    Unknown=0,
    White,
    Black
};

/**
 * @brief Def_piece est une structure de type enum qui va affecter une valeur
 * à chaque pièce en question. Unknown=0; rook=1; knight=2 ...
 */
enum Def_Piece{
    Unknown=0,
    rook,
    knight,
    bishop,
    queen,
    king,
    pawn
};

/**
 * @brief Cette classe va gérer les différentes pièces présentes
 * sur l'échiquier et leurs couleurs à chacunes.
 */

class Piece{
    protected:
    /**
     * @brief permet d'avoir la couleur d'une pièce
     */
    Color color;

    /**
     * @brief permet d'avoir le nom de la pièce sous forme de string.
     */
    string piece_name;

    /**
     * @brief permet d'avoir la case où est la pièce
     */
    Square square;

    /**
     * @brief permet d'avoir accès à un nom générique de la pièce avec  
     * la structure enum Def_Piece. 
     */
    Def_Piece dpiece;

    public:
        /**
         * @brief constructeur de base d'une pièce
         * 
         */
        Piece();

        /**
         * @brief consttructeur avec valeur d'une pièce
         * @param color couleur de la pièce
         * @param name nom de la pièce
         * @param square la case de la pièce
         * @param dpiece 
         */
        Piece(Color color, const string &name, Square square, Def_Piece def)

        


};





