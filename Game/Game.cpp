#include "Game.hpp"

#include "Archaologist.hpp"
#include "Mayor.hpp"

#include "Item.hpp"

#include "Villager.hpp"

#include "../Game_turn/Game_turn.hpp"
#include "../Game_turn/Turn_monster/Turn_monster.hpp"
#include "Turn_hero.hpp"

#include "Perk_card.hpp"
#include "Break_of_Dawn.hpp"
#include "Hurry.hpp"
#include "Late_into_the_Night.hpp"
#include "Overstock.hpp"
#include "Repel.hpp"
#include "Visit_from_the_Detective.hpp"
#include "Perk_empty.hpp"

#include "Egyptian_Expert.hpp"
#include "Former_Employer.hpp"
#include "Form_of_The_Bat.hpp"
#include "Fortune_Teller.hpp"
#include "Hurried_Assistant.hpp"
#include "Sunrise.hpp"
#include "The_Delivery.hpp"
#include "The_Ichthyologist.hpp"
#include "The_Innocent.hpp"
#include "Thief.hpp"
#include "Monster_card_empty.hpp"
#include "On_The_Move.hpp"
#include "Hypnotic_Gaze.hpp"

using namespace std ;

Game::Game() : player_turn(&player_1 ){

    this -> Terror_level = 0 ;
    this -> added_action = 0 ;
    this -> which_turn = 1 ;

    this -> hero_turn = make_shared<Turn_hero>() ;
    this -> turn = hero_turn ;
    this -> monster_turn = make_shared<Turn_monster>() ;

    this -> frenzy_monster = this -> dracula.get_name() ;

    this->set_frenzy_monster(this->get_dracula_name()) ;

    perk_bag.emplace_back(make_shared<Break_of_dawn>()) ;
    perk_bag.emplace_back(make_shared<Break_of_dawn>()) ;
    perk_bag.emplace_back(make_shared<Break_of_dawn>()) ;
    perk_bag.emplace_back(make_shared<Hurry>()) ;
    perk_bag.emplace_back(make_shared<Hurry>()) ;
    perk_bag.emplace_back(make_shared<Hurry>()) ;
    perk_bag.emplace_back(make_shared<Late_into_the_night>()) ;
    perk_bag.emplace_back(make_shared<Late_into_the_night>()) ;
    perk_bag.emplace_back(make_shared<Late_into_the_night>()) ;
    perk_bag.emplace_back(make_shared<Late_into_the_night>()) ;
    perk_bag.emplace_back(make_shared<Overstock>()) ;
    perk_bag.emplace_back(make_shared<Overstock>()) ;
    perk_bag.emplace_back(make_shared<Overstock>()) ;
    perk_bag.emplace_back(make_shared<Overstock>()) ;
    perk_bag.emplace_back(make_shared<Repel>()) ;
    perk_bag.emplace_back(make_shared<Repel>()) ;
    perk_bag.emplace_back(make_shared<Repel>()) ;
    perk_bag.emplace_back(make_shared<Visit_from_the_detective>()) ;
    perk_bag.emplace_back(make_shared<Visit_from_the_detective>()) ;
    perk_bag.emplace_back(make_shared<Visit_from_the_detective>()) ;

    Monster_cards_bag.emplace_back(make_shared<Egyptian_expert>()) ;
    Monster_cards_bag.emplace_back(make_shared<Form_of_The_bat>()) ;
    Monster_cards_bag.emplace_back(make_shared<Form_of_The_bat>()) ;
    Monster_cards_bag.emplace_back(make_shared<Form_of_The_bat>()) ;
    Monster_cards_bag.emplace_back(make_shared<Former_employer>()) ;
    Monster_cards_bag.emplace_back(make_shared<Fortune_teller>()) ;
    Monster_cards_bag.emplace_back(make_shared<Hurried_assistant>()) ;
    Monster_cards_bag.emplace_back(make_shared<Sunrise>()) ;
    Monster_cards_bag.emplace_back(make_shared<Sunrise>()) ;
    Monster_cards_bag.emplace_back(make_shared<Sunrise>()) ;
    Monster_cards_bag.emplace_back(make_shared<The_delivery>()) ;
    Monster_cards_bag.emplace_back(make_shared<The_ichthyologist>()) ;
    Monster_cards_bag.emplace_back(make_shared<The_innocent>()) ;
    Monster_cards_bag.emplace_back(make_shared<Thief>()) ;
    Monster_cards_bag.emplace_back(make_shared<Thief>()) ;
    Monster_cards_bag.emplace_back(make_shared<Thief>()) ;
    Monster_cards_bag.emplace_back(make_shared<Thief>()) ;
    Monster_cards_bag.emplace_back(make_shared<Thief>()) ;
    Monster_cards_bag.emplace_back(make_shared<On_the_move>()) ;
    Monster_cards_bag.emplace_back(make_shared<On_the_move>()) ;
    Monster_cards_bag.emplace_back(make_shared<Hypnotic_gaze>()) ;
    Monster_cards_bag.emplace_back(make_shared<Hypnotic_gaze>()) ;


    // string name, string safe_place, string now_place

    villagers_bag.emplace_back(Villager("Dr.Cranly" , "Precinct" , "")) ;
    villagers_bag.emplace_back(Villager("Dr.Read" , "Camp" , "")) ;
    villagers_bag.emplace_back(Villager("Prof.Pearson" , "Museum" , "")) ;
    villagers_bag.emplace_back(Villager("Maleva" , "Shop" , "")) ;
    villagers_bag.emplace_back(Villager("Fritz" , "Institute" , "")) ;
    villagers_bag.emplace_back(Villager("Wilbur_&_Chick" , "Dungeon" , "")) ;
    villagers_bag.emplace_back(Villager("Maria" , "Camp" , "")) ;

    // string name, string spawn_place, string color, int strength

    item_bag.emplace_back(Item("Flower" , "Docks" , "Yellow" , 2)) ;
    item_bag.emplace_back(Item("Tarot_Deck" , "Camp" , "Yellow" , 1)) ;
    item_bag.emplace_back(Item("Garlic" , "Inn" , "Yellow" , 2)) ;
    item_bag.emplace_back(Item("Mirrored_Box" , "Mansion" , "Yellow" , 3)) ;
    item_bag.emplace_back(Item("Stake" , "Abbey" , "Yellow" , 3)) ;
    item_bag.emplace_back(Item("Scroll_of_Thoth" , "Museum" , "Yellow" , 4)) ;
    item_bag.emplace_back(Item("Violin" , "Camp" , "Yellow" , 3)) ;
    item_bag.emplace_back(Item("Tablet" , "Museum" , "Yellow" , 3)) ;
    item_bag.emplace_back(Item("Wolfsbane" , "Camp" , "Yellow" , 4)) ;
    item_bag.emplace_back(Item("Charm" , "Camp" , "Yellow" , 4)) ;
    item_bag.emplace_back(Item("Dart" , "Inn" , "Red" , 2)) ;
    item_bag.emplace_back(Item("Fire_Poker" , "Mansion" , "Red" , 3)) ;
    item_bag.emplace_back(Item("Rapier" , "Theater" , "Red" , 5)) ;
    item_bag.emplace_back(Item("Shovel" , "Graveyard" , "Red" , 2)) ;
    item_bag.emplace_back(Item("Torch" , "Barn" , "Red" , 5)) ;
    item_bag.emplace_back(Item("Pitchfork" , "Barn" , "Red" , 4)) ;
    item_bag.emplace_back(Item("Rifle" , "Barn" , "Red" , 6)) ;
    item_bag.emplace_back(Item("Silver_Cane" , "Shop" , "Red" , 6)) ;
    item_bag.emplace_back(Item("Knife" , "Docks" , "Red" , 3)) ;
    item_bag.emplace_back(Item("Pistol" , "Precinct" , "Red" , 6)) ;
    item_bag.emplace_back(Item("Bear_Trap" , "Shop" , "Red" , 4)) ;
    item_bag.emplace_back(Item("Speargun" , "Institute" , "Red" , 4)) ;
    item_bag.emplace_back(Item("Anatomy_Text" , "Institute" , "Blue" , 1)) ;
    item_bag.emplace_back(Item("Centrifuge" , "Laboratory" , "Blue" , 1)) ;
    item_bag.emplace_back(Item("Kite" , "Tower" , "Blue" , 1)) ;
    item_bag.emplace_back(Item("Research" , "Tower" , "Blue" , 2)) ;
    item_bag.emplace_back(Item("Telescope" , "Mansion" , "Blue" , 2)) ;
    item_bag.emplace_back(Item("Searchlight" , " Precinct" , "Blue" , 2)) ;
    item_bag.emplace_back(Item("Experiment" , "Laboratory" , "Blue" , 2)) ;
    item_bag.emplace_back(Item("Analysis" , "Institute" , "Blue" , 2)) ;
    item_bag.emplace_back(Item("Rotenone" , "Institute" , "Blue" , 3)) ;
    item_bag.emplace_back(Item("Cosmic_Ray_Diffuser" , "Tower" , "Blue" , 3)) ;
    item_bag.emplace_back(Item("Monocane_Mixture" , "Inn" , "Blue" , 3)) ;
    item_bag.emplace_back(Item("Nebularium" , "Tower" , "Blue" , 3)) ;
    item_bag.emplace_back(Item("Fossil" , "Camp" , "Blue" , 3)) ;
    item_bag.emplace_back(Item("Flower" , "Docks" , "Yellow" , 2)) ;
    item_bag.emplace_back(Item("Tarot_Deck" , "Camp" , "Yellow" , 1)) ;
    item_bag.emplace_back(Item("Garlic" , "Inn" , "Yellow" , 2)) ;
    item_bag.emplace_back(Item("Mirrored_Box" , "Mansion" , "Yellow" , 3)) ;
    item_bag.emplace_back(Item("Stake" , "Abbey" , "Yellow" , 3)) ;
    item_bag.emplace_back(Item("Scroll_of_Thoth" , "Museum" , "Yellow" , 4)) ;
    item_bag.emplace_back(Item("Violin" , "Camp" , "Yellow" , 3)) ;
    item_bag.emplace_back(Item("Tablet" , "Museum" , "Yellow" , 3)) ;
    item_bag.emplace_back(Item("Wolfsbane" , "Camp" , "Yellow" , 4)) ;
    item_bag.emplace_back(Item("Charm" , "Camp" , "Yellow" , 4)) ;
    item_bag.emplace_back(Item("Dart" , "Inn" , "Red" , 2)) ;
    item_bag.emplace_back(Item("Fire_Poker" , "Mansion" , "Red" , 3)) ;
    item_bag.emplace_back(Item("Rapier" , "Theater" , "Red" , 5)) ;
    item_bag.emplace_back(Item("Shovel" , "Graveyard" , "Red" , 2)) ;
    item_bag.emplace_back(Item("Torch" , "Barn" , "Red" , 5)) ;
    item_bag.emplace_back(Item("Pitchfork" , "Barn" , "Red" , 4)) ;
    item_bag.emplace_back(Item("Rifle" , "Barn" , "Red" , 6)) ;
    item_bag.emplace_back(Item("Silver_Cane" , "Shop" , "Red" , 6)) ;
    item_bag.emplace_back(Item("Knife" , "Docks" , "Red" , 3)) ;
    item_bag.emplace_back(Item("Pistol" , "Precinct" , "Red" , 6)) ;
    item_bag.emplace_back(Item("Bear_Trap" , "Shop" , "Red" , 4)) ;
    item_bag.emplace_back(Item("Speargun" , "Institute" , "Red" , 4)) ;
    item_bag.emplace_back(Item("Anatomy_Text" , "Institute" , "Blue" , 1)) ;
    item_bag.emplace_back(Item("Centrifuge" , "Laboratory" , "Blue" , 1)) ;
    item_bag.emplace_back(Item("Kite" , "Tower" , "Blue" , 1)) ;
    item_bag.emplace_back(Item("Research" , "Tower" , "Blue" , 2)) ;
    item_bag.emplace_back(Item("Telescope" , "Mansion" , "Blue" , 2)) ;
    item_bag.emplace_back(Item("Searchlight" , " Precinct" , "Blue" , 2)) ;
    item_bag.emplace_back(Item("Experiment" , "Laboratory" , "Blue" , 2)) ;
    item_bag.emplace_back(Item("Analysis" , "Institute" , "Blue" , 2)) ;
    item_bag.emplace_back(Item("Rotenone" , "Institute" , "Blue" , 3)) ;
    item_bag.emplace_back(Item("Cosmic_Ray_Diffuser" , "Tower" , "Blue" , 3)) ;
    item_bag.emplace_back(Item("Monocane_Mixture" , "Inn" , "Blue" , 3)) ;
    item_bag.emplace_back(Item("Nebularium" , "Tower" , "Blue" , 3)) ;
    item_bag.emplace_back(Item("Fossil" , "Camp" , "Blue" , 3)) ;



}

