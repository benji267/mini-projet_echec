#include <iostream>
#include <tuple>
using namespace std;



class Square{
    public:
    string position;

    tuple<int,int> convertion(){
        tuple<int,int> coordonnees;
        string chaine="abcdefgh";
        for(int i=0;i<7;i++){
            if(this->position[0]=chaine.at(i)){
                get<0>(coordonnees)=i;
                get<1>(coordonnees)=this->position[1]-1;
                return coordonnees;
            }
        }
    }


    void to_string_afficher(int ligne, int colonne){
        string chaine="abcdefgh";
        cout << "ligne : "<<chaine.at(ligne) << "colonne : "<<colonne-1 << endl;
    }
};
