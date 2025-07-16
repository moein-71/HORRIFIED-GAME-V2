#include "Player.hpp"
#include "Game_turn.hpp"
#include "Turn_monster.hpp"

using namespace std ;

void Player::set_Player_Hero(shared_ptr<Hero> input_hero) {
    this -> player_hero = input_hero ;
}

void Player::set_Player_name(string name) {
    this -> player_name = name ;
}

shared_ptr<Hero> Player::get_Player_Hero() {
    return this -> player_hero ;
}

string Player::get_Player_name() {
    return player_name ;
}

bool Player::operator==(const Player& other) {
    return this -> player_name == other.player_name && this -> player_hero->get_name() == other.player_hero->get_name() ;
}
