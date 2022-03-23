#include <iostream>
#include <tuple>
using namespace std;



class Square{
    
    private:
    int ligne;
    int colonne;

    public:
    

    Square(int ligne, int colonne){
        this->ligne=ligne;
        this->colonne=colonne; 
    }

    int getLigne() const{
        return ligne;
    }

    int getColonne() const{
        return colonne;
    }
    

    void to_string_afficher(Square square){
        string chaine="abcdefgh";
        cout << "ligne : "<<chaine.at(getLigne()-1) << "colonne : "<<chaine.at(getColonne() - 1) << endl;
    }
};