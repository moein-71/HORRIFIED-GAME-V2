# cmake_minimum_required(VERSION 3.5)

# project(fact)

# #set(CMAKE_CXX_STANDARD 14) for using version 14 compiler and now every one can use it 

# add_executable(app ../src/main.cpp)

include_directories( ../Game ../Game_turn ../Game_turn/Turn_hero ../Game_turn/Turn_monster 
../Monster_action ../Monster_action/Kill ../Monster_action/Move_monster ../Monster_action/Power ../Monster_card ../Monster_card/card 
../Perk_card ../Perk_card/card ../ACTION ../ACTION/ADVANCE ../ACTION/DEFEAT ../ACTION/GUIDE ../ACTION/MOVE_HERO ../ACTION/PICK_UP 
../ACTION/SPECIAL_ACTION ../HERO ../ITEM ../VILLAGER ../MAP ../MONSTER ../Programm ../Player)

cmake_minimum_required(VERSION 3.10)
project(Game_Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# لیست کامل فایل‌های سورس
add_executable(app
    # فایل‌های اصلی
    ../Programm/main.cpp
    ../Programm/Programm.cpp
    ../Game/Game.cpp
    ../Player/Player.cpp
    
    # فایل‌های Game_turn
    ../Game_turn/Turn_hero/Turn_hero.cpp
    ../Game_turn/Turn_monster/Turn_monster.cpp
    
    # فایل‌های HERO
    ../HERO/Archaologist.cpp
    ../HERO/Hero.cpp
    ../HERO/Mayor.cpp
    ../HERO/Courier.cpp
    ../HERO/Scientist.cpp
    
    # فایل‌های ITEM
    ../ITEM/Item.cpp
    
    # فایل‌های MAP
    ../MAP/Map.cpp
    
    # فایل‌های MONSTER
    ../MONSTER/Dracula.cpp
    ../MONSTER/Invisible_man.cpp
    ../MONSTER/Monster.cpp
    
    # فایل‌های VILLAGER
    ../VILLAGER/Villager.cpp
    
    # فایل‌های ACTION
    ../ACTION/ADVANCE/Advance.cpp
    ../ACTION/DEFEAT/Defeat.cpp
    ../ACTION/GUIDE/Guide.cpp
    ../ACTION/MOVE_HERO/Move_Hero.cpp
    ../ACTION/PICK_UP/Pick_Up.cpp
    ../ACTION/SPECIAL_ACTION/Special_Action.cpp
    
    # فایل‌های Monster_card
    ../Monster_card/card/Egyptian_Expert.cpp
    ../Monster_card/card/Form_of_The_Bat.cpp
    ../Monster_card/card/Former_Employer.cpp
    ../Monster_card/card/Fortune_Teller.cpp
    ../Monster_card/card/Hurried_Assistant.cpp
    ../Monster_card/card/Hypnotic_Gaze.cpp
    ../Monster_card/card/On_The_Move.cpp
    ../Monster_card/card/Sunrise.cpp
    ../Monster_card/card/The_Delivery.cpp
    ../Monster_card/card/The_Ichthyologist.cpp
    ../Monster_card/card/The_Innocent.cpp
    ../Monster_card/card/Thief.cpp
    ../Monster_card/card/Monster_card_empty.cpp
    
    # فایل‌های Perk_card
    ../Perk_card/Perk_card.cpp
    ../Perk_card/card/Break_of_Dawn.cpp
    ../Perk_card/card/Hurry.cpp
    ../Perk_card/card/Late_into_the_Night.cpp
    ../Perk_card/card/Overstock.cpp
    ../Perk_card/card/Repel.cpp
    ../Perk_card/card/Visit_from_the_Detective.cpp
    ../Perk_card/card/Perk_empty.cpp
    
    # فایل‌های Monster_action
    ../Monster_action/Kill/Kill.cpp
    ../Monster_action/Move_monster/Move_monster.cpp
    ../Monster_action/Power/Power.cpp
)

# دایرکتوری‌های شامل
target_include_directories(app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/ACTION
    ${CMAKE_CURRENT_SOURCE_DIR}/Game
    ${CMAKE_CURRENT_SOURCE_DIR}/Game_turn
    ${CMAKE_CURRENT_SOURCE_DIR}/HERO
    ${CMAKE_CURRENT_SOURCE_DIR}/ITEM
    ${CMAKE_CURRENT_SOURCE_DIR}/MAP
    ${CMAKE_CURRENT_SOURCE_DIR}/MONSTER
    ${CMAKE_CURRENT_SOURCE_DIR}/Monster_action
    ${CMAKE_CURRENT_SOURCE_DIR}/Monster_card
    ${CMAKE_CURRENT_SOURCE_DIR}/Monster_card/card
    ${CMAKE_CURRENT_SOURCE_DIR}/Perk_card
    ${CMAKE_CURRENT_SOURCE_DIR}/Perk_card/card
    ${CMAKE_CURRENT_SOURCE_DIR}/VILLAGER
)

# در صورت نیاز کتابخانه‌ها
find_package(Threads REQUIRED)
target_link_libraries(app PRIVATE Threads::Threads)