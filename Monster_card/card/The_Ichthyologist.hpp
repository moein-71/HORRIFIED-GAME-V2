#ifndef THE_ICHTHYOLOGIST_HPP
#define THE_ICHTHYOLOGIST_HPP

#include "Monster_card.hpp"

class The_ichthyologist : public Monster_card {

    public :

        The_ichthyologist() ;
        void ability(Game& gamestage) override ;
        std::string info() const override ;

    private :
};

#endif //THE_ICHTHYOLOGIST_HPP