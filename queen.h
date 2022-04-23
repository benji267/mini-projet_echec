#pragma once
#include "piece.h"
/**
 * @file queen.h
 * @brief cette classe gère les reines.
 * @date 2022-04-13
 * 
 */

class Queen: public Piece{

    public:

    /**
     * @brief constrcuteur de la reine.
     * @param color c'est la couleur de la pièce
     * @param name le nom de la pièce
     * @param location c'est la case d'où se trouve la pièce
     */
        Queen(Color color, const string &name, Square location);

    /**
     * @brief cette fonction permet de voir si le mouvement
     * demandé par l'utilisateur est légale et autorisé pour
     * une reine.
     * @param position la position de départ de la pièce
     * @param destination position souhaité à atteindre pour la pièce
     * @param mvmt
     * @return true si le mouvement est autorisé et false sinon.
     * 
     */
    bool is_moovement_legal(Square position, Square destination);
};