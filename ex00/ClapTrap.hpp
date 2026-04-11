#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class Clap_Trap
{
    private:
        std::string name;
        int hit_point;
        int energy_point;
        int attack_damage;
    public:
        Clap_Trap();
        Clap_Trap(const std::string& name);
        Clap_Trap(const Clap_Trap& other);
        ~Clap_Trap();
        Clap_Trap& operator=(const Clap_Trap& other);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif