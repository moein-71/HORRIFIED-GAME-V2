#include "Menu.hpp"
#include "Archaologist.hpp"
#include "Mayor.hpp"
#include "Courier.hpp"
#include "Scientist.hpp"
#include "Perk_card.hpp"
#include "Monster_card.hpp"
#include "Item.hpp"

using namespace std;

void Menu::Run(shared_ptr<Game> game , Game_State& current_screen , int screen_width , int screen_height){

    while(current_screen == GAME_MENU){

        BeginDrawing();
        ClearBackground(BLACK);

        Draw_Option(false);

        float btn_width = 410;
        float btn_height = 100;
        float btn_X = (screen_width - btn_width) / 2 + 10;
        float start_Y = screen_height * 0.8f;

        Rectangle btn_continue = {btn_X, start_Y - 180, btn_width, btn_height };
        Rectangle btn_load     = {btn_X, start_Y - 60, btn_width, btn_height };
        Rectangle btn_exit     = {btn_X, start_Y + 60, btn_width, btn_height };

        if(Draw_Left_Click(btn_continue, "Start", DARKGRAY, GRAY, WHITE)){
           //reading game 
           if(this->Is_File_Empty("last_save.txt")) {
                this->set_new_game(game) ;
           }
           else {
                this->set_new_game(game) ;
                Game_Save save ;
                this->Func_Read_Data(save , "last_save.txt") ;
                this->Set_Data_In_Game(save , "last_save.txt" , game) ;
           }
            current_screen = GAMEPLAY;
        }

        if(Draw_Left_Click(btn_load, "Load", DARKGRAY, GRAY, WHITE)){

            for (int i = 0; i < 1; i++) {
                BeginDrawing();
                ClearBackground(BLACK);
                EndDrawing();
            }

            current_screen = SAVE_LOAD_GAME;
            Load_Screen(game , current_screen , screen_width , screen_height);
        }

        if(Draw_Left_Click(btn_exit, "Exit", DARKGRAY, GRAY, WHITE)){

            current_screen = EXIT_GAME;
        }

        EndDrawing();
    }
    return;
}


void Menu::Load_Screen(shared_ptr<Game> game , Game_State& current_screen , int screen_width , int screen_height){

    while(current_screen != GAME_MENU){

        BeginDrawing();
        ClearBackground(BLACK);
        Draw_Option(true);

        float btn_width = 410;
        float btn_height = 100;
        float btn_X = (screen_width - btn_width) / 2 + 10;
        float start_Y = screen_height * 0.8f;

        Rectangle btn_file1 = {btn_X, start_Y - 180, btn_width, btn_height };
        Rectangle btn_file2     = {btn_X, start_Y - 60, btn_width, btn_height };
        Rectangle btn_exit     = {btn_X, start_Y + 60, btn_width, btn_height };

        /////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////

        if(Draw_Right_Click_File(btn_file1, "F1.txt", DARKGRAY, GRAY, WHITE)){
           
            fstream clear("F1.txt", ios::out);
            clear.close();
        }
        if(Draw_Right_Click_File(btn_file2, "F2.txt", DARKGRAY, GRAY, WHITE)){
             
            fstream clear("F2.txt", ios::out);
            clear.close();
        }

        /////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////
        if(Draw_ClickS_To_Save_File(btn_file1, "F1.txt", DARKGRAY, GRAY, WHITE)){
           
            if(!this->Is_File_Empty("last_save.txt")) {
                this->set_new_game(game) ;
                Game_Save game_save;
                // this->Get_Data_In_Game(game_save , "last_save.txt" , game) ;
                Func_Read_Data(game_save, "last_save.txt");
                game_save.time_save = Get_Current_Time();
                game_save.file_name = "F1.txt" ;
                Func_Write_Data(game_save, "F1.txt");
            }
        }
        if(Draw_ClickS_To_Save_File(btn_file2, "F2.txt", DARKGRAY, GRAY, WHITE)){
           
            if(!this->Is_File_Empty("last_save.txt")) {
                this->set_new_game(game) ;
                Game_Save game_save;
                // this->Get_Data_In_Game(game_save , "last_save.txt" , game) ;
                Func_Read_Data(game_save, "last_save.txt");
                game_save.time_save = Get_Current_Time();
                game_save.file_name = "F2.txt" ;
                Func_Write_Data(game_save, "F2.txt");
            }
        }
        /////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////
        if(Draw_Left_Click_File(btn_file1, "F1.txt", DARKGRAY, GRAY, WHITE)){
            if(!this -> Is_File_Empty("F1.txt")) {
                this->set_new_game(game) ;
                Read_Save(game , "F1.txt");
                current_screen = GAME_MENU;
            }
        }

        if(Draw_Left_Click_File(btn_file2, "F2.txt", DARKGRAY, GRAY, WHITE)){
            if(!this -> Is_File_Empty("F2.txt")) {
                this->set_new_game(game) ;
                Read_Save(game , "F2.txt");
                current_screen = GAME_MENU;
            }
        }

        if(Draw_Left_Click(btn_exit, "Back", DARKGRAY, GRAY, WHITE)){

            current_screen = GAME_MENU;
        }
        /////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////
        if(IsKeyDown(KEY_N)){
            this->set_new_game(game) ;
            fstream clear("last_save.txt", ios::out);
            clear.close(); 
            current_screen = GAME_MENU;
        }
        EndDrawing();
    }
    return;
}

