#ifndef HURRY_HPP
#define HURRY_HPP

#include "Perk_card.hpp"

class Hurry : public Perk_card {

    public :

        Hurry() ;
        void ability(Game& gamestage) override ;
        void info() const override ;

    private :
};

#endif //HURRY_HPP