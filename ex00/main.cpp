#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    Clap_Trap a("A");
    Clap_Trap b("B");

    std::cout << "\n--- Basic attacks ---\n";
    a.attack("B");
    b.takeDamage(0);

    std::cout << "\n--- Repair ---\n";
    b.beRepaired(5);

    std::cout << "\n--- Copy + assignment ---\n";
    Clap_Trap c(a);
    Clap_Trap d;
    d = b;

    std::cout << "\n--- Drain energy ---\n";
    for (int i = 0; i < 11; ++i)
        a.attack("B");

    std::cout << "\n--- Reduce to 0 HP and test behavior ---\n";
    b.takeDamage(100);
    b.attack("A");
    b.beRepaired(3);

    return 0;
}