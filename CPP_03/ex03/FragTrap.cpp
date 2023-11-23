/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:54:04 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/23 08:31:13 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	_name = "default_name";
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
	std::cout << "default constructor FLAGTRAP called" << std::endl;
	std::cout << "new FragTrap with default name set." << std::endl << std::endl; 
}

FragTrap::FragTrap(std::string str) {
	_name = str;
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
	std::cout << "[normal FLAGTRAP constructor called]" << std::endl;
	std::cout << "(new FragTrap " << str << ") name set." << std::endl  << std::endl; 
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
	std::cout << "(FLAGTRAP " << _name << ")";
	std::cout << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (_energy_point > 0) {
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		std::cout << "FragTrap " << _name << " give high fives!" << std::endl;
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	}
	else {
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		std::cout << "FragTrap " << _name << " has no energy point." << std::endl;
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	}
	std::cout << std::endl;
}