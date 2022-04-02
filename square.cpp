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

    Square(int ligne, int colonne) : ligne(ligne), colonne(colonne)
    {
    }

    Square::Square(int ligne, int colonne)
    {
        this->ligne = ligne;
        this->colonne = colonne;
    }
    

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