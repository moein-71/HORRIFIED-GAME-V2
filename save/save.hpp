#include "Game.hpp"
#include <utility>

struct Save {

    std::string Terror_level = "6" ;

    std::string which_turn = "1" ; // in this we should change player_turn in game and whitch_turn in monster_turn 
    std::string remain_actions ;

    std::string dracula_place = "Crypt" ;
    std::array<std::pair<std::string , bool> , 4> dracula_casket ;

    std::string invisible_man_place = "Inn" ;
    std::array<std::pair<std::string , bool> , 4> invisible_man_investigate ;

    std::string frenzy_monster = "Dracula" ;

    std::string player_1_hero ;
    std::string player_1_name ;
    std::string player_1_place ;
    std::vector<std::pair<std::string , int>> player_1_items ;
    std::vector<std::string> player_1_perk_card ;

    std::string player_2_hero ;
    std::string player_2_name ;
    std::string player_2_place ;
    std::vector<std::pair<std::string , int>> player_2_items ;
    std::vector<std::string> player_2_perk_card ;

    std::vector<std::string> item_in_bag ;
    std::vector<std::string> item_in_map ;

    std::vector<std::string> villager_in_bag ;
    std::vector<std::pair<std::string , std::string>> villager_in_map ; //vilager name , villager place

    std::vector<std::string> perk_card_remain_in_bag ;
    std::vector<std::string> monster_card_remain_in_bag ;
} ;