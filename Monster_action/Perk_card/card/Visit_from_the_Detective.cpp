#include "Visit_from_the_Detective.hpp"

using namespace std ;

Visit_from_the_detective::Visit_from_the_detective() {
    this -> set_perk_name("Visit_from_the_detective") ;
}

void Visit_from_the_detective::ability(Game& gamestage) {
    
    if(gamestage.get_invisible_man_place() == "DEAD") {
        return ;
    }
    string place ;
    cout<< "\nWhich place you want to send Invisible Man ?\n" ;
    gamestage.print_map() ;
    cin>> place ;
    
    if(place == "exit") {
        return ;
    }
    while(!gamestage.Check_Place_Exist_in_map(place)) { // this func should check the place if its currect return true //
        cin>> place ;
        if(place == "exit") {
            return ;
        }
    }
    gamestage.set_invisible_man_place(place) ;
}

void Visit_from_the_detective::info() const {
    cout<< "\nVisit from the Detective\n"
    << "You can move Invisible Man where ever you want\n" ;
}
