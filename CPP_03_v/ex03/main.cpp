#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"
#include "include/DiamondTrap.hpp"
#include <iostream> //cout, endl
#include <climits>  // UINT_MAX

# define GREEN "\033[32m"
# define RESET "\033[0m"

void ClapTrapTests(const std::string &player) {
	std::cout << std::endl;
	std::cout << GREEN "[CLAPTRAP TEST]" RESET << std::endl;
	std::cout << std::endl;
	
	ClapTrap claptrap("Joe");
	claptrap.attack(player); // attack on Tak
	claptrap.beRepaired(UINT_MAX); // heal int max
	claptrap.beRepaired(1); 	// try to heal one point more
	claptrap.takeDamage(UINT_MAX - 5);
	for (int i = 0; i < 8; i++)
		claptrap.attack("[test to get no energy points]");
	claptrap.beRepaired(1); // try to make action without energy point
	claptrap.attack(player);
	std::cout << std::endl;
}


void ScavTrapTests(const std::string &player) {
	std::cout << std::endl;
	std::cout << GREEN "[SCAVTRAP TEST]" RESET << std::endl;
	std::cout << std::endl;
		
	ScavTrap scavtrap("mr_robot");
	scavtrap.attack(player);
	scavtrap.guardGate(); // activ gatekeeper mode
	scavtrap.guardGate(); // remove gatekeeper mode
	std::cout << std::endl;
}

void FragTrapTests(const std::string &player) {
	std::cout << std::endl;
	std::cout << GREEN "[FRAGTRAP TEST]" RESET << std::endl;
	std::cout << std::endl;

	FragTrap fragtrap("robot_BIS");
	fragtrap.attack(player);
	fragtrap.highFivesGuys();
	std::endl(std::cout);
}

void DiamondTrapTests(const std::string &player) {
	std::cout << std::endl;
	std::cout << GREEN "[DiamondTrap Tests]" RESET << std::endl;
	std::cout << std::endl;
	
	DiamondTrap diamondtrap("DI4M0ND-TP");
	diamondtrap.printAttributes();
	diamondtrap.attack(player);
	diamondtrap.highFivesGuys();
	diamondtrap.guardGate();
	diamondtrap.whoAmI();
	std::endl(std::cout);
}

int main() {
	
	ClapTrapTests("TAK");
	ScavTrapTests("TAK");
    FragTrapTests("TAK");
	DiamondTrapTests("TAK");
	return 0;
}