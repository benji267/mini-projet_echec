#pragma once
#include "square.h"
#include <iostream>
#include <string>
#include <list>
#include <enum.h>

/**
 * @brief Color est une structe de type enum qui va affecter une valeur
 * à chaque couleurs. Unknown=0; White=1; Black=2;
 * @return Unknown, Blanc ou Noir
 */
enum Color{Unknown=0, White, Black};

/**
 * @brief Def_piece est une structure de type enum qui va affecter une valeur
 * à chaque pièce en question. Unknown=0; rook=1; knight=2 ...
 */
enum Def_Piece{
    Unk=0,
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

    /**
     * @brief permet de savoir si une pièce a déjà effectuée
     * un déplacement afin de simplifier le codage du grand et 
     * petit roque
     * 
     */
    bool has_moove;

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
        Piece(Color color, const string &name, Square square, Def_Piece def);

        /**
         * @brief destructeur.
         * 
         */
        ~Piece();

        /**
         * @brief renvoie la couleur de la pièce
         * @return la couleur
         * 
         */
        Color get_Color() const;

        /**
         * @brief renvoie le nom de la pièce
         * @return le nom de la pièce
         */
        string get_Name_Piece() const;

        /**
         * @brief renvoie la localisation sur l'échiquier de la pièce
         * @return renvoie la case
         */
        Square get_location() const;

        /**
         * @brief renvoie le type de pièce
         * @return renvoie un type de pièce de la struct Def_piece
         * 
         */
        Def_Piece get_def() const;

        /**
         * @brief renvoie si la pièce a déjà bougé
         * @return renvoie True si elle a déjà bougé et False sinon
         */
        bool get_moovement() const;

        
        /**
         * @brief affiche le nom de la pièce
         * 
         */
        void show() const;


};





