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
 bool Dracula::Check_Casket_Destroyed_In_Place(string place) {
    return !casket[place] ;
}
bool Dracula::Check_Casket(){
    return  !casket["Cave"] && !casket["Dungeon"] && !casket["Crypt"] && !casket["Graveyard"];
}

array<pair<string , bool> , 4> Dracula::get_casket_for_save() {
    array<pair<string , bool> , 4>  return_casket ;

    int i{} ;
    for(auto this_casket : this->casket) {
        return_casket[i] = {this_casket.first , this_casket.second} ;
        ++i ;
    }

    return return_casket ;
}