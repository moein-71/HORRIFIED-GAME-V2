#ifndef ON_THE_MOVE_HPP
#define ON_THE_MOVE_HPP

#include "Monster_card.hpp"

class On_the_move : public Monster_card {

    public :

        void ability(Game& gamestage) override ;
        std::string info() const override ;

    private :
};

#endif //ON_THE_MOVE_HPP