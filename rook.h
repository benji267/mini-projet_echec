#pragma once
#include "piece.h"


/**
 * @file rook.h
 * @brief classe de la tour
 * @date 2022-04-13
 * 
 * 
 */

class Rook : public Piece{
    public:

    /**
     * @brief constructeur d'une Tour
     * 
     */
    Rook(Color color, const string &name, Square location);

    /**
     * @brief cette fonction permet de voir si le mouvement
     * demandé par l'utilisateur est légale et autorisé pour
     * une tour.
     * @return true si le mouvement est légal et false sinon
     */
    bool is_moovement_lega(Square origine, Square destination);
};