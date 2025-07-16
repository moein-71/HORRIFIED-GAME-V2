#ifndef MOVE_HERO_H
#define MOVE_HERO_H

#include "../Hero_Action.hpp"
#include <string>


class Move_Hero: public Hero_Action{

    public:

        bool Activate(Game&);
        std::string info()const;
};

#endif//MOVE_HERO_H