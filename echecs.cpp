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

bool correct_input_grandroque(string const & input){
    regex r("(O|o|0)-(O|o|0)-(O|o|0)");
    return regex_match(input,r);

}

bool correct_input_petitroque(string const & input){
    regex r("(O|o|0)-(O|o|0)");
    return regex_match(input,r);
}

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