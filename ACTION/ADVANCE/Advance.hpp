#ifndef ADVANCE_HPP
#define ADVANCE_HPP

#include "../Hero_Action.hpp"
#include <string>


class Advance: public Hero_Action{

    public:

        bool Activate(Game&);
        std::string info()const;
};

#endif//ADVANCE_HPP