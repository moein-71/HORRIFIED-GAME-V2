#ifndef MOVE_MONSTER_HPP
#define MOVE_MONSTER_HPP

#include "../Monster_action.hpp"

class Move_monster : public Monster_action {

    public :

        bool activate(Game & game , const std::string & monster) override ;   

    private :

} ;

#endif //MOVE_MONSTER_HPP
