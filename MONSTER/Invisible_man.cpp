#include "Invisible_man.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>

using namespace std;

Invisible_man::Invisible_man(): Monster(1, "Invisible_man", "Inn"){

    investigate["Inn"] = 1;
    investigate["Barn"] = 1;
    investigate["Institute"] = 1;
    investigate["Laboratory"] = 1;
    investigate["Mansion"] = 1;
};



unordered_map <string, bool> Invisible_man::get_investigate()const{
    return investigate;
}
bool Invisible_man::set_investigate_found(string place){

    if(investigate.count(place)){

        if(investigate[place]){
            
            investigate[place] = 0;
            return true;
        }

        return false;
    }

    else{

        throw invalid_argument("In this place there is no any Invisible_man item.");
    }
}
void Invisible_man::reset_near_villager(vector<string> villager_name){

    for(auto obj_villager : villager_name){

        if(near_villager.count(obj_villager)){

            near_villager[obj_villager] = 1;
        }
        else{

            near_villager[obj_villager] = 0;
        }
    }

    vector<string> to_remove;
    for(const auto& pair : near_villager){
        if(find(villager_name.begin(), villager_name.end(), pair.first) == villager_name.end()){
            to_remove.push_back(pair.first);
        }
    }
    
    for(const auto& key : to_remove){
        near_villager.erase(key);
    }
}
bool Invisible_man::can_kill_villager(string villager){
    return near_villager.count(villager) && near_villager[villager];
}
bool Invisible_man::check_investigate() {
    return !investigate["Inn"] && !investigate["Barn"] && !investigate["Institute"] && !investigate["Laboratory"] && !investigate["Mansion"] ;
}
