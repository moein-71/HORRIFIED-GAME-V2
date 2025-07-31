#ifndef EGYPTIAN_EXPERT_HPP
#define EGYPTIAN_EXPERT_HPP

#include "Monster_card.hpp"

class Egyptian_expert : public Monster_card {

    public :

        Egyptian_expert() ;
        void ability(Game& gamestage) override ;
        std::string info() const override ;

    private :
};

#endif //EGYPTIAN_EXPERT_HPP