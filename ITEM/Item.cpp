#include "Item.hpp"
#include <iostream>

using namespace std;

Item::Item(string name, string spawn_place, string color, int strength){

    set_name(name);
    set_spawn_place(spawn_place);
    set_color(color);
    set_strength(strength);
}
Item::Item(int num){
    
    set_name("0");
    set_spawn_place("0");
    set_color("0");
    set_strength(0);
}



bool Item::operator==(const Item& other) const{
    
    return name == other.name && spawn_place == other.spawn_place &&
           color == other.color && strength == other.strength;
}



void Item::set_name(string name){
    this -> name = name;
}
void Item::set_spawn_place(string spawn_place){
    this -> spawn_place = spawn_place;
}
void Item::set_color(string color){
    this -> color = color;
}
void Item::set_strength(int strength){
    this -> strength = strength;
}



string Item::get_name()const{
    return this -> name;
}
string Item::get_spawn_place()const{
    return this -> spawn_place;
}
string Item::get_color()const{
    return this -> color;
}
int Item::get_strength()const{
    return this -> strength;
}