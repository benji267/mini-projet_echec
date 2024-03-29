#pragma once

#include "chessboard.h"

#include <iostream>
using namespace std;

/**
 * @brief cette classe a pour vocation d'interagir avec
 * l'utilisateur.
 **/
class Game {
    protected:
        /**
         * @brief attribut Chessboard
         */
        Chessboard chess;
        /**
         * @brief permet de savoir quelle est 
         * la couleur attendue et gérer 
         * l'alternance des coups
         */
        Color color;
        /**
         * @brief non utilisé, 
         * prévu pour la prise en passant
         */
        bool en_passant_;
        /**
         * @brief
         * 
         */
        bool roque_en_cours;

    public:
        /**
         * @brief constructeur
         * initialise la dernière couleur à Noir pour que
         * les Blancs commencent.
         **/
        Game();

        /**
         * @brief destructeur
         **/
        ~Game();

        /**
         * @brief affiche l'échiquier grâce à la méthode
         * affiche() de la classe Echiquier
         * affiche la couleur devant jouer le prochain coup
         **/
        void affiche();

        /**
         * @return le nom de la couleur 
         **/
        string affiche_couleur(Color couleur);

        /**
         * @brief s'occupe de l'affichage final au format pgn
         **/
        void affiche_pgn() const;

        /**
         * @brief
         * change la valeur de roque_en_cours
         */
        void set_roque(bool value);

        /**
         * @brief gestion du déplacement suite à la saisie du coup
         *
         * @param position la case de départ de la pièce
         * @param location la case d'arrivée de la pièce
         * @param mvmt permet de spécifier s'il s'agit d'un roque
         * @return true si le déplacement a eu lieu, false sinon
         **/
        bool moove(Square position, Square location, int mvmt);


        /**
         * @brief s'occupe des vérifications spécifiques aux pions 
         * comme la prise, la prise en passant etc.
         * @param position 
         * @param location 
         * @param mvmt spécifie le type du mouvement, 
         *      permet de dissocier les différents mouvements
         * @return true 
         * @return false 
         */
        int Check_Pawn(Square position, Square location, int mvmt);

        /**
         * @brief vérifie que la pièce ne passe pas au-dessus
         * d'une autre lors de son déplacement.
         * On distingue trois déplacements particuliers:
         *      - selon la ligne
         *      - selon la colonne
         *      - selon la diagonale
         * 
         * (à désactiver lors du roque)
         * @param piece 
         * @param position 
         * @param location 
         * @return true s'il y a un obstacle,false sinon
         */
        bool hurdle(Piece * piece,Square position, Square location);

        /**
         * @brief si un roque est demandé, il faut spécifier 
         * les cases de départ et d'arrivée du roi et de la tour,
         * qui dépendent de la couleur et du type de roque.
         * Valable si ces pièces n'ont jamais bougé.
         * Fait appel à deplace()
         * @param mvmt le type de mouvement
         **/
        bool roque(int mvmt);

};