void Menu::Read_Save(shared_ptr<Game> game , string file_save_name){

    Game_Save game_save;
    game_save.file_name = file_save_name;
    Func_Read_Data(game_save, file_save_name);
    Func_Write_Data(game_save, "last_save.txt");
}

void Menu::Set_Data_In_Game(Game_Save& game_save, const std::string& filename, shared_ptr<Game> game) {
    
    game->Terror_level = stoi(game_save.Terror_level) ;
    game->which_turn = stoi(game_save.which_turn) ;
    game->remain_actions = stoi(game_save.remain_actions) ;

    game->set_dracula_place(game_save.dracula_place) ;
    for(int i{} ; i < game_save.dracula_casket.size() ; ++i) { // dracula caskets
        if(game_save.dracula_casket[i].second == false) {
            game->dracula.Destroy_Casket(game_save.dracula_casket[i].first) ;
        }
    }

    game->set_invisible_man_place(game_save.invisible_man_place) ;
    for(int i{} ; i < game_save.invisible_man_investigate.size() ; ++i) { // investigates
        if(game_save.invisible_man_investigate[i].second == false) {
            game->invisible_man.set_investigate_found(game_save.invisible_man_investigate[i].first) ;
        }
    }
    game->frenzy_monster = game_save.frenzy_monster ;

    shared_ptr<Hero> mayor = make_shared<Mayor>();
    shared_ptr<Hero> archaologist = make_shared<Archaologist>() ;
    shared_ptr<Hero> courier = make_shared<Courier>() ;
    shared_ptr<Hero> scientist = make_shared<Scientist>() ;

    //player 1 

    if(game_save.player_1_hero == mayor->get_name()) {
        game->player_1.set_Player_Hero(mayor) ;
    }

    if(game_save.player_1_hero == archaologist->get_name()) {
        game->player_1.set_Player_Hero(archaologist) ;
    }

    if(game_save.player_1_hero == courier->get_name()) {
        game->player_1.set_Player_Hero(courier) ;
    }

    if(game_save.player_1_hero == scientist->get_name()) {
        game->player_1.set_Player_Hero(scientist) ;
    }

    game->player_1.set_Player_name(game_save.player_1_name) ;
    game->player_1.get_Player_Hero()->set_player_name(game_save.player_1_name) ;
    game->player_1.get_Player_Hero()->set_now_place(game_save.player_1_place) ;

    for(int i{} ; i < game_save.player_1_items.size() ; ++i) { // setting item for player 1
        for(int j{} ; j < game_save.player_1_items[i].second ; ++j) {
                game->player_1.get_Player_Hero()->set_item(game->get_item(game_save.player_1_items[i].first)) ;
        }
    }

    for(int i{} ; i < game_save.player_1_perk_card.size() ; ++i) { // setting perk for player 1
        game->player_1.get_Player_Hero()->set_perk(game->get_perk(game_save.player_1_perk_card[i])) ;
    }

    //player 2

    if(game_save.player_2_hero == mayor->get_name()) {
        game->player_2.set_Player_Hero(mayor) ;
    }

    if(game_save.player_2_hero == archaologist->get_name()) {
        game->player_2.set_Player_Hero(archaologist) ;
    }

    if(game_save.player_2_hero == courier->get_name()) {
        game->player_2.set_Player_Hero(courier) ;
    }

    if(game_save.player_2_hero == scientist->get_name()) {
        game->player_2.set_Player_Hero(scientist) ;
    }

    game->player_2.set_Player_name(game_save.player_2_name) ;
    game->player_2.get_Player_Hero()->set_player_name(game_save.player_2_name) ;
    game->player_2.get_Player_Hero()->set_now_place(game_save.player_2_place) ;

    for(int i{} ; i < game_save.player_2_items.size() ; ++i) { // setting item for player 2
        for(int j{} ; j < game_save.player_2_items[i].second ; ++j) {
                game->player_2.get_Player_Hero()->set_item(game->get_item(game_save.player_2_items[i].first)) ;
        }
    }

    for(int i{} ; i < game_save.player_2_perk_card.size() ; ++i) { // setting perk for player 2
        game->player_2.get_Player_Hero()->set_perk(game->get_perk(game_save.player_2_perk_card[i])) ;
    }

    // setting items in map first 
    for(int i{} ; i < game_save.item_in_map.size() ; ++i) {
        for(int j{} ; j < game_save.item_in_map[i].second ; ++j) {
            game->set_item_to_map(game->get_item(game_save.item_in_map[i].first)) ;
        }
    }
    // setting item in bag 
    game->remove_not_exist_items_in_save(game_save.item_in_bag) ;

    // setting villagers in map first 
    for(int i{} ; i < game_save.villager_in_map.size() ; ++i) {

        game->Game_map.set_villager(game_save.villager_in_map[i].second , game->get_villager(game_save.villager_in_map[i].first)) ;
    }

    // setting villagers in game bag
    game->remove_not_exist_villagers_in_save(game_save.villager_in_bag) ;

    // setting perk cards 
    game->remove_not_exist_perk_cards_in_save(game_save.perk_card_remain_in_bag) ;

    // setting monster cards 
    game->remove_not_exist_monster_cards_in_save(game_save.monster_card_remain_in_bag) ;


}

