#ifndef HERO_ACTION_H
#define HERO_ACTION_H

#include "Game.hpp"
#include "Archaologist.hpp"
#include "Mayor.hpp"
#include "Hero.hpp"

#include "Item.hpp"

#include "Map.hpp"

#include "Dracula.hpp"
#include "Invisible_man.hpp"

#include "Villager.hpp"

#include "Perk_card.hpp"
#include "Break_of_Dawn.hpp"
#include "Hurry.hpp"
#include "Late_into_the_Night.hpp"
#include "Overstock.hpp"
#include "Repel.hpp"
#include "Visit_from_the_Detective.hpp"
#include <memory>

class Hero_Action{

    public:

        virtual ~Hero_Action() = default;

        virtual bool Activate(Game&) = 0;
        virtual std::string info()const = 0;
};

#endif//HERO_ACTION_H