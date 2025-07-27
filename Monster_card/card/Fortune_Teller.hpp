#ifndef FORTUNE_TELLER_HPP
#define FORTUNE_TELLER_HPP

#include "Monster_card.hpp"

class Fortune_teller : public Monster_card {

    public :

        Fortune_teller() ;
        void ability(Game& gamestage) override ;
        std::string info() const override ;

    private :
};

#endif //FORTUNE_TELLER_HPP