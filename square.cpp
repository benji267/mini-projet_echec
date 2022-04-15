#include "square.h"




    Square::Square(const int lig, const int col)
    : ligne(lig),colonne(col)
    {}


    Square::Square(const string &position){
        char c=position[0];
        char l=position[1];
        switch(c){
            case 'a':
                colonne=0;
                break;
            case 'b':
                colonne=1;
                break;
            case 'c':
                colonne=2;
                break;
            case 'd':
                colonne=3;
                break;
            case 'e':
                colonne=4;
                break;
            case 'f':
                colonne=5;
                break;
            case 'g':
                colonne=6;
                break;
            case 'h':
                colonne=7;
                break;
            default:
                cout << "erreur de saisie colonne"<<endl;
                break;
        switch(l){
            case '1':
                ligne=0;
                break;
            case '2':
                ligne=1;
                break;
            case '3':
                ligne=2;
                break;
            case '4':
                ligne=3;
                break;
            case '5':
                ligne=4;
                break;
            case '6':
                ligne=5;
                break;
            case '7':
                ligne=6;
                break;
            case '8':
                ligne=7;
                break;
            default:
                cout << "erreur de saisi ligne"<<endl;
                break;
            
        } 


        }
    }

    int Square::getLigne() const
    {
        return ligne;
    }

    int Square::getColonne() const
    {
        return colonne;
    }

    

    void Square::to_string_afficher() const
    {
        string chaine = "abcdefgh";
        cout << "ligne : " << chaine.at(getLigne() - 1) << "colonne : " << chaine.at(getColonne() - 1) << endl;
    }

    char Square::square_to_string() const{
        int lig=ligne+1;
        char col;
        switch (colonne){
            case 0:
                col='a'; 
                break;
            case 1:
                col='b';
                break;
            case 2:
                col='c';
                break;
            case 3:
                col='d';
                break;
            case 4:
                col='e';
                break;
            case 5:
                col='f';
                break;
            case 6:
                col='g';
                break;
            case 7:
                col='h';
                break;
            default:
                col='z';
                cout << "erreur de saisie colonne"<<endl;
                return col;
        }
        char coord;
        sprintf(&coord, lig);
        return coord;
    }