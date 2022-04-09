#include <iostream>
using namespace std;

class Square
{

private:
    int ligne;
    int colonne;

public:
    Square()
    {
        ligne = -1;
        colonne = -1;
    };
    Square(int ligne, int colonne);
    ~Square();


    Square(const string &position){
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

    Square::Square(const int ligne, const int colonne) : ligne(ligne), colonne(colonne)
    {}

    Square::~Square()
    {
        delete &ligne;
        delete &colonne;
    }

    Square(const Square &square){
        ligne=square.ligne;
        colonne=square.colonne;
    }

    int getLigne() const
    {
        return ligne;
    }

    int getColonne() const
    {
        return colonne;
    }

    

    void to_string_afficher(Square square)
    {
        string chaine = "abcdefgh";
        cout << "ligne : " << chaine.at(getLigne() - 1) << "colonne : " << chaine.at(getColonne() - 1) << endl;
    }
};