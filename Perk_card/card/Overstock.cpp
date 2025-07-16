#include "Overstock.hpp"

using namespace std ;

Overstock::Overstock() {
    this -> set_perk_name("Overstock") ;
}

void Overstock::ability(Game& gamestage)  {

    const int player = 2 ;

    for(int i{} ; i < 2 ; ++i) {
        gamestage.set_item_to_map(gamestage.get_random_item()) ;
    }
}

void Overstock::info() const  {
    
    cout<< "every player pick an item and placed in its location \n" ; 
}