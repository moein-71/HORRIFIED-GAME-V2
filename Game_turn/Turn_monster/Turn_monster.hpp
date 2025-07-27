#ifndef TURN_MONSTER_HPP
#define TURN_MONSTER_HPP

#include "../Game_turn.hpp"

class Turn_monster : public Game_turn {

    public :

        bool phase(Game& gamestage) override ;
        void handle_turn(Game& gamestage) override ;

    private :

};

#endif //TURN_MONSTER_HPP