#ifndef HERO_H
#define HERO_H

#include <string>
#include <unordered_map>
#include <memory>
#include <variant>
#include <vector>
#include "../ITEM/Item.hpp"
#include <variant>

class Item ;
class Perk_card ;

class Hero{

    public:

        Hero() = default;
        Hero(std::string, std::string, bool, int);

        void set_name(std::string);
        void set_player_name(std::string);
        void set_spawn_place(std::string);
        void set_now_place(std::string);
        void set_item(Item);
        void set_perk(std::shared_ptr<Perk_card>) ;

        bool get_special_action_info()const;
        int get_action()const;
        std::string get_name()const;
        std::string get_player_name()const;
        std::string get_spawn_place()const;
        std::string get_now_place()const;
        std::variant<std::shared_ptr<Perk_card> , bool> get_perk();
        std::vector <Item> get_item(std::string, int);
        std::vector<Item> get_investigate_item() ;
        void remove_item_from_bag(Item& , std::unordered_map <Item, int>* = nullptr);

        void Describe_Hero_Special_Action();//this function describe the special action of all hero
        std::variant<int, Item> When_Monster_Killed_A_Hero();
        Item Back_To_Life_By_Use_An_Item();
        void Go_To_Hospital();
        void Print_Hero_Info();
        std::string repeat(const std::string& s, int n) ;
        void printLineDelay(const std::string& line, int delayMs = 30) ; //30
        std::vector<std::pair<std::string , int>> get_items_for_save() ;
        std::vector<std::string> get_perk_for_save() ;

        
    private:

        const bool special_action_info;
        const int action;
        std::string name;
        std::string player_name;
        std::string spawn_place;
        std::string now_place;


        std::unordered_map <std::shared_ptr<Perk_card>, int> perk;
        std::unordered_map <Item, int> item;
        std::vector<std::string> investigate_place ;
};

#endif//HERO_H