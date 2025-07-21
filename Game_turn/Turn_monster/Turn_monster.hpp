#ifndef TURN_MONSTER_HPP
#define TURN_MONSTER_HPP

#include "../Game_turn.hpp"

class Turn_monster : public Game_turn {

    public :

        Turn_monster() ;
        bool phase(Game& gamestage) override ;
        void handle_turn(Game& gamestage) override ;
        void set_which_turn(int which_turn) ;
        int get_which_turn() ;

    private :

        int which_turn ; // if 1 play player to , if 2 play player 1 
};

#endif //TURN_MONSTER_HPP