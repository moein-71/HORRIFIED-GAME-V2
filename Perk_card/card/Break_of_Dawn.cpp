#include "Break_of_Dawn.hpp"

using namespace std ;

Break_of_dawn::Break_of_dawn() {
    this -> set_perk_name("Break_of_dawn") ;
}

void Break_of_dawn::ability(Game& gamestage) {

    const int add_item = 2 ; 

    gamestage.handle_turn() ; // check this //

    for(int i{} ; i < add_item ; ++i) {
        gamestage.set_item_to_map(gamestage.get_random_item()) ;
    }
}

void Break_of_dawn::info() const {

    cout<< "\nskip next monster phase\n" 
    << "add 2 item to map\n" ; 
}