void Game::set_player_1(shared_ptr<Hero> player_1_hero) {
    if(player_1_hero == nullptr) {
        throw bad_alloc() ;
    }
    this -> player_1.set_Player_Hero(player_1_hero) ;
    this -> player_turn = &(this -> player_1) ;
}

void Game::set_player_2(shared_ptr<Hero> player_2_hero) {
    if(player_2_hero == nullptr) {
        throw bad_alloc() ;
    }
    this -> player_2.set_Player_Hero(player_2_hero) ;
}


int Game::random_number() {
    
    random_device rd ;

    default_random_engine eng(rd()) ;

    uniform_int_distribution<int> random_number(1 , 100) ;

    return random_number(eng) ;
}

Item Game::get_random_item() {

    if(item_bag.empty()) {
        return Item("" , "" , "" , 0) ;
    }

    int number = (this->random_number() % this->item_bag.size()) ;

    Item random_item = item_bag[number] ;
    item_bag.erase(item_bag.begin() + number) ;
    item_bag.shrink_to_fit() ;

    return random_item ;
}

Item Game::get_item(string name) {

    for(int i{} ; i < this->item_bag.size() ; ++i) {

        if(name == item_bag[i].get_name()) {

            Item return_item = this->item_bag[i] ; 
            this->item_bag.erase(item_bag.begin() + i) ;
            this->item_bag.shrink_to_fit() ;
            return return_item ;
        }
    }
    return Item("" , "" , "" , 0) ;
}

