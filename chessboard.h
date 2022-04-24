#pragma once
#include "piece.h"



/**
 * @brief Cette classe a pour vocation de manipuler l'échiquier.
 *        Elle a pour rôle de l'initialiser et de maintenir l'état
 *        après le déplacement dees pièces dmandés.
 **/
class Chessboard {
    protected:
        /**
         * @brief représentation de l'échiquier
         * sous forme de tableau [8][8]
         * du type echiquier_[ligne][colonne]
         */
        Piece *** chessboard; 

    public:
        /**
         * @brief constructeur par défaut qui initialise l'échiquier
         * Place les pièces en position initiale
         **/
        Chessboard();

        /**
         * @brief destructeur
         **/
        ~Chessboard();


        /**
         * @brief vérifie que l'on reste dans les 
         * dimensions de l'échiquier
         * @param square la case demandée
         * @return l'addresse de la pièce se trouvant sur 
         * cette case, nullptr s'il n'y a pas de pièces
         **/
        Piece * get_piece(Square location) const;

        /**
         * @brief place un pointeur nul sur la case origine
         **/
        void remove_piece(Square location);

        /**
         * @brief pose une pièce à la case spécifiée
         * La pose est possile si la case est vide ou si elle
         * contient une pièce de couleur opposée à `pièce`.
         * @param piece la pièce à poser
         * @param destination la case où l'on veut poser la pièce
         * @param capture renvoie par addresse true si l'on capture une pièce
         * 
         * @return true si la pièce a été posée sur la case, false sinon.
         **/
        bool put_piece(Piece * piece, Square const& destination, bool & capture);

        /**
         * @brief indique le statut de la case (libre/occupée).
         * 
         * @param square la case à examiner
         * @return true si la case est vide, false sinon.
         **/
        bool is_empty_bloc(Square square) const;

        /**
         * @brief la position finale du jeu sous une forme 
         *        canonique, on récupère le contenu de chaque
         *        case en parcoutant l'échiquier dans l'ordre et
         *        on ajoute un espace vide si nullptr.
         * @return une chaine de caractères modélisant l'échiquier
         **/
        string final_position() const;

        /**
         * @brief est utilisée par final_position()
         * pour renvoyer le symbole utilisé dans la notation pgn.
         * 
         * @param name nom de la pièce
         * la valeur de la pièce
         * @param view_pawn si la pièce est un pion
         * @param view_color si la pièce est blanche ou noire
         * @return le nom au format pgn: rien si la case est vide,
         *         sinon `w` ou `b` pour la couleur, suivi d'un caractère
         *         pour la pièce (R,N,B,Q,K,P). 
         **/
        string pgn_piece_name(string const name, bool view_pawn, bool view_color) const;

        /**
         *  @brief affiche l'échiquier dans le terminal
         **/
        void show() const;
};