void Menu::Get_Data_In_Game(Game_Save& game_save, const std::string& filename, shared_ptr<Game> game) {
    game_save.file_name = filename ;
    game_save.time_save = this -> Get_Current_Time() ;

    game_save.Terror_level = to_string(game->Terror_level) ;
    game_save.which_turn = to_string(game->which_turn) ;
    game_save.remain_actions = to_string(game->remain_actions) ;

    game_save.dracula_place = game->get_dracula_place() ;

    game_save.dracula_casket = game->dracula.get_casket_for_save() ;

    game_save.invisible_man_place = game->get_invisible_man_place() ;
    game_save.invisible_man_investigate = game->invisible_man.get_investigate_for_save() ;

    game_save.frenzy_monster = game->frenzy_monster ;

    game_save.player_1_hero = game->player_1.get_Player_Hero()->get_name() ;
    game_save.player_1_name = game->player_1.get_Player_Hero()->get_player_name() ;
    game_save.player_1_place = game->player_1.get_Player_Hero()->get_now_place() ;

    game_save.player_1_items = game->player_1.get_Player_Hero() -> get_items_for_save() ;
    game_save.player_1_perk_card = game->player_1.get_Player_Hero() -> get_perk_for_save() ;

    game_save.player_2_hero = game->player_2.get_Player_Hero()->get_name() ;
    game_save.player_2_name = game->player_2.get_Player_Hero()->get_player_name() ;
    game_save.player_2_place = game->player_2.get_Player_Hero()->get_now_place() ;

    game_save.player_2_items = game->player_2.get_Player_Hero() -> get_items_for_save() ;
    game_save.player_2_perk_card = game->player_2.get_Player_Hero() -> get_perk_for_save() ;

    for(int i{} ; i < game->item_bag.size() ; ++i) {
        game_save.item_in_bag.push_back(game->item_bag[i].get_name()) ;
    }

    game_save.item_in_map = game->Game_map.get_all_items() ;

    for(int i{} ; i < game->villagers_bag.size() ; ++i) {
        game_save.villager_in_bag.push_back(game->villagers_bag[i].get_name()) ;
    }

    game_save.villager_in_map = game->Game_map.get_all_villager_for_save() ;

    for(int i{} ; i < game->perk_bag.size() ; ++i) {
        game_save.perk_card_remain_in_bag.push_back(game->perk_bag[i]->get_perk_name()) ;
        cout<< "\n\n" << game->perk_bag[i]->get_perk_name() << "\n\n" ;
    }

    for(int i{} ; i < game->Monster_cards_bag.size() ; ++i) {
        game_save.monster_card_remain_in_bag.push_back(game->Monster_cards_bag[i]->get_name()) ;
    }
}

