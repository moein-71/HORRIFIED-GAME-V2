#include "Power.hpp"

using namespace std ;

bool Power::activate(Game & game , const std::string & monster) {

    if(monster == game.dracula.get_name()) {
            game.get_last_hero_turn() == game.player_1.get_Player_Hero()->get_name() ? game.player_1.get_Player_Hero()->set_now_place(game.get_dracula_place()) : game.player_2.get_Player_Hero()->set_now_place(game.get_dracula_place()) ;
            game.printLineDelay("Power of " + game.get_dracula_name() + " done\n") ;
            return true ;
    }
    else if(monster == game.invisible_man.get_name()) {
            game.invisible_man.set_now_place(game.Game_map.Find_Near_Place_To_Villager(game.invisible_man.get_now_place())) ;
            game.printLineDelay("Power of " + game.get_invisible_man_name() + " done\n") ;
            return true ;
    }


    return false ;
}

