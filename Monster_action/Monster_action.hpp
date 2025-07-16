#ifndef MONSTER_ACTION_HPP
#define MONSTER_ACTION_HPP

#include "Game.hpp"
#include "Archaologist.hpp"
#include "Mayor.hpp"

#include "Item.hpp"

#include "Dracula.hpp"
#include "Invisible_man.hpp"

#include "Villager.hpp"

#include "../Game_turn/Game_turn.hpp"
#include "../Game_turn/Turn_monster/Turn_monster.hpp"
#include "Turn_hero.hpp"
class Monster_action {

    public :

        virtual ~Monster_action() = default ;
        virtual bool activate(Game & game , const std::string & monster) = 0 ;  // pure 
        
    private :
} ;

#endif //MONSTER_ACTION_HPP
