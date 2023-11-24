#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"
#include "include/DiamondTrap.hpp"
#include <iostream> //cout, endl
#include <climits>  // UINT_MAX

# define GREEN "\033[32m"
# define RESET "\033[0m"

void ClapTrapTests(const std::string &player) {
	std::cout << GREEN "[ClapTrap Tests]" RESET << std::endl;
	ClapTrap claptrap("CL4P-TP");
	std::endl(std::cout);

	claptrap.attack(player);
	claptrap.beRepaired(UINT_MAX);
	claptrap.beRepaired(1);
	claptrap.takeDamage(UINT_MAX - 5);
	for (int i = 0; i < 8; i++)
		claptrap.attack("[filler to use up energy points]");
	claptrap.beRepaired(1);
	claptrap.attack(player);
	std::endl(std::cout);
}

void ScavTrapTests(const std::string &player) {
	std::cout << GREEN "[ScavTrap Tests]" RESET << std::endl;
	ScavTrap scavtrap("SC4V-TP");
	std::endl(std::cout);

	scavtrap.attack(player);
	scavtrap.guardGate();
	scavtrap.guardGate();
	std::endl(std::cout);
}


void FragTrapTests(const std::string &player) {
	std::cout << GREEN "[FragTrap Tests]" RESET << std::endl;
	FragTrap fragtrap("FR4G-TP");
	std::endl(std::cout);

	fragtrap.attack(player);
	fragtrap.highFivesGuys();
	std::endl(std::cout);
}

void DiamondTrapTests(const std::string &player) {
	std::cout << GREEN "[DiamondTrap Tests]" RESET << std::endl;
	DiamondTrap diamondtrap("DI4M0ND-TP");
	std::endl(std::cout);

	diamondtrap.printAttributes();
	diamondtrap.attack(player);
	diamondtrap.whoAmI();

	std::endl(std::cout);
}

int main() {
	std::string player = "Wilhelm";

	ClapTrapTests(player);
	std::endl(std::cout);
	ScavTrapTests(player);
	std::endl(std::cout);
	FragTrapTests(player);
	std::endl(std::cout);
	DiamondTrapTests(player);
}