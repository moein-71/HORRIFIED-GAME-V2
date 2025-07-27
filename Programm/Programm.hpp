#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "../Game/Game.hpp"
#include "Archaologist.hpp"
#include "Mayor.hpp"
#include "State_enum.hpp"

#include "Item.hpp"

#include "Villager.hpp"

#include "../Game_turn/Game_turn.hpp"
#include "../Game_turn/Turn_monster/Turn_monster.hpp"
#include "Turn_hero.hpp"


#include <sstream>
#include <new>

class Program {
    
    public : 

        Program() ;
        void Start() ;
        void Run() ;
        bool End() ; //if game has been end return true 
        void Menu() ;
        void Draw_Option(bool draw) ;

        void printLineDelay(const std::string& line, int delayMs = 0) ; //40
        int CheckInputNumber() ;
        void set_current_screen(Game_State state) ;
        Game_State & get_current_screen() ;
        int get_screen_width() ;
        int get_screen_height() ;
        void set_screen_width(int ) ;
        void set_screen_height(int ) ;
        void set_new_game() ;

        std::shared_ptr<Game> get_game() ;

    private : 

        float screen_width ;
        float screen_height ;
        std::string player_1 ;
        std::string player_2 ;
        std::shared_ptr<Game> base_game ;
        Game_State current_screen ;
} ;

#endif //PROGRAM_HPP