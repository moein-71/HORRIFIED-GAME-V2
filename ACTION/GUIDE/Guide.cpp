#include "Guide.hpp"
#include <bits/stdc++.h>

using namespace std;

bool Guide::Activate(Game& game){

    bool Hozoor = 0;
    string now_place = game.player_turn->get_Player_Hero() -> get_now_place();
    auto neighbor = game.Game_map.get_connection(now_place);

    auto vector_villager_info = game.Game_map.get_villager(now_place);
    if(!vector_villager_info.empty()){

        Hozoor = 1;
        game.printLineDelay("Villagers who are in our current location.\n\n");
        for(auto villager: vector_villager_info){
            game.printLineDelay("Villager's name: " + villager.get_name() + "  ") ;
        }

        cout << "_______________________________________________________\n";
    }
    for(auto neighbor_place_name: neighbor){

        vector_villager_info = game.Game_map.get_villager(neighbor_place_name);
        if(!vector_villager_info.empty()){

            Hozoor = 1;
            game.printLineDelay("Villagers who are in location " + neighbor_place_name + "\n\n");
            for(auto villager: vector_villager_info){
                game.printLineDelay("Villager's name: " + villager.get_name() + "  ");
            }  
            cout << "_______________________________________________________\n\n";
        }
    }
    if(!Hozoor){
        game.printLineDelay("Unfortunately, there are no villagers in your neighborhood and you cannot use this action.\n\n");
        return false ;
    }

    string choose;
    string report;
    string villager_name;
    string choose_place_name;
    int counter = 0 ;

    while(1){
        counter++ ;
        game.printLineDelay("For sending villager to a neighbor location , Enter A\nFor bring back villager from neighbor location , Enter B.\nor write exit to stop this action.\n\n",20);
        cin>>choose ;

        if(choose == "exit") {
                return false ;
        }
        else if(choose == "A"){

            while(1){
                game.printLineDelay("Enter the name of the place :");
                cin>> choose_place_name ;

                if(choose_place_name == "exit") {
                        return false ;
                }

                game.printLineDelay("Enter villager's name or write exit : ");
                cin.ignore() ;
                cin>> villager_name ;

                if(villager_name == "exit")
                        return false ;
                    

                report = send_villager_another_place(now_place, choose_place_name, villager_name, neighbor, game , game.player_turn->get_Player_Hero());
                game.printLineDelay(report + '\n');
                if(report == "Successful") {
                    if(choose_place_name == game.Game_map.get_villager_safe_place(choose_place_name , villager_name)) {
                            game.player_turn->get_Player_Hero()->set_perk(game.get_random_perk()) ;
                    }   
                    return true ;
                }
                else {
                    return false ;
                }
            }
        } 
        else if(choose == "B"){
            
            while(1){
                 game.printLineDelay("Enter the name of the place :");
                cin>> choose_place_name ;

                if(choose_place_name == "exit") {
                        return false ;
                }

                game.printLineDelay("Enter villager's name or write exit : ");
                cin>> villager_name ;

                if(villager_name == "exit")
                        return false ;

                report = take_villager_another_place(now_place, choose_place_name, villager_name, neighbor, game , game.player_turn->get_Player_Hero());
                cout << report << '\n';
                if(report == "Successful") {
                    if(now_place == game.Game_map.get_villager_safe_place(now_place , villager_name)) {
                            game.player_turn->get_Player_Hero()->set_perk(game.get_random_perk()) ;
                    }   
                    return true ;
                }
                else {
                    continue;
                }
            }
        }
        else{
            cerr<< "Please enter the right command.\n";
        }
    }
}
string Guide::send_villager_another_place(string now_place, string choose_place_name, string villager_name, vector<string> neighbor, Game& game , shared_ptr<Hero> hero){

    bool Hozoor = 0;
    for(auto place_name: neighbor){
        if(choose_place_name == place_name){
            Hozoor = 1;
            break;
        }
    }
    if(!Hozoor)
        return "The place name you entered does not exist at neighbor of the current location.(field)";

    Hozoor = 0;
    auto villager_info = game.Game_map.get_villager(now_place);
    for(auto villager: villager_info){
        if(villager.get_name() == villager_name){
            Hozoor = 1;
            break;
        }
    }
    if(!Hozoor)
        return "The villager name you entered does not exist at the current location.(field)";

    game.Game_map.set_villager_place(now_place , choose_place_name, villager_name); 

    return "Successful" ;
}

string Guide::take_villager_another_place(string now_place, string choose_place_name, string villager_name, vector<string> neighbor, Game& game , shared_ptr<Hero> hero){

    bool Hozoor = 0;
    for(auto place_name: neighbor){
        if(choose_place_name == place_name){
            Hozoor = 1;
            break;
        }
    }
    if(!Hozoor)
        return "The place name you entered does not exist at neighbor of the current location.(field)";

    auto villager_info = game.Game_map.get_villager(choose_place_name);
    for(auto villager: villager_info){
        if(villager.get_name() == villager_name){
            Hozoor = 1;
            break;
        }
    }
    if(!Hozoor)
        return "The villager name you entered does not exist at the current location.(field)";

    game.Game_map.set_villager_place(choose_place_name , now_place , villager_name);

    return "Successful" ;
}

std::string Guide::info()const {
    return "GUIDE : With this action you can send a villager to another place or take villager\n" ;
}