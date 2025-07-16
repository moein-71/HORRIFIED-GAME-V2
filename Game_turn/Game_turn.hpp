#ifndef GAME_TURN_HPP
#define GAME_TURN_HPP

#include "../Game/Game.hpp"
#include "Hero_Action.hpp"
#include "../ACTION/ADVANCE/Advance.hpp"
#include "../ACTION/DEFEAT/Defeat.hpp"
#include "../ACTION/GUIDE/Guide.hpp"
#include "../ACTION/MOVE_HERO/Move_Hero.hpp"
#include "../ACTION/PICK_UP/Pick_Up.hpp"
#include "../ACTION/SPECIAL_ACTION/Special_Action.hpp"


class Game_turn {

    public :

        virtual ~Game_turn() = default ;
        virtual bool phase(Game& gamestage) = 0 ;
        virtual void handle_turn(Game& gamestage) = 0 ;

    private :

};

#endif //GAME_TURN__HPP