#include "game.h"
#include <iostream>
#include <regex>
using namespace std;







/**
 * @brief On vérifie si la commande rentrée est correcte
 * 
 * @param input 
 * @return true si oui et false sinon
 */
bool correct_input(string const & input){
    regex r("[a-h][1-8][a-h][1-8]");
    return regex_match(input,r);

}

/**
 * @brief On vérifie si la commande rentrée est correcte pour le grand roque
 * 
 * @param input 
 * @return true si oui et false sinon
 */

bool correct_input_grandroque(string const & input){
    regex r("(O|o|0)-(O|o|0)-(O|o|0)");
    return regex_match(input,r);

}

/**
 * @brief On vérifie si la commande rentrée est correcte pour le petit roque
 * 
 * @param input 
 * @return true si oui et false sinon
 */

bool correct_input_petitroque(string const & input){
    regex r("(O|o|0)-(O|o|0)");
    return regex_match(input,r);
}

/**
 * @brief On vérifie si la commande rentrée est correcte et renvoie le numéro du déplacement
 * 
 * @param input 
 * @return true si oui et false sinon
 */

int right_input(string const &input){
    if(input == "/quit"){
        return 1;
    }
    else if(correct_input(input)){
        return 2;
    }
    else if(correct_input_petitroque(input)){
        return 3;
    }
    else if(correct_input_grandroque(input)){
        return 4;
    }
    return 0;
}


int main(){
    bool end(false);
    Game game_;
    string input;
    int mvmt;
    game_.affiche();
    
    do{
        cout << "coup :" << endl;
        cin >> input;

        switch(right_input(input)){
            case 1:
                end = true;
                break;
            case 2:
                mvmt=2;
                break;

            case 3:
                mvmt=3;
                break;
            
            case 4:
                mvmt=4;
                break;
            
            default:
                mvmt=0;
                cout << "mauvaise commande" << endl;
        }

        if(mvmt==3){
            game_.roque(mvmt);
            game_.affiche();
        }
        else if(mvmt==4){
            game_.roque(mvmt);
            game_.affiche();
        }
        else if(mvmt==2){
            string position=input.substr(0, 2);
            string location=input.substr(2, 2);

            game_.moove(position,location,mvmt);
            game_.affiche();
        }
    }
    while(!end);
    game_.affiche_pgn();
}