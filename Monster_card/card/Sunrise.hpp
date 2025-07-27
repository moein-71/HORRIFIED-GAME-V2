#ifndef SUNRiSE_HPP
#define SUNRiSE_HPP

#include "Monster_card.hpp"

class Sunrise : public Monster_card {

    public :

        Sunrise() ;
        void ability(Game& gamestage) override ;
        std::string info() const override ;

    private :
};

#endif //SUNRiSE_HPP