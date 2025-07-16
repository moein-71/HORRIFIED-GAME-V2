#ifndef OVERSTOCK_HPP
#define OVERSTOCK_HPP

#include "Perk_card.hpp"

class Overstock : public Perk_card {

    public :

        Overstock() ;
        void ability(Game& gamestage) override ;
        void info() const override ;

    private :
};

#endif //OVERSTOCK_HPP