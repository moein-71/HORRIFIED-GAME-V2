#ifndef HYPNOTIC_GAZE_HPP
#define HYPNOTIC_GAZE_HPP

#include "Monster_card.hpp"

class Hypnotic_gaze : public Monster_card {

    public :

        void ability(Game& gamestage) override ;
        std::string info() const override ;

    private :
};

#endif //HYPNOTIC_GAZE_HPP