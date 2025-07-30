#include "Move_monster.hpp"

using namespace std ;

bool Move_monster::activate(Game & game , const string & monster) {

    if(monster == game.get_dracula_name()) {
        game.dracula.set_now_place(game.Game_map.Find_Near_Destination(1 , game.dracula.get_now_place() , game.player_1.get_Player_Hero() , game.player_2.get_Player_Hero())) ;
        return true ;
    }
    else if(monster == game.get_invisible_man_name()) {
        game.invisible_man.set_now_place(game.Game_map.Find_Near_Destination(1 , game.invisible_man.get_now_place() , game.player_1.get_Player_Hero() , game.player_2.get_Player_Hero())) ;
        return true ;
    }

    return false ;
    
}

