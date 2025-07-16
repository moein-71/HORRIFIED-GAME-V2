#include "Dracula.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

Dracula::Dracula(): Monster(1, "Dracula", "Crypt"){
            
    casket["Cave"] = 1; 
    casket["Dungeon"] = 1; 
    casket["Crypt"] = 1; 
    casket["Graveyard"] = 1; 
};



unordered_map<string, bool> Dracula::get_casket()const{
    return casket;
}



bool Dracula::Destroy_Casket(string place){

    if(casket.count(place)){

        if(casket[place]){

            casket[place] = 0;
            return true;
        }

        else{
            
            cout << "This casket destroyed befor.\n";
            return false;          
        }
    }

    else{

        cout << "You entered wrong name.\n";
        return false;
    }
}
 bool Dracula::Check_Casket_Destroyed_In_Place(std::string place) {
    return !casket[place] ;
}
bool Dracula::Check_Casket(){
    return  !casket["Cave"] && !casket["Dungeon"] && !casket["Crypt"] && !casket["Graveyard"];
}