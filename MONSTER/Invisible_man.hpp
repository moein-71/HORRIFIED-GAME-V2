#ifndef INVISIBLE_MAN_H
#define INVISIBLE_MAN_H

#include "./Monster.hpp"
#include "../VILLAGER/Villager.hpp"
#include <unordered_map>
#include <vector>
#include <string>

class Invisible_man : public Monster {

    public:

        Invisible_man();

        std::unordered_map <std::string, bool> get_investigate()const;
        void reset_near_villager(std::vector<std::string>);
        bool can_kill_villager(std::string);
        bool set_investigate_found(std::string);
        bool check_investigate() ;
       

    private:

        std::unordered_map <std::string, bool> investigate;
        std::unordered_map <std::string , bool> near_villager;
};

#endif//INVISIBLE_MAN_H