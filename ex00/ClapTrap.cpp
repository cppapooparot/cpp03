#include "ClapTrap.hpp"
#include <iostream>

Clap_Trap::Clap_Trap() : hit_point(10), energy_point(10), attack_damage(0)
{
    std::cout << "Default constructor" << std::endl; 
}

Clap_Trap::Clap_Trap(const std::string& name) : name(name)
{
    std::cout << "Constructor with argument" << std::endl;
}

Clap_Trap::Clap_Trap(const Clap_Trap& other)
{
    std::cout << "Copy constructor" << std::endl;
    this->name = other.name;
    this->attack_damage = other.attack_damage;
    this->energy_point = other.energy_point;
    this->hit_point = other.hit_point;
}

Clap_Trap& Clap_Trap::operator=(const Clap_Trap& other)
{
    std::cout << "Copy assigment operator" << std::endl;
    if (this == &other)
        return *this;
    this->name = other.name;
    this->attack_damage = other.attack_damage;
    this->energy_point = other.energy_point;
    this->hit_point = other.hit_point;
    return (*this);
}

Clap_Trap::~Clap_Trap()
{
    std::cout << "Destructor" << std::endl;
}

void Clap_Trap::attack(const std::string& target)
{
    if (this->energy_point == 0)
    {
        std::cerr << "ClapTrap " << this->name << " can't attack because it has no energy points left" << std::endl;
        return;
    }
    if (this->hit_point == 0)
    {
        std::cerr << "ClapTrap " << this->name << " can't attack because it has no hit points left" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}

void Clap_Trap::takeDamage(unsigned int amount)
{
    if (this->hit_point < amount)
        this->hit_point = 0;
    int hit;
    if (hit_point < amount)
        hit = hit_point;
    else
        hit = amount;
    std::cout << "ClapTrap " << this->name << "takes " << hit << " points of damage! Remaining hit points: " << 
              << std::endl;
}