void Menu::Func_Read_Data(Game_Save& game_save, const string& filename){

    if(this->Is_File_Empty(filename)) {
        return ;
    }

    fstream read(filename, ios::in);
    // read >> game_save.x >> game_save.y >> game_save.file_name >> game_save.time_save;
    read >> game_save.file_name >> game_save.time_save >> game_save.Terror_level >> game_save.which_turn >> game_save.remain_actions >> game_save.dracula_place ;
    
    string start ;
    read >> start ;
    if(start != "$") {
        throw invalid_argument("in reading in Func_read_data somthing readed wrong") ;
    }
    start = "" ;

    int counter = 0 ;
    string place , F_or_T ;
    while(read >> place) { //getting dracula casket 
        if(place == "$") {
            break ;
        }
        read >> F_or_T ;
        game_save.dracula_casket[counter].first = place ;
        game_save.dracula_casket[counter].second = F_or_T == "T" ? true : false ;
        counter++ ;
    }
    

    read >> game_save.invisible_man_place ;

    read >> start ;
    if(start != "$") {
        throw invalid_argument("in reading in Func_read_data somthing readed wrong") ;
    }
    start = "" ;

    place = "" ; F_or_T = "" ; counter = 0 ;
    while(read >> place) { // getting investigates 
        if(place == "$") {
            break ;
        }
        read >> F_or_T ;
        game_save.invisible_man_investigate[counter].first = place ;
        game_save.invisible_man_investigate[counter].second = F_or_T == "T" ? true : false ;
        counter++ ;
    }

    read >> game_save.frenzy_monster >> game_save.player_1_hero >> game_save.player_1_name >> game_save.player_1_place ;
    
    read >> start ;
    if(start != "$") {
        throw invalid_argument("in reading in Func_read_data somthing readed wrong") ;
    }
    start = "" ;

    string name , amount ;
    while(read >> name) { // getting item for player 1
        if(name == "$") {
            break ;
        }
        read >> amount ;
        game_save.player_1_items.push_back({name , stoi(amount)}) ;
    }

    read >> start ;
    if(start != "$") {
        throw invalid_argument("in reading in Func_read_data somthing readed wrong") ;
    }
    start = "" ;

    name = "" ;
    while(read >> name) { // getting perk for player 1
        if(name == "$") {
            break ;
        }
        game_save.player_1_perk_card.push_back(name) ;
    }    

    read >> game_save.player_2_hero >> game_save.player_2_name >> game_save.player_2_place ;
    
    read >> start ;
    if(start != "$") {
        throw invalid_argument("in reading in Func_read_data somthing readed wrong") ;
    }
    start = "" ;

    name = "" ; amount = "" ;
    while(read >> name) { // getting item for player 2
        if(name == "$") {
            break ;
        }
        read >> amount ;
        game_save.player_2_items.push_back({name , stoi(amount)}) ;
    }

    read >> start ;
    if(start != "$") {
        throw invalid_argument("in reading in Func_read_data somthing readed wrong") ;
    }
    start = "" ;

    name = "" ;
    while(read >> name) { // getting perk for player 2
        if(name == "$") {
            break ;
        }
        game_save.player_2_perk_card.push_back(name) ;
    }    

    read >> start ;
    if(start != "#") { 
        throw invalid_argument("in reading in Func_read_data somthing readed wrong") ;
    }
    start = "" ;

    name = "" ;
    while(read >> name) { // getting item in bag
        if(name == "#") {
            break ;
        }
        game_save.item_in_bag.push_back(name) ;
    }

    read >> start ;
    if(start != "#") { 
        throw invalid_argument("in reading in Func_read_data somthing readed wrong") ;
    }
    start = "" ;

    name = "" ; amount = "" ;
    while (read >> name) { // getting item in map
        if(name == "#") {
            break ;
        }
        read >> amount ; 
        game_save.item_in_map.push_back({name , stoi(amount)}) ;
    }

    read >> start ;
    if(start != "#") { 
        throw invalid_argument("in reading in Func_read_data somthing readed wrong") ;
    }
    start = "" ;

    name = "" ;
    while(read >> name) { // getting villagers in bag
        if(name == "#") {
            break ;
        }
        game_save.villager_in_bag.push_back(name) ;
    }

    read >> start ;
    if(start != "#") { 
        throw invalid_argument("in reading in Func_read_data somthing readed wrong") ;
    }
    start = "" ;

    name = "" ; place = "" ;
    while(read >> name) { // getting villager in map
        if(name == "#") { 
            break ;
        }
        read >> place ;
        game_save.villager_in_map.push_back({name , place}) ;
    }

    read >> start ;
    if(start != "#") { 
        throw invalid_argument("in reading in Func_read_data somthing readed wrong") ;
    }
    start = "" ;

    name = "" ;
    while(read >> name) { // getting perk card remains
        if(name == "#") { 
            break ;
        }
        game_save.perk_card_remain_in_bag.push_back(name) ;
    }

    read >> start ;
    if(start != "#") { 
        throw invalid_argument("in reading in Func_read_data somthing readed wrong") ;
    }
    start = "" ;

    name = "" ;
    while(read >> name) { // getting monster card remains
        if(name == "#") { 
            break ;
        }
        game_save.monster_card_remain_in_bag.push_back(name) ;
    }

    read.close();
}

