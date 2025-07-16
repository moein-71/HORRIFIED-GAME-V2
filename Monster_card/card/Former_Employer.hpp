#ifndef FORMER_EMPLOYER_HPP
#define FORMER_EMPLOYER_HPP

#include "Monster_card.hpp"

class Former_employer : public Monster_card {

    public :

        void ability(Game& gamestage) override ;
        std::string info() const override ;

    private :
};

#endif //FORMER_EMPLOYER_HPP