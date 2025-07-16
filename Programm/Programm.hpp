#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "../Game/Game.hpp"
#include "Archaologist.hpp"
#include "Mayor.hpp"

#include "Item.hpp"

#include "Villager.hpp"

#include "../Game_turn/Game_turn.hpp"
#include "../Game_turn/Turn_monster/Turn_monster.hpp"
#include "Turn_hero.hpp"


#include <sstream>
#include <new>

class Program {
    
    public : 

        void Start() ;
        void Run() ;
        bool End() ; //if game has been end return true 

        void printLineDelay(const std::string& line, int delayMs = 0) ; //40
        void showWelcomeScreen() ;
        int CheckInputNumber() ;

    private : 

        std::string player_1 ;
        std::string player_2 ;
        Game base_game ;
} ;

#endif //PROGRAM_HPP