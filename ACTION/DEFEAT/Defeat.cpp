#include "Defeat.hpp"
#include <bits/stdc++.h>

using namespace std;

bool Defeat::Activate(Game& game) {
    if(game.player_turn->get_Player_Hero()->get_now_place() == game.get_dracula_place()) {
        if(game.dracula.Check_Casket()) {
            vector<Item> defeat_item = game.player_turn->get_Player_Hero()->get_item("Yellow" , 6) ;

            if(!defeat_item.empty()) {
                game.set_dracula_place("DEAD") ;
                cout<< "Dracula died\n" ;
                return true ;
            }
            else {
                cout<< "You cant defeat dracula\n" ;
                return false ;
            }
        }
        else {
            cout<< "All of the Caskets are not destroyed\n" ;
            return false ;
        }
    }
    else if(game.player_turn->get_Player_Hero()->get_now_place() == game.get_invisible_man_place()) {
        if(game.invisible_man.check_investigate()) {
             vector<Item> defeat_item = game.player_turn->get_Player_Hero()->get_item("Red" , 9) ;

            if(!defeat_item.empty()) {
                game.set_invisible_man_place("DEAD") ;
                cout<< "Invisible_man died\n" ;
                return true ;
            }
            else {
                cout<< "You cant defeat invisible_man\n" ;
                return false ;
            }
        }
        else {
            cout<< "All of the investigates are not found\n" ;
            return false ;
        }
    }
    else {
        cout<< "You are not in the monster place\n" ;
        return false ;
    }
}

std::string Defeat::info()const {
    return "DEFEAT : Is for defeating Monsters\n" ;
}