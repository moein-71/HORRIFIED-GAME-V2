#ifndef Game_HPP
#define Game_HPP

#include <memory> 
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <random>
#include <stdexcept>
#include <new>
#include <format>
#include <array>
#include <set>
#include <unordered_map>
#include <thread>
#include <chrono>
#include "../MAP/Map.hpp"
#include "Archaologist.hpp"
#include "Mayor.hpp"
#include "../MONSTER/Dracula.hpp"
#include "Invisible_man.hpp"
#include "Player.hpp"

class Game_turn ;
class Turn_monster ;
class Turn_archaologist ;
class Turn_mayor ;
class Map ;
class Villager ;
class Perk_card ;
class Monster_card ; 
class Special_Action ;
class Pick_Up ;
class Move_Hero ;
class Guide ;
class Defeat ;
class Advance ;
class Program ;
class Menu ;

class Game {

    friend class Move_monster ;
    friend class Kill ;
    friend class Power ;
    friend class Special_Action ;
    friend class Pick_Up ;
    friend class Move_Hero ;
    friend class Guide ;
    friend class Defeat ;
    friend class Advance ;
    friend class Turn_monster ;
    friend class Turn_hero ;
    friend class Game_turn ;
    friend class Program ;
    friend class Menu ;

    public :

        Game() ;
        
        void set_player_1(std::shared_ptr<Hero> player_1_hero) ;
        void set_player_2(std::shared_ptr<Hero> player_2_hero) ;
        int random_number() ;
        Item get_random_item() ; 
        Item get_item(std::string name) ;
        void set_item_bag(Item new_item) ;
        void set_item_to_map(Item new_item) ;
        void remove_not_exist_items_in_save(std::vector<std::string> exist_items) ;
        std::shared_ptr<Perk_card> get_random_perk() ; 
        std::shared_ptr<Perk_card> get_perk(std::string name) ;
        std::shared_ptr<Monster_card> get_random_monster_card() ;
        Villager get_villager(std::string name) ;
        void remove_not_exist_villagers_in_save(std::vector<std::string> exist_villagers) ;
        void remove_not_exist_perk_cards_in_save(std::vector<std::string> exist_perks) ;
        void remove_not_exist_monster_cards_in_save(std::vector<std::string> exist_monster_card) ;

        char throw_dice() ; 

        std::string find_place_with_more_item_map() ;
        bool remove_all_item_in_place(std::string place) ;

        void print_map() ;

        std::string find_far_destination_monster_map(int move , std::string place , std::string archaologist_place , std::string mayor_place) ;
        std::string find_far_destination_hero_map(int move , std::string place , std::string dracula_place , std::string Invisible_man_place) ;

        void handle_turn() ;

        void set_invisible_man_place(const std::string place) ; //we need validation on place 
        void set_dracula_place(const std::string place) ; //we need validation on place
        void set_last_hero_turn(const std::string & new_turn) ;
        void set_player_1_place(const std::string & place) ; //we need validation on place
        void set_player_2_place(const std::string & place) ; //we need validation on place
        void set_frenzy_monster(const std::string & name) ; //we need validation on place
        void set_villager_in_Game_map(const std::string place , const std::string name) ; //we need validation on place
        void set_added_action(const int & added_action) ;
        std::string get_invisible_man_place() ;
        std::string get_dracula_place() ;
        std::string get_last_hero_turn() ;
        std::string get_player_1_place() ;
        std::string get_player_2_place() ;
        std::string get_player_1_hero_name() ;
        std::string get_player_2_hero_name() ;
        std::string get_frenzy_monster() ;
        std::string get_dracula_name() ;
        std::string get_invisible_man_name() ;
        int get_added_action() ;
        int get_monster_card_number() ;

        std::string move_character_near_dracula(std::string dracula_place) ;
        void move_villager_to_safe_place() ;
        bool Check_Place_Exist_in_map(std::string place) ;

        void increase_Terror_level() ;
        int get_Terror_level() ;

        void printLineDelay(const std::string& line, int delayMs = 20) ; //20

    private :
    
        int Terror_level ;
        int added_action ;
        int which_turn ; // if 1 play player to , if 2 play player 1 
        int remain_actions ;
        Player * player_turn ;
        std::shared_ptr<Game_turn> turn = nullptr ;
        std::shared_ptr<Game_turn> hero_turn = nullptr ;
        std::shared_ptr<Game_turn> monster_turn = nullptr ;
        Player player_1 ;
        Player player_2 ;
        std::string last_hero_turn ;
        Map Game_map ;
        Dracula dracula ;  
        Invisible_man invisible_man ;
        std::string frenzy_monster ; // first dracula // name of the monsters save in it 
        std::vector<Villager> villagers_bag ;
        std::vector<std::shared_ptr<Perk_card>> perk_bag ;
        std::vector<std::shared_ptr<Monster_card>> Monster_cards_bag ;
        std::vector<Item> item_bag ;
} ;

#endif //Game_HPP

