#ifndef BREAK_OF_DAWN_HPP
#define BREAK_OF_DAWN_HPP

#include "Perk_card.hpp"

class Break_of_dawn : public Perk_card {

    public :

        Break_of_dawn() ;
        void ability(Game& gamestage) override ;
        void info() const override ;

    private :
};

#endif //BREAK_OF_DAWN_HPP