void Menu::Func_Write_Data(Game_Save& game_save, const string& filename){
    
    fstream write(filename, ios::out);
    // write << game_save.x << ' ' << game_save.y << ' ' << game_save.file_name << ' ' << game_save.time_save;
    write << game_save.file_name << ' ' << game_save.time_save << ' ' << game_save.Terror_level << ' ' << game_save.which_turn << ' ' << game_save.remain_actions  << ' ' << 
        game_save.dracula_place  << " $ " ;
    for(int i{} ; i < game_save.dracula_casket.size() ; ++i) { //adding caskets 
        char F_or_T = game_save.dracula_casket[i].second == true ? 'T' : 'F' ;
        write << game_save.dracula_casket[i].first << ' ' << F_or_T << ' ' ;
    }

    write << "$ " << game_save.invisible_man_place << " $ " ;
     for(int i{} ; i < game_save.invisible_man_investigate.size() ; ++i) { //adding investigate
        char F_or_T = game_save.invisible_man_investigate[i].second == true ? 'T' : 'F' ;
        write << game_save.invisible_man_investigate[i].first << ' ' << F_or_T << ' ' ;
    }

    write << "$ " << game_save.frenzy_monster << ' ' << game_save.player_1_hero << ' ' << game_save.player_1_name << ' ' << game_save.player_1_place << " $ " ;
    for(int i{} ; i < game_save.player_1_items.size() ; ++i) { //adding items of player 1
        string amount = to_string(game_save.player_1_items[i].second) ;
        write << game_save.player_1_items[i].first << ' ' << amount << ' ' ;
    }

    write << "$ " << "$ " ;
    for(int i{} ; i < game_save.player_1_perk_card.size() ; ++i) { //adding perks of player 1 
        write << game_save.player_1_perk_card[i] << ' '  ;
    }

    write << "$ " << game_save.player_2_hero << ' ' << game_save.player_2_name << ' ' << game_save.player_2_place << " $ " ;
    for(int i{} ; i < game_save.player_2_items.size() ; ++i) { //adding items of player 2
        string amount = to_string(game_save.player_2_items[i].second) ;
        write << game_save.player_2_items[i].first << ' ' << amount << ' ' ;
    }

    write << "$ " << "$ " ;
    for(int i{} ; i < game_save.player_2_perk_card.size() ; ++i) { //adding perks of player 2 
        write << game_save.player_2_perk_card[i] << ' '  ;
    }
    write << "$ " ;

    write << "# " ; 
    for(int i{} ; i < game_save.item_in_bag.size() ; ++i) { // adding items in bag
        write << game_save.item_in_bag[i] << ' ' ;
    }
    write << "# " ; 

    write << "# " ;
    for(int i{} ; i < game_save.item_in_map.size() ; ++i) { // adding items in map
        string amount = to_string(game_save.item_in_map[i].second) ;
        write << game_save.item_in_map[i].first << ' ' << amount << ' ' ;
    }
    write << "# " ; 

    write << "# " ;
    for(int i{} ; i < game_save.villager_in_bag.size() ; ++i) { //adding villagers in bag 
        write << game_save.villager_in_bag[i] << ' ' ;
    }
    write << "# " ; 

    write << "# " ;
    for(int i{} ; i < game_save.villager_in_map.size() ; ++i) { //adding villager in map
        write << game_save.villager_in_map[i].first << ' ' << game_save.villager_in_map[i].second << ' ' ;
    }
    write << "# " ; 

    write << "# " ;
    for(int i{} ; i < game_save.perk_card_remain_in_bag.size() ; ++i) { // adding perk card remains
        write << game_save.perk_card_remain_in_bag[i] << ' ' ;
    }
    write << "# " ; 

    write << "# " ; 
    for(int i{} ; i < game_save.monster_card_remain_in_bag.size() ; ++i) { // adding monster card remains
        write << game_save.monster_card_remain_in_bag[i] << ' ' ;
    }
        write << "# " ; 
    

    write.close();
}

