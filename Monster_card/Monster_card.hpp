#ifndef MONSTER_CARD_HPP
#define MONSTER_CARD_HPP

#include "Game.hpp"
#include "Archaologist.hpp"
#include "Mayor.hpp"

#include "Item.hpp"

#include "Map.hpp"

#include "Dracula.hpp"
#include "Invisible_man.hpp"

#include "Villager.hpp"

class Monster_card {

    public :

        virtual ~Monster_card() = default ;
        virtual void ability(Game& gamestage) = 0 ;
        virtual std::string info() const = 0 ;

    private :
};

#endif //MONSTER_CARD_HPP