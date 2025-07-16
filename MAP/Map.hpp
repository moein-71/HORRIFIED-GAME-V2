#ifndef MAP_H
#define  MAP_H


#include <string>
#include <unordered_map>
#include <vector>

#include "Item.hpp"
#include "../VILLAGER/Villager.hpp"
#include "../ITEM/Item.hpp"
#include "../HERO/Mayor.hpp"
#include "../HERO/Archaologist.hpp"

class Mayor ;
class Item ;
class Hero ;
class Archaologist ;
class Villager ;



class Map{

    public:

        Map();
        std::vector<Villager> get_villager(std::string);
        std::string get_villager_place(std::string) ;
        std::string get_villager_safe_place(std::string , std::string) ;
        std::vector<std::string> get_connection(std::string) ;
        std::unordered_map<Item , int> get_item_of_place(std::string);
        int get_item_number(std::string , std::string) ;

        void set_connection();
        void set_item(Item);
        void set_villager(std::string, Villager);//This function add Villager
        bool set_villager_place(std::string, std::string, std::string);//This function edit villager_place

        bool Check_Count_Item_Place(std::string ,std::string) ;
        bool Check_Count_Neighbor_Connection(std::string , std::string) ;
        bool Check_Place_Exist(std::string) ;
        bool Kill_Villager(std::string , std::string = ""); 
        Item Pickeup_Item(std::string, std::string);
        std::string Find_Place_With_More_Item();
        std::vector<std::pair<Item, int>> Remove_All_Item_In_Place(std::string);
        std::string Find_Near_Destination(int, std::string, std::shared_ptr<Hero> , std::shared_ptr<Hero>);
        std::string Move_Monster_Away_From_Hero(std::string, std::shared_ptr<Hero>, std::shared_ptr<Hero>); // where is move 
        std::string Move_Hero_Away_From_Monsters(
            const std::string& hero_location,
            const std::string& monster1_location,
            const std::string& monster2_location,
            const std::string& other_hero_location,
            int max_steps = 2
        );
        int bfs_distance(const std::string& start, const std::string& end);
        void Print_Map_And_All_Info(std::string, std::string, std::string, std::string,
                                    std::unordered_map<std::string, bool>,
                                    std::unordered_map<std::string, bool>,
                                    int
                                );//This function outputs city routes. 
        void Print_Character_Info(std::string, std::string, std::string, std::string);//This function outputs the positions of the characters and items in the game.
        std::string Find_Near_Place_To_Villager(std::string);
        void Move_Villager_To_Safe_House();
        std::string Move_Character_Near_Dracula(std::string , std::shared_ptr<Hero>, std::shared_ptr<Hero>);
        std::string repeat(const std::string& s, int n) ;
    private:

        std::unordered_map<std::string, std::vector<std::string>> connection;
        std::unordered_map<std::string, std::vector<Villager>> villager_place;
        std::unordered_map<std::string, std::unordered_map<Item, int>> item_place;
};

#endif //MAP_H