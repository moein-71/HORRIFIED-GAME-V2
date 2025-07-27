#ifndef DRACULA_H
#define DRACULA_H

#include "Monster.hpp"
#include <string>
#include <unordered_map>

class Dracula: public Monster{

    public:

        Dracula();

        std::unordered_map<std::string, bool> get_casket()const;

        bool Destroy_Casket(std::string);//This function get place name and destroy the casket. if casket destroyed befor return false;
        bool Check_Casket_Destroyed_In_Place(std::string);//This function check this casket is destroyed or not 
        bool Check_Casket();//This function checks whether all coffins have been destroyed or not.
        std::array<std::pair<std::string , bool> , 4> get_casket_for_save() ;

    private:

        std::unordered_map<std::string, bool> casket;
};

#endif//DRACULA_H