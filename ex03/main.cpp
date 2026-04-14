#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

    {
        DiamondTrap d("Diamond");
        d.attack("dummy");
        d.highFivesGuys();
        d.guardGate();
        d.whoAmI();

        DiamondTrap copy(d);
        copy.whoAmI();

        DiamondTrap assigned;
        assigned = d;
        assigned.whoAmI();
    }

    return 0;
}