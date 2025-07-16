#include "Perk_card.hpp"

using namespace std ;

void Perk_card::set_perk_name(std::string name) {
    this -> perk_name = name ; 
}

std::string Perk_card::get_perk_name() {
    return this -> perk_name ;
}
