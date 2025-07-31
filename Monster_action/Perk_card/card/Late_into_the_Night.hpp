#ifndef LATE_INTO_THE_NIGHT_HPP
#define LATE_INTO_THE_NIGHT_HPP

#include "Perk_card.hpp"

class Late_into_the_night : public Perk_card {

    public :

        Late_into_the_night() ;
        void ability(Game& gamestage) override ;
        void info() const override ;

    private :
};

#endif //LATE_INTO_THE_NIGHT_HPP