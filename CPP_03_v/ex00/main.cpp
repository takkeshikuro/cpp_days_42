/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:23:46 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 02:15:26 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"

# define GREEN "\033[32m"
# define RESET "\033[0m"

void ClapTrapTests(const std::string &player) {
	std::endl(std::cout);
	std::cout << GREEN "[ClapTrap Tests]" RESET << std::endl;
	std::endl(std::cout);
	
	ClapTrap claptrap("Joe");
	claptrap.attack(player); // attack on Tak
	claptrap.beRepaired(UINT_MAX); // heal int max
	claptrap.beRepaired(1); 	// try to heal one point more
	claptrap.takeDamage(UINT_MAX - 5);
	for (int i = 0; i < 8; i++)
		claptrap.attack("[test to get no energy points]");
	claptrap.beRepaired(1); // try to make action without energy point
	claptrap.attack(player);
	std::endl(std::cout);
}

int main() {
	ClapTrapTests("TAK");
	std::endl(std::cout);
}
