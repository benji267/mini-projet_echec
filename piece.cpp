#include <iostream>
#include <square.cpp>
#include <stdlib.h>
using namespace std;

// White=true and Black=false

class Piece{
    public:
    string nom_piece;
    bool couleur;
    Square square;

    Piece::Piece(string nom_piece, bool couleur, Square square){
        this->nom_piece=nom_piece;
        if(couleur){
            this->couleur=couleur;
        }
        else{
            this->couleur=couleur;
        }
    }
    


    virtual void affiche(Piece &p){
        cout << "Le nom de la pièce est : " << p.nom_piece <<  endl;
    }

};