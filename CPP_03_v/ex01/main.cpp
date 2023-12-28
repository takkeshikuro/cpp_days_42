/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 06:12:37 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 02:35:34 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"

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

int main() {
	ClapTrapTests("TAK");
	std::cout << std::endl;
	ScavTrapTests("TAK");
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