#include "Late_into_the_Night.hpp"

using namespace std ;

Late_into_the_night::Late_into_the_night() {
    this -> set_perk_name("Late_into_the_night") ;
}

void Late_into_the_night::ability(Game& gamestage) {

    const int added_action = 2 ;

    gamestage.set_added_action(added_action) ; 
}

void Late_into_the_night::info() const {

    cout<< "add two action to now turn player actions\n" ;
}
