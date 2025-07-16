#ifndef FORM_OF_THE_BAT_HPP
#define FORM_OF_THE_BAT_HPP

#include "Monster_card.hpp"

class Form_of_The_bat : public Monster_card {

    public :

        void ability(Game& gamestage) override ;
        std::string info() const override ;

    private :
};

#endif //FORM_OF_THE_BAT_HPP