#include "Move_Hero.hpp"
#include <bits/stdc++.h>

using namespace std;

bool Move_Hero::Activate(Game& game){

    string now_place = game.player_turn->get_Player_Hero() -> get_now_place();
    auto neighbor = game.Game_map.get_connection(now_place);
    game.printLineDelay("Your now place : " + now_place) ; 

    game.printLineDelay("Your Neighbor_places :\n");
    for(auto neighbor_place_name: neighbor){
        game.printLineDelay(neighbor_place_name+ "   "); 
    }
    cout << "\n";

    bool Hozoor{};
    bool found{0};
    string choose_place_name;
    cin.ignore() ;
    while(!found){

        Hozoor = 0;

        game.printLineDelay("Enter where you go , or exit.\n");
        getline(cin, choose_place_name);
        
        if(choose_place_name == "exit")
            return false ;

        for(auto neighbor_place_name: neighbor){
            
            if(neighbor_place_name == choose_place_name){

                Hozoor = 1;

                vector<Villager> villager = game.Game_map.get_villager(now_place);

                if(villager.empty()){

                    game.player_turn->get_Player_Hero() -> set_now_place(choose_place_name);
                    return true ;
                }
                
                for(int i{}; i < villager.size(); ++i){
                    cout << "Villager name: " << villager[i].get_name() << '\n';
                }
                cout << "___________________________________________________________________\n";

                game.player_turn->get_Player_Hero() -> set_now_place(choose_place_name);

                while(1){

                    cout << "Please enter villager's name that you want or write exit.\n";
                    string villager_name;
                    getline(cin, villager_name);

                    if(villager_name == "exit"){
                        found = 1;
                        return true ;
                    }

                    if(!(game.Game_map.set_villager_place(now_place, choose_place_name, villager_name))){
                        cout << "Please enter the right name.\n";
                    }
                    else {
                        if(choose_place_name == game.Game_map.get_villager_safe_place(choose_place_name , villager_name)) {
                            game.player_turn->get_Player_Hero()->set_perk(game.get_random_perk()) ;
                        }   
                    }
                }
            }
        }
        if(!Hozoor){
            cerr << "There is no place with this name.\n";
        }
        
    }
    return false ;
}

std::string Move_Hero::info()const {
    return "MOVE : You can move your self and villagers with this action\n" ;
}