/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:23:03 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 02:42:22 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	_name = "default_name";
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
	std::cout << "[Default constructor FLAGTRAP called]" << std::endl;
	std::cout << "New FragTrap with default name set." << std::endl << std::endl; 
}

FragTrap::FragTrap(std::string str) {
	_name = str;
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
	std::cout << "Normal FLAGTRAP constructor called]" << std::endl;
	std::cout << "New FragTrap " << str << " name set." << std::endl  << std::endl; 
}

FragTrap::FragTrap(FragTrap const &cpy) : ClapTrap(cpy) {
	_name = cpy._name;
	_hit_point = cpy._hit_point;
	_energy_point = cpy._energy_point;
	_attack_damage = cpy._attack_damage;
}

FragTrap &FragTrap::operator=(const FragTrap &cpy) {
	if (this != &cpy) {
		_name = cpy._name;
		_hit_point = cpy._hit_point;
		_energy_point = cpy._energy_point;
		_attack_damage = cpy._attack_damage;
	}
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "[Flagtrap " << _name << " destructor called]" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (_energy_point > 0) {
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "| FragTrap " << _name << " give high fives!" << std::endl;
		std::cout << "----------------------------------------------------------";
	}
	else {
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "| FragTrap " << _name << " has no energy point." << std::endl;
		std::cout << "----------------------------------------------------------";
	}
	std::cout << std::endl;
}