#ifndef ITEM_H
#define ITEM_H

#include <functional>
#include <string>

class Item{

    public:
    
        Item() = default;
        explicit Item(int);//this constructor males temp_obj_Item  
        Item(std::string, std::string, std::string, int);

        std::string get_name()const;
        std::string get_spawn_place()const;
        std::string get_color()const;
        int get_strength()const;

        void set_name(std::string);
        void set_spawn_place(std::string);
        void set_color(std::string);
        void set_strength(int);

        bool operator==(const Item&)const;

    private:

        std::string name;
        std::string spawn_place;
        std::string color;
        int strength;
};

namespace std{

    template<>
    struct hash<Item>{

        std::size_t operator()(const Item& item) const {
            return hash<std::string>()(item.get_name()) ^
                   (hash<std::string>()(item.get_spawn_place()) << 1) ^
                   (hash<std::string>()(item.get_color()) << 2) ^
                   (hash<int>()(item.get_strength()) << 3);
        }
    };
}

#endif //ITEM_H