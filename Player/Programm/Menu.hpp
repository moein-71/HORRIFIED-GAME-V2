#ifndef MENU_HPP
#define MENU_HPP
#include <bits/stdc++.h>
#include "raylib.h"
#include "State_enum.hpp"
#include "save.hpp"
#include "Game.hpp"
#include <memory>

class Menu{

    public:

        void Run(Program& , Game_State& , int , int);
        bool Draw_Right_Click_File(Rectangle, const char*, Color, Color, Color);
        bool Draw_Left_Click_File(Rectangle, const char*, Color, Color, Color);
        bool Draw_Left_Click(Rectangle, const char*, Color, Color, Color);
        bool Draw_ClickS_To_Save_File(Rectangle, const char*, Color, Color, Color);
        void Load_Screen(Program& , Game_State& , int screen_width , int screen_height);
        void Read_Save(Program& , std::string);
        void Set_Data_In_Game(Game_Save& , const std::string& , Program&) ;
        void Get_Data_In_Game(Game_Save& , const std::string& , Program&) ;
        void Func_Read_Data(Game_Save&, const std::string&);
        void Func_Write_Data(Game_Save&, const std::string&);
        void Draw_Option(bool);
        std::string Write_Info_Or_None(const std::string&);
        bool Is_File_Empty(const std::string&);
        std::string Get_Current_Time();
        void set_new_game(Program&) ;
};

#endif //MENU_HPP