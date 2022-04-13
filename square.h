#pragma once

#include <iostream>
#include <string>
using namespace std;


/**
 * @brief Cette classe a pour vocation de représenter l'état et la position
 *        d'une pièce.
 **/

class Square{

    protected:
        /**
         * @brief permet de savoir la ligne où se trouve la pièce
         */
        int ligne;

        /**
         * @brief permet de savoir la colonne où se trouve la pièce
         */
        int colonne;

    public:
    /**
     * @brief constructeur par défaut d'un Square avec des coordonnées
     * du type int ligne et int colonne
     * @param lig la ligne où se trouve la pièce
     * @param col la colonne où se trouve la pièce 
    **/
    Square(int lig, int col);

    /**
     * @brief constructeur par défaut d'un Square avec des coordonnées
     * du type string. Par exemple "a1" qui correspond a la première colonne
     * pour le "a" et la première ligne pour le 1.
     * @param position la position où se trouve la pièce 
     **/
    Square(const string &position);

    /**
     * @brief fonction qui renvoie la ligne où se trouve la pièce
     * @return la ligne où se trouve la pièce
    **/
    int getLigne() const;

    /**
     * @brief fonction qui renvoie la colonne où se trouve la pièce
     * @return la colonne où se trouve la pièce
    **/
    int getColonne() const;

    /**
     * @brief fonction qui affiche la position de la pièce
     * @param square la case en question 
    **/
    void to_string_afficher(Square square) const;
};