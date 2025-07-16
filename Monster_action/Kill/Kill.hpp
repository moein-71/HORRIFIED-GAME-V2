#ifndef KILL_HPP
#define KILL_HPP

#include "Monster_action.hpp"

class Kill : public Monster_action {

    public :

        bool activate(Game & game , const std::string & monster) override ;   
        
    private :

} ;

#endif //KILL_HPP