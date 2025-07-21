#include "Turn_monster.hpp"
#include "Turn_hero.hpp"
#include "Egyptian_Expert.hpp"
#include "Former_Employer.hpp"
#include "Form_of_The_Bat.hpp"
#include "Fortune_Teller.hpp"
#include "Hurried_Assistant.hpp"
#include "../../Monster_card/card/Hypnotic_Gaze.hpp"
#include "../../Monster_card/card/On_The_Move.hpp"
#include "Sunrise.hpp"
#include "The_Delivery.hpp"
#include "The_Ichthyologist.hpp"
#include "The_Innocent.hpp"
#include "Thief.hpp"
#include "../../Monster_card/card/Monster_card_empty.hpp"

using namespace std ;

Turn_monster::Turn_monster() : which_turn(1) {}

bool Turn_monster::phase(Game& gamestage) {

    gamestage.turn->handle_turn(gamestage) ;

    shared_ptr<Monster_card> monster_phase = gamestage.get_random_monster_card() ;  

    gamestage.printLineDelay(monster_phase->info()) ;

    monster_phase->ability(gamestage) ; 

    vector<string> villager_name ;
    for(auto villager : gamestage.Game_map.get_villager(gamestage.invisible_man.get_now_place())) {
        villager_name.push_back(villager.get_name()) ;
    }
    gamestage.invisible_man.reset_near_villager(villager_name) ;

    // if(!gamestage.Game_map.get_villager(gamestage.get_invisible_man_place()).empty())
    //     gamestage.increase_Terror_level() ;

    // if(!gamestage.Game_map.get_villager(gamestage.get_dracula_place()).empty())
    // gamestage.increase_Terror_level() ;
        

    return true ;
}

void Turn_monster::handle_turn(Game& gamestage) {

    gamestage.turn = gamestage.hero_turn ;
    
    if(which_turn == 1) {
        gamestage.player_turn = &gamestage.player_2 ;
        which_turn = 2 ;
    }
    else if(which_turn == 2) {
        gamestage.player_turn = &gamestage.player_1 ;
        which_turn = 1 ;
    }

    gamestage.turn = gamestage.hero_turn ;
}

void Turn_monster::set_which_turn(int which_turn) {
    this -> which_turn = which_turn ;
}

int Turn_monster::get_which_turn() {
    return this -> which_turn ;
}
