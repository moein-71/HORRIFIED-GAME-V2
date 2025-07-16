#include "Repel.hpp"

using namespace std ;

Repel::Repel() {
    this -> set_perk_name("Repel") ;
}

void Repel::ability(Game& gamestage)  {

    const int move_monster = 2 ;

    if(gamestage.get_dracula_place() != "DEAD")
        gamestage.set_dracula_place(gamestage.find_far_destination_monster_map(move_monster , gamestage.get_dracula_place() , gamestage.get_player_1_place() , gamestage.get_player_2_place())) ;

    if(gamestage.get_invisible_man_place() != "DEAD")
        gamestage.set_invisible_man_place(gamestage.find_far_destination_monster_map(move_monster , gamestage.get_invisible_man_place() , gamestage.get_player_1_place() , gamestage.get_player_2_place())) ;
}

void Repel::info() const  {

        cout<< "move Monsters two block far away from People  \n" ; 
}
