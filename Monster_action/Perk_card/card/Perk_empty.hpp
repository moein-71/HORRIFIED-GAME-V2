#ifndef PERK_EMPTY_HPP
#define PERK_EMPTY_HPP

#include "Perk_card.hpp"

class Perk_empty : public Perk_card {

    public :

        Perk_empty() ;       
        void ability(Game& gamestage) override ;
        void info() const override ;

    private :
};

#endif //PERK_EMPTY_HPP