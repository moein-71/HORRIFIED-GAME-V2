#include <cstdlib>
#include "Programm.hpp"
#include "Archaologist.hpp"
#include "Mayor.hpp"
#include "Courier.hpp"
#include "Scientist.hpp"
#include "State_enum.hpp"
#include "raylib.h"

#include "Item.hpp"

#include "Map.hpp"

#include "Dracula.hpp"
#include "Invisible_man.hpp"

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

using namespace std ;

Program::Program() {
    this -> base_game = make_shared<Game>() ;
    this -> current_screen = GAME_MENU ;
}

void Program::Start() {

    for(int i{} ; i < 12 ; ++i) {
        base_game->set_item_to_map(base_game->get_random_item()) ;
    }

    Texture2D img_start = LoadTexture("../Asset/Start.jpg") ;
    float img_start_height = ((this->screen_width * img_start.height) / img_start.width) ;
    Rectangle source = { 0, 0, float(img_start.width), float(img_start.height) };
    Rectangle dest = { 0, 0, this->screen_width , this->screen_height };  // x, y, width, height
    Vector2 origin = { 0, 0 } ;

    string player_1_Name = "" ;
    string player_1_garlic = "" ;
    bool player_1_name_Entered = false ;
    bool player_1_garlic_Entered = false ;

    Rectangle player_name_Box = {screen_width / 2 - screen_width / 6, screen_height / 2 , screen_width / 3 , 80} ;
    Rectangle garlic_Box = {screen_width / 2 - screen_width / 6, screen_height / 2 + 150 , screen_width / 3 , 80} ;

    bool player_Box = true ;

    while (this -> current_screen != GAME_MENU) {
        if(IsKeyPressed(KEY_ESCAPE)) {
            this -> current_screen = GAME_MENU ;
        }

        if (!player_1_name_Entered) {
            int key = GetCharPressed() ;
            while (key > 0) {
                if ((key > 32 && key <= 125) && player_1_Name.length() < 32) {
                    player_1_Name += (char)key ;
                }
                key = GetCharPressed() ;
            }

            if (IsKeyPressed(KEY_BACKSPACE) && !player_1_Name.empty()) {
                player_1_Name.pop_back() ;
            }

            if (IsKeyPressed(KEY_ENTER) && !player_1_Name.empty()) {
                player_1_name_Entered = true ;
                player_Box = false ;
            }
        } 
        else if (!player_1_garlic_Entered) {
            int key = GetCharPressed() ;
            while (key > 0) {
                if (isdigit(key) && player_1_garlic.length() < 6) {
                    player_1_garlic += (char)key ;
                }
                key = GetCharPressed() ;
            }

            if (IsKeyPressed(KEY_BACKSPACE) && !player_1_garlic.empty()) {
                player_1_garlic.pop_back() ;
            }

            if (IsKeyPressed(KEY_ENTER) && !player_1_garlic.empty()) {
                player_1_garlic_Entered = true ;
            }
        }
        BeginDrawing() ;
        DrawTexturePro(img_start , source , dest , origin , 0 ,  WHITE) ;
        ClearBackground(BLACK) ;
        DrawText("Player 1", player_name_Box.x / 2, player_name_Box.y / 4, 50, WHITE) ;
        DrawText("Enter your name (max 32 characters):", player_name_Box.x, player_name_Box.y - 40, 30, WHITE) ;
        DrawText("How many days ago you eat garlic :", garlic_Box.x, garlic_Box.y - 40, 30, WHITE) ;

        DrawRectangleRec(player_name_Box, player_Box ? BLUE : GRAY) ;
        DrawRectangleLinesEx(player_name_Box, 5, RED) ;

        DrawRectangleRec(garlic_Box, (!player_Box && !player_1_garlic_Entered) ? BLUE : GRAY) ;
        DrawRectangleLinesEx(garlic_Box, 5, RED) ;

        DrawText(player_1_Name.c_str(), player_name_Box.x + 10, player_name_Box.y + 25, 30, BLACK) ;
        DrawText(player_1_garlic.c_str(), garlic_Box.x + 10, garlic_Box.y + 25, 30, BLACK) ;

        if (player_1_name_Entered && player_1_garlic_Entered) {
            // this -> base_game->player_1.set_Player_name(player_1_Name) ;
            break ;
        }

        EndDrawing() ;
    }
    string player_2_Name = "" ;
    string player_2_garlic = "" ;
    bool player_2_name_Entered = false ;
    bool player_2_garlic_Entered = false ;

    player_Box = true ;  

    while (this -> current_screen != GAME_MENU) {
        if(IsKeyPressed(KEY_ESCAPE)) {
            this -> current_screen = GAME_MENU ;
        }
        if (!player_2_name_Entered) {
            int key = GetCharPressed() ;
            while (key > 0) {
                if ((key > 32 && key <= 125) && player_2_Name.length() < 32) {
                    player_2_Name += (char)key ;
                }
                key = GetCharPressed() ;
            }

            if (IsKeyPressed(KEY_BACKSPACE) && !player_2_Name.empty()) {
                player_2_Name.pop_back() ;
            }

            if (IsKeyPressed(KEY_ENTER) && !player_2_Name.empty()) {
                player_2_name_Entered = true ;
                player_Box = false ;
            }
        } 
        else if (!player_2_garlic_Entered) {
            int key = GetCharPressed() ;
            while (key > 0) {
                if (isdigit(key) && player_2_garlic.length() < 6) {
                    player_2_garlic += (char)key ;
                }
                key = GetCharPressed() ;
            }

            if (IsKeyPressed(KEY_BACKSPACE) && !player_2_garlic.empty()) {
                player_2_garlic.pop_back() ;
            }

            if (IsKeyPressed(KEY_ENTER) && !player_2_garlic.empty()) {
                player_2_garlic_Entered = true ;
            }
        }
        BeginDrawing() ;
        DrawTexturePro(img_start , source , dest , origin , 0 ,  WHITE) ;
        ClearBackground(BLACK) ;

        DrawText("Player 2", player_name_Box.x / 2, player_name_Box.y / 4, 50, WHITE) ;
        DrawText("Enter your name (max 32 characters):", player_name_Box.x, player_name_Box.y - 40, 30, WHITE) ;
        DrawText("How many days ago you eat garlic :", garlic_Box.x, garlic_Box.y - 40, 30, WHITE) ;

        DrawRectangleRec(player_name_Box, player_Box ? RED : GRAY) ;
        DrawRectangleLinesEx(player_name_Box, 5, BLUE) ;

        DrawRectangleRec(garlic_Box, (!player_Box && !player_2_garlic_Entered) ? RED : GRAY) ;
        DrawRectangleLinesEx(garlic_Box, 5, BLUE) ;

        DrawText(player_2_Name.c_str(), player_name_Box.x + 10, player_name_Box.y + 25, 30, BLACK) ;
        DrawText(player_2_garlic.c_str(), garlic_Box.x + 10, garlic_Box.y + 25, 30, BLACK) ;

        if (player_2_name_Entered && player_2_garlic_Entered) {
            // this -> base_game->player_2.set_Player_name(player_2_Name) ;
            break ;
        }

        EndDrawing() ;
    }
    if(player_1_garlic == "") {
        player_1_garlic = "0" ;
    }
    if(player_2_garlic == "") {
        player_2_garlic = "0" ;
    }

    if(stoi(player_1_garlic) > stoi(player_2_garlic)) {
        swap(player_1_Name , player_2_Name) ;
    }

    this -> base_game->player_1.set_Player_name(player_1_Name) ;
    this -> base_game->player_2.set_Player_name(player_2_Name) ;
    this -> player_1 = player_1_Name ;
    this -> player_2 = player_2_Name ;

    shared_ptr<Hero> mayor = make_shared<Mayor>();
    shared_ptr<Hero> archaologist = make_shared<Archaologist>() ;
    shared_ptr<Hero> courier = make_shared<Courier>() ;
    shared_ptr<Hero> scientist = make_shared<Scientist>() ;
    const int box_size = 250;
    const int distance_between = 100;

    vector<string> class_names = {mayor -> get_name(), archaologist -> get_name(), courier -> get_name(), scientist -> get_name()};
    // vector<string> class_names = {"../Asset/icon/mayor.png", "../Asset/icon/archaologist.png", "../Asset/icon/courier.png","../Asset/icon/scientist.png" };
    vector<Texture2D> class_texture = {LoadTexture("../Asset/icon/mayor.png") , LoadTexture("../Asset/icon/archaologist.png") , LoadTexture("../Asset/icon/courier.png") , LoadTexture("../Asset/icon/scientist.png")} ;
    
    vector<Rectangle> class_boxes;
    int selected_class = -1;

    float total_width = 2 * box_size + distance_between; // total space this boxes get
    float start_point_X = (screen_width - total_width) / 2;
    float start_point_Y = (screen_height - total_width) / 2 + 50; 

    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            Rectangle temp_box = {
                start_point_X + col * (box_size + distance_between),
                start_point_Y + row * (box_size + distance_between),
                (float)box_size,
                (float)box_size
            };
            class_boxes.push_back(temp_box);
        }
    }

    while (this -> current_screen != GAME_MENU) {

        if(IsKeyPressed(KEY_ESCAPE)) {
            this -> current_screen = GAME_MENU ;
        }
        Vector2 mouse = GetMousePosition();

        for (int i = 0; i < class_boxes.size(); i++) {
            if (CheckCollisionPointRec(mouse, class_boxes[i])) {
                selected_class = i;
                break ;
            }
            else {
                selected_class = -1 ;
            }
        }

        BeginDrawing();

        DrawTexturePro(img_start , source , dest , origin , 0 ,  WHITE) ;        
        ClearBackground(BLACK);

        DrawText(TextFormat(base_game->player_1.get_Player_name().c_str()) , start_point_X / 3, start_point_Y / 5, 60, BLUE) ;

        if (selected_class != -1) {//thanks form python because learn us %s in cpp , but i like f""
            DrawText(TextFormat("You want to selected: %s", class_names[selected_class].c_str()), start_point_X / 3, start_point_Y / 2, 40, WHITE);
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

                if(selected_class == 0) {
                    this -> base_game->set_player_1(mayor) ;
                    class_names[0] = "Selected" ;
                }
                else if(selected_class == 1) {
                    this -> base_game->set_player_1(archaologist) ;
                    class_names[1] = "Selected" ;
                }
                else if(selected_class == 2) {
                    this -> base_game->set_player_1(courier) ;
                    class_names[2] = "Selected" ;
                }
                else if(selected_class == 3) {
                    this -> base_game->set_player_1(scientist) ;
                    class_names[3] = "Selected" ;
                }
                this -> base_game->player_1.get_Player_Hero()->set_player_name(player_1) ;
                break ;
            }
        } else {
            DrawText("Select your role:", start_point_X / 3, start_point_Y / 2 , 40, GRAY);
        }


        for (int i = 0; i < class_boxes.size(); i++) {
            Color box_color = (selected_class == i) ? LIME : GRAY;
            DrawRectangleRec(class_boxes[i], box_color);
            DrawRectangleLinesEx(class_boxes[i], 3, DARKGRAY);

            int text_width = MeasureText(class_names[i].c_str(), 30);
            Rectangle source = { 0, 0, float(class_texture[i].width), float(class_texture[i].height) };
            Rectangle dest = { class_boxes[i].x, class_boxes[i].y, class_boxes[i].width  , class_boxes[i].height };  // x, y, width, height
            Vector2 origin = { 0, 0 } ;
            DrawTexturePro(class_texture[i] , source , dest , origin , 0 , WHITE) ;
            // DrawText(
            //     class_names[i].c_str(),
            //     class_boxes[i].x + (box_size - text_width) / 2,
            //     class_boxes[i].y + box_size / 2 - 15,
            //     30,
            //     WHITE
            // );
        }

        EndDrawing();
    }

    selected_class = -1;

    while (this -> current_screen != GAME_MENU) {
        if(IsKeyPressed(KEY_ESCAPE)) {
            this -> current_screen = GAME_MENU ;
        }
        Vector2 mouse = GetMousePosition();

        for (int i = 0; i < class_boxes.size(); i++) {
            if (CheckCollisionPointRec(mouse, class_boxes[i])) {
                selected_class = i;
                break ;
            }
            else {
                selected_class = -1 ;
            }
        }

        BeginDrawing();

        DrawTexturePro(img_start , source , dest , origin , 0 ,  WHITE) ;       
        ClearBackground(BLACK);

        DrawText(TextFormat(base_game->player_2.get_Player_name().c_str()) , start_point_X / 3, start_point_Y / 5, 60, RED) ;

        if (selected_class != -1) {
            DrawText(TextFormat("You want to selected: %s", class_names[selected_class].c_str()), start_point_X / 3, start_point_Y / 2, 40, WHITE);
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                if(class_names[selected_class] == "Selected") {
                    
                }
                else if(selected_class == 0) {
                    this -> base_game->set_player_2(mayor) ;
                    this -> base_game->player_2.get_Player_Hero()->set_player_name(player_2) ;
                    break ;
                }
                else if(selected_class == 1) {
                    this -> base_game->set_player_2(archaologist) ;
                    this -> base_game->player_2.get_Player_Hero()->set_player_name(player_2) ;
                    break ;
                }
                else if(selected_class == 2) {
                    this -> base_game->set_player_2(courier) ;
                    this -> base_game->player_2.get_Player_Hero()->set_player_name(player_2) ;
                    break ;
                }
                else if(selected_class == 3) {
                    this -> base_game->set_player_2(scientist) ;
                    this -> base_game->player_2.get_Player_Hero()->set_player_name(player_2) ;
                    break ;
                }
                
            }
        } else {
            DrawText("Select your role:", start_point_X / 3, start_point_Y / 2 , 40, GRAY);
        }

        for (int i = 0; i < class_boxes.size(); i++) {
            Color box_color = (selected_class == i) ? LIME : GRAY;
            DrawRectangleRec(class_boxes[i], box_color);
            DrawRectangleLinesEx(class_boxes[i], 3, DARKGRAY);

            if(class_names[i] == "Selected") continue; 
            int text_width = MeasureText(class_names[i].c_str(), 30);
            Rectangle source = { 0, 0, float(class_texture[i].width), float(class_texture[i].height) };
            Rectangle dest = { class_boxes[i].x, class_boxes[i].y, class_boxes[i].width  , class_boxes[i].height };  // x, y, width, height
            Vector2 origin = { 0, 0 } ;
            DrawTexturePro(class_texture[i] , source , dest , origin , 0 , WHITE) ;
            // DrawText(
            //     class_names[i].c_str(),
            //     class_boxes[i].x + (box_size - text_width) / 2,
            //     class_boxes[i].y + box_size / 2 - 15,
            //     30,
            //     WHITE
            // );
        }

        EndDrawing();
    }

    if(this->current_screen != GAME_MENU){
        base_game->player_1.get_Player_Hero()->set_perk(base_game->get_random_perk()) ;
        base_game->player_2.get_Player_Hero()->set_perk(base_game->get_random_perk()) ;
    }

    UnloadTexture(img_start) ;
    for(int i{} ; i < class_texture.size() ; ++i) {
        UnloadTexture(class_texture[i]) ;
    }

}

