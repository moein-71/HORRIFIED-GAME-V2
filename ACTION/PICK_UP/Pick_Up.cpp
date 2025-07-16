#include "Pick_Up.hpp"
#include <bits/stdc++.h>///////////////////////////////investigate 

using namespace std;

bool Pick_Up::Activate(Game& game){

    string now_place = game.player_turn->get_Player_Hero() -> get_now_place();
    auto unordered_item = game.Game_map.get_item_of_place(now_place);

    if(unordered_item.empty()) {
        game.printLineDelay("There is no item in this place") ;
        return false ;
    }

    for(auto pair_item: unordered_item){
        game.printLineDelay( "Item name: " + pair_item.first.get_name() + " , " + "Number item: " + to_string(pair_item.second));
    }

    int choose_number;
    string choose_name;
    string exeption_choose_number;

    int counter = 0 ;
    while(1){
        game.printLineDelay("Enter the item name , for exit type : exit\n");
        cin>> choose_name ;

        if(choose_name == "exit") {
            if(counter == 0) {
                return false ;
            }
            return true ;
        }

        game.printLineDelay("Enter number of item :");
        cin.ignore() ;
        getline(cin, exeption_choose_number);

        istringstream iss(exeption_choose_number);

        if(game.Game_map.Check_Count_Item_Place(now_place, choose_name)){

            if(iss >> choose_number && choose_number > 0 && choose_number <= game.Game_map.get_item_number(now_place, choose_name)){

                int item_number = game.Game_map.get_item_number(now_place, choose_name) ;

                for(int i{} ; i < choose_number ; ++i){

                    game.player_turn->get_Player_Hero() ->set_item(game.Game_map.Pickeup_Item(now_place, choose_name));
                    counter++ ; 
                }
            }
            else{
                cerr << "Please enter the right value;\n";
            }
        }
        else{
            cerr << "Please enter the right name of item.\n";
        }
    }
}

std::string Pick_Up::info()const {
    return "PICK_UP : With action you can pick how many item you want from your place\n" ;
}