#include "Turn_hero.hpp"
#include "../Turn_monster/Turn_monster.hpp"
#include "Player.hpp"
using namespace std ;

bool Turn_hero::phase(Game& gamestage) {

    gamestage.player_turn->get_Player_Hero()->Print_Hero_Info() ;
    
    gamestage.set_last_hero_turn(gamestage.player_turn->get_Player_Hero()->get_name()) ;

    gamestage.turn->handle_turn(gamestage) ;
    shared_ptr<Hero_Action> action = nullptr ;
    
    if(gamestage.remain_actions == 0) {
        gamestage.remain_actions = gamestage.player_turn->get_Player_Hero()->get_action()  + gamestage.get_added_action() ;
    }
    
    char choose = 0 ;

    while(gamestage.remain_actions > 0) {
        gamestage.printLineDelay("Remain actions : " + to_string(gamestage.remain_actions) + '\n' + "1.Move  2.Guide  3.Pick up  4.Advance  5.Defeat  6.Special Action  7.Use perk  8.Status  9.Action_info  0.Skip\n" + "\nChoose your action : " );
        cin>> choose ;

        if(choose == '1') {
            action = make_shared<Move_Hero>() ;
            if(action -> Activate(gamestage)) {
                gamestage.remain_actions-- ;
                gamestage.printLineDelay("Move done\n") ;
                continue;
            }
            gamestage.printLineDelay( "Move not done\n") ;
        }
        else if(choose == '2') {
            action = make_shared<Guide>() ;
            if(action -> Activate(gamestage)) {
                gamestage.remain_actions-- ;
                gamestage.printLineDelay( "Guide done\n") ;
                continue;
            }
            gamestage.printLineDelay( "Guide not done\n") ;
        }
        else if(choose == '3') {
            action = make_shared<Pick_Up>() ;
            if(action -> Activate(gamestage)) {
                gamestage.remain_actions-- ;
                gamestage.printLineDelay( "Pick_Up done\n") ;
                continue;
            }
            gamestage.printLineDelay( "Pick_Up not done\n") ;
        }
        else if(choose == '4') {
            action = make_shared<Advance>() ;
            if(action -> Activate(gamestage)) {
                gamestage.remain_actions-- ;
                gamestage.printLineDelay( "Advance done\n") ;
                continue;
            }
            gamestage.printLineDelay( "Advance not done\n") ;
        }
        else if(choose == '5') {
            action = make_shared<Defeat>() ;
            if(action -> Activate(gamestage)) {
                gamestage.remain_actions-- ;
                gamestage.printLineDelay( "Defeat done\n") ;
                continue;
            }
            gamestage.printLineDelay( "Defeat not done\n") ;
        }
        else if(choose == '6') {
            action = make_shared<Special_Action>() ;
                if(action -> Activate(gamestage)) {
                gamestage.remain_actions-- ;
                gamestage.printLineDelay( "Special_Action done\n") ;
                continue;
            }
            gamestage.printLineDelay( "Special_Action not done\n") ;
        }
        else if(choose == '7') {
            auto perk_variant = gamestage.player_turn->get_Player_Hero()->get_perk();
            if (auto perk_ptr = std::get_if<std::shared_ptr<Perk_card>>(&perk_variant)) {
                (*perk_ptr)->ability(gamestage);
                gamestage.remain_actions +=  gamestage.get_added_action() ;
                continue;
            }
            else {
                gamestage.printLineDelay("There is no perk card use\n") ;
            }
        }
        else if(choose == '8') {
            gamestage.Game_map.Print_Map_And_All_Info(gamestage.get_player_1_place() , gamestage.get_player_2_place() , gamestage.get_dracula_place() , gamestage.get_invisible_man_place() , gamestage.dracula.get_casket() , gamestage.invisible_man.get_investigate() , gamestage.get_Terror_level()) ;
            gamestage.player_turn->get_Player_Hero()->Print_Hero_Info() ;
        }
        else if(choose == '9') {
            cout<< Move_Hero().info() << Guide().info() << Pick_Up().info() << Advance().info() << Defeat().info() << Special_Action().info() << '\n' ;
        }
        else if(choose == '0'){
            gamestage.remain_actions = 0 ;
            return true ;
        }
        else {
            gamestage.printLineDelay("\nChooss right number\n") ;
            continue;
        }
    }

    if(gamestage.remain_actions == 0) {
        return true ;
    }
    else {
        return false ;
    }
}

void Turn_hero::handle_turn(Game& gamestage) {

    gamestage.turn = gamestage.monster_turn ;
}