void Program::Run() {

    screen_width = GetScreenWidth() ;
    screen_height = GetScreenHeight() ;

    this -> base_game->Game_map.Print_Map_And_All_Info(this->base_game->player_1.get_Player_Hero()->get_now_place() , this->base_game->player_2.get_Player_Hero()->get_now_place()  , this->base_game->get_dracula_place() , this->base_game->get_invisible_man_place() , this->base_game->dracula.get_casket() , this->base_game->invisible_man.get_investigate() , base_game->get_Terror_level()) ;
    
    if(!this -> base_game->turn->phase(*this -> base_game)) {
        throw logic_error("somthing in phase goes wrong\n") ;
    }
    if(base_game->turn != base_game->monster_turn) {
        printLineDelay("MONSTER PHASE SKIPED\n" , 70) ;
        printLineDelay("Click to continue .......\n") ;
        cin.ignore() ;
        system("clear");
        return ;
    }
        
    if(!this -> base_game->turn->phase(*this -> base_game)) {
        throw logic_error("somthing in phase goes wrong\n") ;
    }

    cout<< "Click to continue .......\n" ;
    cin.ignore() ;
    cin.ignore() ;

}

bool Program::End() {
    if(base_game->get_monster_card_number() == 0) {
        printLineDelay("\n\nMONSTER SIDE WINS\n\n" , 100) ;
        return true ;
    }
    else if(base_game->get_Terror_level() == 5) {
        printLineDelay("\n\nMONSTER SIDE WINS\n\n" , 100) ;
        return true ;
    }
    else if(base_game->get_dracula_place() == "DEAD" && base_game->get_invisible_man_place() == "DEAD") {
        printLineDelay("\n\nHERO SIDE WINS\n\n" , 100) ;
        return true ;
    }
    else {
        return false ;
    }
}

void Program::printLineDelay(const string& line, int delayMs) {
    for (char c : line) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
    cout << endl;
}

int Program::CheckInputNumber() {
    int number;
    string input;

    while (true) {
        printLineDelay("Please enter a number: ");
        getline(cin, input);

        stringstream ss(input);

        if (ss >> number && ss.eof()) {
            return number ;
            break;
        } else {
            cout << "Invalid input. Please try again.\n";
        }
    }
}

void Program::set_current_screen(Game_State state) {
    this -> current_screen = state ;
}

Game_State & Program::get_current_screen() {
    return this -> current_screen ;
}

int Program::get_screen_width() {
    return this -> screen_width ;
}

int Program::get_screen_height() {
    return this -> screen_height ;
}

void Program::set_screen_width(int width) {
    this -> screen_width = width ;
}

void Program::set_screen_height(int height) {
    this -> screen_height = height ;
}

void Program::set_new_game() {
    this -> base_game.reset() ;
    this -> base_game = make_shared<Game>() ;
}