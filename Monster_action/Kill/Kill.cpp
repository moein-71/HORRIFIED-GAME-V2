#include "Kill.hpp"
#include "variant"
#include "../../ITEM/Item.hpp"

using namespace std ;

bool Kill::activate(Game & game , const std::string & monster) {


    if(monster == game.dracula.get_name()) {
        if(game.get_dracula_place() == game.player_1.get_Player_Hero()->get_now_place()) { //archaologist
            game.printLineDelay("Dracula want to kill you " + game.player_1.get_Player_Hero()->get_name()) ; 
            auto item_or_bool = game.player_1.get_Player_Hero()->When_Monster_Killed_A_Hero() ;
            if (auto p = get_if<Item>(&item_or_bool)) {
                game.set_item_bag(*p) ;
            }
            else {
                game.increase_Terror_level() ;
            }
            game.printLineDelay(game.get_dracula_name() + " Kill the archaologist\n") ;
            return true ;
        }
        else if(game.get_dracula_place() == game.player_2.get_Player_Hero()->get_now_place()) { //mayor
            game.printLineDelay("Dracula want to kill you " + game.player_2.get_Player_Hero()->get_name()) ; 
            auto item_or_bool = game.player_2.get_Player_Hero()->When_Monster_Killed_A_Hero() ;
            if (auto p = get_if<Item>(&item_or_bool)) {
                game.set_item_bag(*p) ;
            }
            else {
                game.increase_Terror_level() ;
            }
            game.printLineDelay(game.get_dracula_name() + " Kill the mayor\n") ;
            return true ;
        }
        if(game.Game_map.Kill_Villager(game.dracula.get_now_place())) {
            game.printLineDelay(game.get_dracula_name() + " Kill a villager in the night\n") ;
            game.increase_Terror_level() ;
            return true ;
        } 
    }
    else if(monster == game.invisible_man.get_name()) {
        for(auto kill_villager : game.Game_map.get_villager(game.invisible_man.get_now_place())) {
            if(game.invisible_man.can_kill_villager(kill_villager.get_name())) {
                if(game.Game_map.Kill_Villager(game.invisible_man.get_now_place() , kill_villager.get_name())) {
                    game.printLineDelay(game.get_invisible_man_name() + " Kill a villager in the day\n") ;
                    game.increase_Terror_level() ;
                    return true ;
                }
            }
        }
    }

    // throw runtime_error("somthing goes wrong in Kill") ;    
    game.printLineDelay("Kill of " + monster + " is not successful\n") ;
    return false ;
}   
