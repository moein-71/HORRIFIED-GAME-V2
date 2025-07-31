#ifndef VISIT_FROM_THE_DETECTIVE_HPP
#define VISIT_FROM_THE_DETECTIVE_HPP

#include "Perk_card.hpp"

class Visit_from_the_detective : public Perk_card {

    public :

        Visit_from_the_detective() ;
        void ability(Game& gamestage) override ;
        void info() const override ;

    private :
};

#endif //VISIT_FROM_THE_DETECTIVE_HPP