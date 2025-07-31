#include "Thief.hpp"
#include "../../Monster_action/Move_monster/Move_monster.hpp"
#include "../../Monster_action/Kill/Kill.hpp"
#include "../../Monster_action/Power/Power.hpp"

using namespace std ;

Thief::Thief() {
    this -> set_name("Thief") ;
}

 void Thief::ability(Game& gamestage) {

    constexpr int add_item = 2 ;
    constexpr int move = 1 ;
    constexpr int dice_number = 3 ;
    constexpr int strike_number = 2 ;

    //Item
    
    for(int i{} ; i < add_item ; ++i) {
        gamestage.set_item_to_map(gamestage.get_random_item()) ;
    }

    //Event

    gamestage.set_invisible_man_place(gamestage.find_place_with_more_item_map()) ;
    gamestage.remove_all_item_in_place(gamestage.get_invisible_man_place()) ;

    //Strike

    array<string , strike_number> monster_turn {gamestage.get_invisible_man_name() , gamestage.get_dracula_name()} ;

    unique_ptr<Monster_action> action = make_unique<Move_monster>() ;

    vector<shared_ptr<Power>> invisible_man_power ;

    bool kill = false ; 

    for(int i{} ; i < strike_number ; ++i ) {

        if(monster_turn[i] == gamestage.get_dracula_name()) {
            if(gamestage.get_dracula_place() == "DEAD") {
                continue ;
            }
        }

        if(monster_turn[i] == gamestage.get_invisible_man_name()) {
            if(gamestage.get_invisible_man_place() == "DEAD") {
                continue ;
            }
        }

        if(kill) break ;

        //Move 
        action = make_unique<Move_monster>() ;
        for(int j{} ; j < move ; ++j) {
            action->activate(gamestage , monster_turn[i]) ;
        }
        gamestage.printLineDelay(monster_turn[i] + " move to " + (monster_turn[i] == gamestage.get_dracula_name() ? gamestage.get_dracula_place() : gamestage.get_invisible_man_place())) ;


        //Dice
        set<char> dice ;

        for(int j{} ; j < dice_number ; ++j) {
            dice.insert(gamestage.throw_dice()) ;
        }

        for(char chance : dice) {
            if(chance == 'K') { //Kill
                action = make_unique<Kill>() ;
                if(action->activate(gamestage ,monster_turn[i])) {
                    kill = true ;
                    break ;
                }
                else {
                    continue;
                }
            }
            else if(chance == 'P') { //Power
                if(monster_turn[i] == gamestage.get_invisible_man_name()) {
                    invisible_man_power.push_back(make_shared<Power>()) ;
                    break ;
                }
                else if(monster_turn[i] == gamestage.get_dracula_name()) {
                    action = make_unique<Power>() ;
                    action->activate(gamestage , gamestage.get_dracula_name()) ;
                    break ;
                }
                else {
                    throw invalid_argument("somthing in ability sunrise goes wrong") ;
                }
            }
            else if(chance == 'Z') {
                break ;
            }
        }
    }

    if(invisible_man_power.empty()) {
        return ;
    }
    action = make_unique<Power>() ;
    for(auto active_power : invisible_man_power) {
        active_power->activate(gamestage , gamestage.get_invisible_man_name()) ;
    }
}

std::string Thief::info() const {
    string info = "\nThief\n" ;
    info +=  "add 2 item\n" ;
    info +=  "Move the Invisible Man to the location with the highest number of items" ;
    info +=  "\nremove all items from that location on the map and return them outside the game\n" ;
    info +=  "Strike : 1 Move , 3 Dice\n" ;
    info +=  "Turn : Invisible Man , Dracula\n" ;
    return info ;
}
