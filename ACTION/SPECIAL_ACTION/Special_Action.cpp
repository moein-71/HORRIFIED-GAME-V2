#include "Special_Action.hpp"
#include <bits/stdc++.h>

using namespace std;

bool Special_Action::Activate(Game& game){
    if(game.player_turn->get_Player_Hero() -> get_name() == "Archaologist") {   
        auto neighbor = game.Game_map.get_connection(game.player_turn->get_Player_Hero()->get_now_place());

        for(auto name_neighbor_place: neighbor){

            game.printLineDelay( "Place name:" + name_neighbor_place + '\n');

            for(auto item_info: game.Game_map.get_item_of_place(name_neighbor_place)){
                    game.printLineDelay( "Item name:" + item_info.first.get_name() + "  " + "Number item:" + to_string(item_info.second) + '\n' );
            }
            game.printLineDelay( "____________________________________________________________________\n");
        }

        string choose;

        int counter = 0 ;
        while(1){
            counter++ ;
            game.printLineDelay( "Please enter a place_name or write exit for exit :\n");
            cin>> choose ;

            if(choose == "exit") {
                return false ;
            }
            
            if(game.Game_map.Check_Count_Neighbor_Connection(game.player_turn->get_Player_Hero()->get_now_place() , choose)){

                auto it = game.Game_map.get_item_of_place(choose);

                if(it.empty()) {
                    return false ;
                }
                
                game.Game_map.Remove_All_Item_In_Place(choose);

                for(auto pair_it: it){
                    for(int i{}; i < pair_it.second; ++i){
                        game.player_turn->get_Player_Hero()->set_item(pair_it.first) ;
                    }
                }
                return true ;
            }
            else{
                game.printLineDelay( "Please enter the right name.\n");
            }
        }
    }

    else if(game.player_turn->get_Player_Hero() -> get_name() == "Courier") {
        if(*game.player_turn == game.player_1) {
            
            string choose ;

            while(1) {
                game.printLineDelay("\nYou want to go in " + game.player_2.get_Player_Hero()->get_name() + " place ? ") ;
                game.printLineDelay("y or n") ;
                cin>> choose ;

                if(choose == "y") {
                    game.player_turn->get_Player_Hero()->set_now_place(game.player_2.get_Player_Hero()->get_now_place()) ;
                    return true ;
                }
                else if(choose == "n") {
                    return false ;
                }
            }
        }
        if(*game.player_turn == game.player_2) {
            string choose ;

            while(1) {
                game.printLineDelay("\nYou want to go in " + game.player_1.get_Player_Hero()->get_name() + " place ? ") ;
                game.printLineDelay("y or n") ;
                cin>> choose ;

                if(choose == "y") {
                    game.player_turn->get_Player_Hero()->set_now_place(game.player_1.get_Player_Hero()->get_now_place()) ;
                    return true ;
                }
                else if(choose == "n") {
                    return false ;
                }
            }
        }
    }

    else {
        game.printLineDelay("You dont have any special action") ;
        return false ;
    }
    return false ;
}
std::string Special_Action::info()const{
    return "SPECIAL_ACTION : Archaologist can get how many item he want from Neighbor places\n" ;
}