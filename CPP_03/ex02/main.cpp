/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:21:48 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/23 07:47:45 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"

#include <climits>  // UINT_MAX


# define GREEN "\033[32m"
# define RESET "\033[0m"

void ClapTrapTests(const std::string &player) {
	std::cout << GREEN "[ClapTrap Tests]" RESET << std::endl;
	ClapTrap claptrap("joe");
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
	ScavTrap scavtrap("mr_robot");
	std::endl(std::cout);

	scavtrap.attack(player);
	scavtrap.guardGate();
	scavtrap.guardGate();
	std::endl(std::cout);
}

void FragTrapTests(const std::string &player) {
	std::cout << GREEN "[FragTrap Tests]" RESET << std::endl;
	FragTrap fragtrap("robot_BIS");
	std::endl(std::cout);

	fragtrap.attack(player);
	fragtrap.highFivesGuys();
	std::endl(std::cout);
}

int main() {
	std::string player = "tak";

	ClapTrapTests(player);
	std::endl(std::cout);
	ScavTrapTests(player);
    FragTrapTests(player);
}

/* int main(void)
{
	ClapTrap tak("tak");
	ClapTrap joe("joe");

	tak.attack(joe.get_name());
	joe.takeDamage(tak.get_attack_damage());
	joe.beRepaired(2);
	joe.attack(tak.get_name());
	tak.takeDamage(joe.get_attack_damage());

    ScavTrap prince("prince");
    prince.attack(joe.get_name());
	
	return 0;
} */