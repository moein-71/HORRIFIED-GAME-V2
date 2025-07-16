#include "Monster.hpp"
#include <iostream>
#include <ctime>


using namespace std;

Monster::Monster(int frenzy, string name, const string spawn_place): frenzy(frenzy),
 name(name), spawn_place(spawn_place) {
    set_now_place(spawn_place) ;
 }



int Monster::get_frenzy()const{
    return frenzy;
}
string Monster::get_name()const{
    return name;
}
string Monster::get_now_place(){
    if(now_place == "DEAD") {
        printLineDelay(this -> name + " is DEAD\n") ;
        return  "DEAD" ;
    }
    return now_place;
}
string Monster::get_spawn_place()const{
    return spawn_place;
}



void Monster::set_now_place(string new_place){
    if(now_place == "DEAD") {
        printLineDelay(this -> name + " is DEAD\n") ;
        return ;
    }
    this -> now_place = new_place;
}

void Monster::printLineDelay(const std::string& line, int delayMs) {
    for (char c : line) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
    cout << endl;
}
