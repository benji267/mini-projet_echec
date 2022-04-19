#pragma once
#include "piece.h"


/**
 * @file knight.h
 * @brief classe du chevalier
 * @date 2022-04-13
 * 
 * 
 */

class Knight : public Piece{
    public:

    /**
     * @brief constructeur d'un chevalier
     * @param color c'est la couleur de la pièce
     * @param name le nom de la pièce
     * @param location c'est la case d'où se trouve la pièce
     * 
     */
    Knight(Color color, const string &name, Square location);

    /**
     * @brief cette fonction permet de voir si le mouvement
     * demandé par l'utilisateur est légale et autorisé pour
     * un chevalier.
     * @param position la position de départ de la pièce
     * @param destination position souhaité à atteindre pour la pièce
     * @param mvmt
     * @return true si le mouvement est légal et false sinon
     */
    bool is_moovement_legal(Square position, Square destination, int mvmt);
};