#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    {
        ClapTrap base("Base");
        base.attack("dummy");
    }

    {
        ScavTrap s("Scav");
        s.attack("dummy");
        s.guardGate();
    }

    {
        FragTrap f("Frag");
        f.attack("dummy");
        f.highFivesGuys();

        FragTrap copy(f);
        copy.highFivesGuys();

        FragTrap assigned;
        assigned = f;
        assigned.attack("dummy");
    }

    return 0;
}