#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Archaologist.hpp"
#include "Mayor.hpp"
#include "Courier.hpp"
#include "../HERO/Hero.hpp"
#include <memory>

class Game_turn ;

class Player {

    public :

        void set_Player_Hero(std::shared_ptr<Hero> input_hero) ;
        void set_Player_name(std::string name) ;
        std::shared_ptr<Hero> get_Player_Hero() ;
        std::string get_Player_name() ;
        bool operator==(const Player& other) ;

    private :

        std::string player_name ;
        std::shared_ptr<Hero> player_hero = nullptr ;
} ;


#endif //PLAYER_HPP