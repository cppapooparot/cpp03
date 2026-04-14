#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("Unnamed"), hit_point(10), energy_point(10), attack_damage(0)
{
    std::cout << "Default constructor for ClapTrap" << std::endl; 
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hit_point(10), energy_point(10), attack_damage(0)
{
    std::cout << "Constructor with argument" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor" << std::endl;
    this->name = other.name;
    this->attack_damage = other.attack_damage;
    this->energy_point = other.energy_point;
    this->hit_point = other.hit_point;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
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

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hit_point == 0)
    {
        std::cerr << "ClapTrap " << this->name << " can't attack because it has no hit points left" << std::endl;
        return;
    }
    if (this->energy_point == 0)
    {
        std::cerr << "ClapTrap " << this->name << " can't attack because it has no energy points left" << std::endl;
        return;
    }
    --this->energy_point;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_point == 0)
    {
        std::cerr << "ClapTrap " << this->name << " already has 0 hit points" << std::endl;
        return;
    }
    int previous = this->hit_point;
    if (amount >= static_cast<unsigned int>(this->hit_point))
        this->hit_point = 0;
    else
        this->hit_point -= static_cast<int>(amount);
    int taken = previous - this->hit_point;
    std::cout << "ClapTrap " << this->name << " takes " << taken << " points of damage! Remaining hit points: " << this->hit_point << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_point == 0)
    {
        std::cerr << "ClapTrap " << this->name << " can't be repaired because it has no hit points left" << std::endl;
        return;
    }
    if (this->energy_point == 0)
    {
        std::cerr << "ClapTrap " << this->name << " can't be repaired because it has no energy points left" << std::endl;
        return;
    }
    --this->energy_point;
    this->hit_point += static_cast<int>(amount);
    std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " points! Remaining hit points: " << this->hit_point << std::endl;
}


