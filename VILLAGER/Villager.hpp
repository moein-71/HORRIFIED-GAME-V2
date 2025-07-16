#ifndef VILLAGER_H
#define VILLAGER_H

#include <string>
#include <functional>

class Villager{

    friend bool operator==(const Villager&, const Villager&);

    public:

        Villager() = default;
        Villager(std::string, std::string, std::string);

        std::string get_name()const;
        std::string get_safe_place()const;
        std::string get_now_place()const;

        void set_name(std::string);
        void set_safe_place(std::string);
        void set_now_place(std::string);

    private:

        std::string name;
        std::string safe_place;
        std::string now_place;
};

namespace std {
    template <>
    struct hash<Villager> {
        std::size_t operator()(const Villager& v) const {
            return hash<std::string>()(v.get_name()) ^
                   (hash<std::string>()(v.get_now_place()) << 1) ^
                   (hash<std::string>()(v.get_safe_place()) << 2);
        }
    };
}

#endif//VILLAGER_H