void Game::set_item_bag(Item new_item) {

    item_bag.push_back(new_item) ;
}


void Game::set_item_to_map(Item new_item) {

    if(new_item.get_name() == "") {
        return ;
    }

    this->Game_map.set_item(new_item) ;
}

void Game::remove_not_exist_items_in_save(vector<string> exist_items) {
    vector<Item> now_items ;

    for(int i{} ; i < exist_items.size() ; ++i) {

        for(int j{} ; j < this->item_bag.size() ; ++j) {

            if(exist_items[i] == item_bag[j].get_name()) {

                now_items.push_back(item_bag[j]) ;
                item_bag.erase(item_bag.begin() + j) ;
            }
        }
    }

    this->item_bag = now_items ;
}

shared_ptr<Perk_card> Game::get_random_perk() {

    if(perk_bag.empty()) {
        return make_shared<Perk_empty>() ;
    }

    int number = (this->random_number() % this->perk_bag.size()) ;

    shared_ptr<Perk_card> random = perk_bag[number] ;
    perk_bag.erase(perk_bag.begin() + number) ;
    perk_bag.shrink_to_fit() ;

    if(random == nullptr) {
        throw runtime_error("in get_random_perk somthing goes wrong \n") ;
    }

    return random ;
}

std::shared_ptr<Perk_card> Game::get_perk(std::string name) {

    for(int i{} ; i < this->perk_bag.size() ; ++i) {

        if(name == this->perk_bag[i]->get_perk_name()) {

            shared_ptr<Perk_card> return_card = this->perk_bag[i] ;
            this->perk_bag.erase(this->perk_bag.begin() + i) ;
            this->perk_bag.shrink_to_fit() ;
            return return_card ;
        }
    }

    return nullptr ;
}

