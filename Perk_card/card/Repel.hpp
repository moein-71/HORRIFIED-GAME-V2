#ifndef REPEL_HPP
#define REPEL_HPP

#include "Perk_card.hpp"

class Repel : public Perk_card {

    public :

        Repel() ;       
        void ability(Game& gamestage) override ;
        void info() const override ;

    private :
};

#endif //REPEL_HPP