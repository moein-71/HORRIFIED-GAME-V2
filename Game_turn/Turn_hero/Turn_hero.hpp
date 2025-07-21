#ifndef TURN_HERO_HPP
#define TURN_HERO_HPP

#include "../Game_turn.hpp"
#include "../../Perk_card/card/Break_of_Dawn.hpp"
#include "../../Perk_card/card/Hurry.hpp"
#include "../../Perk_card/card/Late_into_the_Night.hpp"
#include "../../Perk_card/card/Overstock.hpp"
#include "../../Perk_card/card/Repel.hpp"
#include "../../Perk_card/card/Visit_from_the_Detective.hpp"

class Turn_hero : public Game_turn {

    public :

        bool phase(Game& gamestage) override ;
        void handle_turn(Game& gamestage) override ;
        void set_remain_actions(int remain_actions) ;
        int get_remain_actions() ;
    private :

        int remain_actions ;
};

#endif //TURN_HERO_HPP