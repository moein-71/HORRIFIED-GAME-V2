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

        void Run(std::shared_ptr<Game> , Game_State& , int , int);
        bool Draw_Right_Click_File(Rectangle, const char*, Color, Color, Color);
        bool Draw_Left_Click_File(Rectangle, const char*, Color, Color, Color);
        bool Draw_Left_Click(Rectangle, const char*, Color, Color, Color);
        bool Draw_ClickS_To_Save_File(Rectangle, const char*, Color, Color, Color);
        void Load_Screen(std::shared_ptr<Game> , Game_State& , int screen_width , int screen_height);
        void Read_Save(std::shared_ptr<Game> , std::string);
        void Set_Data_In_Game(Game_Save& , const std::string& , std::shared_ptr<Game>) ;
        void Get_Data_In_Game(Game_Save& , const std::string& , std::shared_ptr<Game>) ;
        void Func_Read_Data(Game_Save&, const std::string&);
        void Func_Write_Data(Game_Save&, const std::string&);
        void Draw_Option(bool);
        std::string Write_Info_Or_None(const std::string&);
        bool Is_File_Empty(const std::string&);
        std::string Get_Current_Time();
        void set_new_game(std::shared_ptr<Game>) ;
};

#endif //MENU_HPP