shared_ptr<Monster_card> Game::get_random_monster_card() {

    if(Monster_cards_bag.empty()) {
        return make_shared<Monster_card_empty>() ;
    }

    int number = (this->random_number() % this->Monster_cards_bag.size()) ;

    shared_ptr<Monster_card> random = Monster_cards_bag[number] ;
    Monster_cards_bag.erase(Monster_cards_bag.begin() + number) ;
    Monster_cards_bag.shrink_to_fit() ;

    if(random == nullptr) {
        throw runtime_error("in get_random_monster_card somthing goes wrong \n") ;
    }

    if(random == nullptr) {
        throw bad_alloc() ;
    }

    return random ;
}

Villager Game::get_villager(string name) {

    int counter = 0 ;
    for( Villager villager : villagers_bag) {
        if(villager.get_name() == name) {
            villagers_bag.erase( villagers_bag.begin() + counter) ;
            return villager ;
        }
        ++counter ;
    }

    return Villager("" , "" , "") ;
}

void Game::remove_not_exist_villagers_in_save(std::vector<std::string> exist_villagers) {

    vector<Villager> new_villagers ;

    for(int i{} ; i < exist_villagers.size() ; ++i) {

        for(int j{} ; j < this->villagers_bag.size() ; ++j) {

            if(exist_villagers[i] == this -> villagers_bag[j].get_name()) {
                new_villagers.push_back(villagers_bag[j]) ;
                // this->villagers_bag.erase(this->villagers_bag.begin() + j) ;
                // this->villagers_bag.shrink_to_fit() ;
            }
        }
    }

    this->villagers_bag = new_villagers ;
}