//////////////////////////////////////////////////////////////////////////////
////////////////////////////////( MOUSE )/////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

bool Menu::Draw_Left_Click(Rectangle rect, const char* text, Color first_color, Color second_color, Color text_color){

    Vector2 mouse_pointer = GetMousePosition();
    bool is_in_rect = CheckCollisionPointRec(mouse_pointer, rect);

    DrawRectangleRec(rect, is_in_rect ? second_color : first_color);

    int text_width = MeasureText(text, 40);
    DrawText(text, rect.x + (rect.width - text_width) / 2, rect.y + 30, 40, text_color);

    return is_in_rect && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool Menu::Draw_Left_Click_File(Rectangle rect, const char* text, Color first_color, Color second_color, Color text_color){

    text = Write_Info_Or_None(string(text)).c_str();

    Vector2 mouse_pointer = GetMousePosition();
    bool is_in_rect = CheckCollisionPointRec(mouse_pointer, rect);

    DrawRectangleRec(rect, is_in_rect ? second_color : first_color);

    int text_width = MeasureText(text, 40);
    DrawText(text, rect.x + (rect.width - text_width) / 2, rect.y + 30, 40, text_color);

    return is_in_rect && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

bool Menu::Draw_ClickS_To_Save_File(Rectangle rect, const char* text, Color first_color, Color second_color, Color text_color){

    text = Write_Info_Or_None(string(text)).c_str();

    Vector2 mouse_pointer = GetMousePosition();
    bool is_in_rect = CheckCollisionPointRec(mouse_pointer, rect);

    DrawRectangleRec(rect, is_in_rect ? second_color : first_color);

    int text_width = MeasureText(text, 40);
    DrawText(text, rect.x + (rect.width - text_width) / 2, rect.y + 30, 40, text_color);

    return is_in_rect && IsKeyDown(KEY_S);
}

bool Menu::Draw_Right_Click_File(Rectangle rect, const char* text, Color first_color, Color second_color, Color text_color){

    text = Write_Info_Or_None(string(text)).c_str();

    Vector2 mouse_pointer = GetMousePosition();
    bool is_in_rect = CheckCollisionPointRec(mouse_pointer, rect);

    DrawRectangleRec(rect, is_in_rect ? second_color : first_color);

    int text_width = MeasureText(text, 40);
    DrawText(text, rect.x + (rect.width - text_width) / 2, rect.y + 30, 40, text_color);

    return is_in_rect && IsMouseButtonPressed(MOUSE_RIGHT_BUTTON);
}

void Menu::Draw_Option(bool draw){

    int text_x =  0;
    int text_y = 0;

    Color text_color = WHITE;

    DrawText("Click mouse Left_click to select.", text_x, text_y, 20,text_color);

    if(draw){

        DrawText("Click mouse right_click to delete select file_save.", text_x, text_y + 30, 20,text_color);
        DrawText("Click Key_S to save now game on select file.", text_x, text_y + 60, 20,text_color);
        DrawText("Click Key_N to start s new game->", text_x, text_y + 90, 20,text_color);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
string Menu::Write_Info_Or_None(const string& filename){

    string res;
    if(Is_File_Empty(filename)){
        res = "New";
    }
    else{
        Game_Save game_save;
        Func_Read_Data(game_save, filename);
        res = game_save.time_save;
    }
    return res;
}

bool Menu::Is_File_Empty(const std::string& filename){

    ifstream file(filename, std::ios::ate); 
    bool is_empty = (file.tellg() == 0);
    file.close();
    return is_empty;
}

string Menu::Get_Current_Time(){

    time_t now = time(nullptr);
    tm* local = localtime(&now);

    char buffer[100];
    strftime(buffer, sizeof(buffer), "%d/%m_%H:%M:%S", local);

    return std::string(buffer);
}

void Menu::set_new_game(shared_ptr<Game>game) {
    game = make_shared<Game>() ;
}