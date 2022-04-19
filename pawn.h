#pragma once
#include "piece.h"


/**
 * @file pawn.h
 * @brief classe du pion
 * @date 2022-04-13
 * 
 * 
 */

class Pawn : public Piece{
    public:

    /**
     * @brief constructeur d'un pion
     * @param color c'est la couleur de la pièce
     * @param name le nom de la pièce
     * @param location c'est la case d'où se trouve la pièce
     * 
     */
    Pawn(Color color, const string &name, Square location);

    /**
     * @brief cette fonction permet de voir si le mouvement
     * demandé par l'utilisateur est légale et autorisé pour
     * un pion.
     * @param position la position de départ de la pièce
     * @param destination position souhaité à atteindre pour la pièce
     * @param mvmt
     * @return true si le mouvement est légal et false sinon
     */
    bool is_moovement_legal(Square position, Square destination, int mvmt);
};