void Game::remove_not_exist_perk_cards_in_save(std::vector<std::string> exist_perks) {
    vector<shared_ptr<Perk_card>> new_perk_cards ;

    for(int i{} ; i < exist_perks.size() ; ++i) {

        for(int j{} ; j < this->perk_bag.size() ; ++j) {

            if(exist_perks[i] == this->perk_bag[j]->get_perk_name()) {
                new_perk_cards.push_back(this->perk_bag[j]) ;
                this->perk_bag.erase(this->perk_bag.begin() + j) ;
                this->perk_bag.shrink_to_fit() ;
            }
        }
    }

    this->perk_bag = new_perk_cards ;
    cout<< perk_bag.size() << "   " << exist_perks.size() <<"\n\n";
}

void Game::remove_not_exist_monster_cards_in_save(std::vector<std::string> exist_monster_card) {
    vector<shared_ptr<Monster_card>> new_monster_cards ;

    for(int i{} ; i < exist_monster_card.size() ; ++i) {

        for(int j{} ; j < this->Monster_cards_bag.size() ; ++j) {

            if(exist_monster_card[i] == this->Monster_cards_bag[j]->get_name()) {
                new_monster_cards.push_back(this->Monster_cards_bag[j]) ;
                this->Monster_cards_bag.erase(this->Monster_cards_bag.begin() + j) ;
                this->Monster_cards_bag.shrink_to_fit() ;
            }
        }
    }
    this->Monster_cards_bag = new_monster_cards ;
}


char Game::throw_dice() {

    array<char , 6> dice {'K' , 'Z' , 'Z' , 'Z' , 'Z' , 'P'} ;

    return dice[this->random_number() % 6] ;
}

std::string Game::find_place_with_more_item_map() {
    return this->Game_map.Find_Place_With_More_Item() ;
}

bool Game::remove_all_item_in_place(std::string place) {
    int j = 0 ;
    vector<pair<Item, int>> remove_item = this->Game_map.Remove_All_Item_In_Place(place) ;

    if(!remove_item.empty()) { 
        for(auto add : remove_item) {
            for(int i{} ; i < add.second ; ++i) {
                this -> set_item_bag(add.first) ;
                if(j==0) {
                    this->printLineDelay(add.first.get_spawn_place() + " be clear\n") ;
                    j++ ;
                }
            }
        }
        return true ;
    }
    else {
        printLineDelay("all place all clear") ;
        return false ;
    }
}

void Game::handle_turn() {
    this -> turn->handle_turn(*this) ;
}

