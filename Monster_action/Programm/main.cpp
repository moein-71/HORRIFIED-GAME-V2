#include "Programm.hpp"
#include <stdexcept>
#include "raylib.h"
#include "State_enum.hpp"
#include "Menu.hpp"

using namespace std ;

int main() {

    

    try{ // we need more
        Program p ;

        Menu menu ;


        SetConfigFlags(FLAG_FULLSCREEN_MODE) ;
        InitWindow(0 , 0 , "Main_Screen");
        SetExitKey(0);
        SetTargetFPS(60);
        p.set_screen_width(GetScreenWidth()) ;
        p.set_screen_height(GetScreenHeight()) ;
        
        // p.Start() ;

        bool do_save = false ;
        while (!p.End() && p.get_current_screen() != EXIT_GAME)
        {
            if(p.get_current_screen() == GAME_MENU) {
                if(!menu.Is_File_Empty("last_save.txt") && do_save == true) {
                    Game_Save save ;
                    menu.Get_Data_In_Game(save , "last_save.txt" , p) ;
                    menu.Func_Write_Data(save , "last_save.txt") ;
                }
                do_save = true ;
                menu.Run(p , p.get_current_screen() , p.get_screen_width() , p.get_screen_height()) ;
            }
            if(p.get_current_screen() == GAMEPLAY) {
                if(menu.Is_File_Empty("last_save.txt")) {
                    p.Start() ;
                    if(p.get_current_screen() == GAME_MENU) {
                        do_save = false ;
                        p.set_new_game() ;
                        continue;
                    }
                    Game_Save save ;
                    menu.Get_Data_In_Game(save , "last_save.txt" , p) ;
                    menu.Func_Write_Data(save , "last_save.txt") ;
                }
                
                p.Run() ;
                 int a ; 
                cout<< "\nenter if you want menu\n" ;
                cin>> a ;
                if(a == 1) {
                    p.set_current_screen(GAME_MENU) ;
                }
            }
        }
    }
    catch(bad_alloc & s) {
        cout<< "you have bad alloc\n" ;
    }
    catch(runtime_error & s) {
        cout<< s.what() << '\n' ;
    }
    catch(logic_error & s) {
        cout<< s.what() << '\n' ;
    }
    catch(exception & s) {
        cout<< s.what() << '\n' ;
    }

    return 0 ;
}
