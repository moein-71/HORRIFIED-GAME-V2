#include "Villager.hpp"
#include <iostream>

using namespace std;

Villager::Villager(string name, string safe_place, string now_place){

    set_name(name);
    set_safe_place(safe_place);
    set_now_place(now_place);
}



void Villager::set_name(string name){
    this -> name = name;
}
void Villager::set_safe_place(string safe_place){
    this -> safe_place = safe_place;
}
void Villager::set_now_place(string now_place){
    this -> now_place = now_place;
}



string Villager::get_name()const{
    return this -> name;
}
string Villager::get_safe_place()const{
    return this -> safe_place;
}
string Villager::get_now_place()const{
    return this -> now_place;
}



bool operator==(const Villager& lhs, const Villager& rhs){
    
    return lhs.get_name() == rhs.get_name() &&
           lhs.get_now_place() == rhs.get_now_place() &&
           lhs.get_safe_place() == rhs.get_safe_place();
}