void Game::print_map() {
    // this -> Game_map.print() ;
}

string Game::find_far_destination_monster_map(int move , std::string place , std::string archaeologist_place , std::string mayor_place) {
    return this -> Game_map.Move_Monster_Away_From_Hero(place , (this -> player_1.get_Player_Hero()) , (this -> player_2.get_Player_Hero())) ; //
}

std::string Game::find_far_destination_hero_map(int move , std::string place , std::string dracula_place , std::string Invisible_man_place) {
    return this -> Game_map.Move_Hero_Away_From_Monsters(place , this -> dracula.get_now_place() , this -> invisible_man.get_now_place() ,
    this -> player_1.get_Player_Hero()->get_now_place() == place ? player_2.get_Player_Hero()->get_now_place() : player_1.get_Player_Hero()->get_now_place()) ; //
}


void Game::set_invisible_man_place(const string place) {
    this->invisible_man.set_now_place(place) ;
}

void Game::set_dracula_place(const string place) {
    this->dracula.set_now_place(place) ;
}

void Game::set_last_hero_turn(const string & new_turn) {
    this -> last_hero_turn = new_turn ;
}

void Game::set_player_1_place(const string & place) {
    this->player_1.get_Player_Hero()->set_now_place(place) ;
}

void Game::set_player_2_place(const string & place) {
    this->player_2.get_Player_Hero()->set_now_place(place) ;
}

void Game::set_frenzy_monster( const string & name) {
    this->frenzy_monster = name ;
}

void Game::set_villager_in_Game_map(const std::string place , const std::string name) {
    int counter{} ;
    for( const Villager & temp : this->villagers_bag) {
        if(temp.get_name() == name) {
            this -> Game_map.set_villager(place , temp) ;
            this -> villagers_bag.erase(villagers_bag.begin() + counter) ;
            return ;
        }
        ++counter ;
    }
    if(this->Game_map.set_villager_place(this -> Game_map.get_villager_place(name) , place , name)) {
        return ;
    }
    else {
        printLineDelay( "\nsorry but this villager has been died\n") ;
    }
}        

void Game::set_added_action(const int & added_action) {
    this -> added_action = added_action ;
}

string Game::get_invisible_man_place() {
    return this->invisible_man.get_now_place() ;
}

string Game::get_dracula_place() {
    return this->dracula.get_now_place() ;
}


string Game::get_last_hero_turn() {
    return  last_hero_turn ;
}

string Game::get_player_1_place() {
    return player_1.get_Player_Hero()->get_now_place() ;
}

string Game::get_player_2_place() {
    return player_2.get_Player_Hero()->get_now_place() ;
}

string Game::get_player_1_hero_name() {
    return player_1.get_Player_Hero()->get_name() ;
}

string Game::get_player_2_hero_name() {
    return player_2.get_Player_Hero()->get_name() ;
}

string Game::get_frenzy_monster() {
    return this->frenzy_monster ;
}

string Game::get_dracula_name() {
    return this->dracula.get_name() ;
}

string Game::get_invisible_man_name() {
    return this->invisible_man.get_name() ;
}
int Game::get_added_action() {
    int temp = 0 ;
    swap(this -> added_action , temp) ;
    return temp ;
}

int Game::get_monster_card_number() {
    this->Monster_cards_bag.shrink_to_fit() ;
    return this->Monster_cards_bag.size() ;
}

bool Game::Check_Place_Exist_in_map(string place) {
    return this -> Game_map.Check_Place_Exist(place) ;
}

void Game::increase_Terror_level() {
    this -> Terror_level++ ;
}

int Game::get_Terror_level() {
    return this -> Terror_level ;
}

std::string Game::move_character_near_dracula(std::string dracula_place) {
    return this -> Game_map.Move_Character_Near_Dracula(dracula_place , this -> player_1.get_Player_Hero() , this -> player_2.get_Player_Hero()) ;
}

void Game::move_villager_to_safe_place() {
    this->Game_map.Move_Villager_To_Safe_House() ;
}

void Game::printLineDelay(const std::string& line, int delayMs) {
    for (char c : line) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
    cout << endl;
}



