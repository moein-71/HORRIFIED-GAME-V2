#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "Villager.hpp"

class Monster{

    public:

        Monster() = default;
        Monster(int, std::string, const std::string);

        int get_frenzy()const;
        std::string get_name()const;
        std::string get_now_place();
        std::string get_spawn_place()const;

        void set_now_place(std::string);

        void printLineDelay(const std::string& line, int delayMs = 30) ;

    private:

        const int frenzy;
        const std::string name;
        std::string now_place;
        const std::string spawn_place ;
};

#endif