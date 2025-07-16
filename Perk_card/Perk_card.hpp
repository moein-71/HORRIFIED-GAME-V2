#ifndef PERK_CARD_HPP
#define PERK_CARD_HPP

#include "Game.hpp"
#include "Archaologist.hpp"
#include "Mayor.hpp"

#include "Item.hpp"

#include "Map.hpp"

#include "Dracula.hpp"
#include "Invisible_man.hpp"

#include "Villager.hpp"

class Perk_card {

    public :

        virtual ~Perk_card() = default ;
        virtual void ability(Game& gamestage) = 0 ;
        virtual void info() const = 0 ;
        void set_perk_name(std::string name) ;
        std::string get_perk_name() ;

    private :

        std::string perk_name ;
};

#endif //PERK_CARD_HPP