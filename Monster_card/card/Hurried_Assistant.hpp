#ifndef HURRIED_ASSISTANT_HPP
#define HURRIED_ASSISTANT_HPP

#include "Monster_card.hpp"

class Hurried_assistant : public Monster_card {

    public :

        Hurried_assistant() ;
        void ability(Game& gamestage) override ;
        std::string info() const override ;

    private :
};

#endif //HURRIED_ASSISTANT_HPP