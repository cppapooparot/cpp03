#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(), gate_keeper(false)
{
    this->hit_point = 100;
    this->energy_point = 50;
    this->attack_damage = 20;
    std::cout << "Default constructor for unnamed ScavTrap" << std::endl; 
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), gate_keeper(false)
{
    this->hit_point = 100;
    this->energy_point = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap " << name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other), gate_keeper(other.gate_keeper)
{
    std::cout << "ScavTrap copy constructor called for " << other.name << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " destructed." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->gate_keeper = other.gate_keeper;
        std::cout << "ScavTrap assignment operator called for " << other.name << std::endl;
    }
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
    this->gate_keeper = true;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->energy_point > 0 && this->hit_point > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage<< " points of damage!" << std::endl;
        this->energy_point--;
    }
    else
        std::cout << "ScavTrap " << this->name << " cannot attack"
                  << (this->energy_point <= 0 ? " because it is out of energy!" : " because it has no hit points left!")
                  << std::endl;
}