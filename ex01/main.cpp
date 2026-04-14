#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    ScavTrap a;
    ScavTrap b("Bob");

    b.attack("target");
    b.takeDamage(30);
    b.beRepaired(10);
    b.guardGate();

    ScavTrap c(b);
    c.attack("another target");

    a = b;
    a.attack("third target");

    return 0;
}