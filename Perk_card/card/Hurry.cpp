#include "Hurry.hpp"

using namespace std ;

Hurry::Hurry() {
    this -> set_perk_name("Hurry") ;
}

void Hurry::ability(Game& gamestage) {

    const int move_hero = 2 ;

    
    gamestage.set_player_1_place(gamestage.find_far_destination_hero_map(move_hero ,
        gamestage.get_player_1_place() ,
        (gamestage.get_dracula_place() != "DEAD" ? gamestage.get_dracula_place() : gamestage.get_invisible_man_place()) ,
        (gamestage.get_invisible_man_place() != "DEAD" ? gamestage.get_invisible_man_place() : gamestage.get_dracula_place()))) ;

    gamestage.set_player_2_place(gamestage.find_far_destination_hero_map(move_hero ,
        gamestage.get_player_2_place() ,
        (gamestage.get_dracula_place() != "DEAD" ? gamestage.get_dracula_place() : gamestage.get_invisible_man_place()) ,
        (gamestage.get_invisible_man_place() != "DEAD" ? gamestage.get_invisible_man_place() : gamestage.get_dracula_place()))) ;
}

void Hurry::info() const {

    cout<< "move Heros two block far away from Monsters  \n" ;
}
