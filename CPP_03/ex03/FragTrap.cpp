/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:54:04 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 03:42:42 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
	std::cout << "[Default constructor FRAGTRAP called]" << std::endl;
	std::cout << "New FragTrap with default name set." << std::endl << std::endl; 
}

FragTrap::FragTrap(std::string str) : ClapTrap(str) {
	_name = str;
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
	std::cout << "[Normal constructor FRAGTRAP called]" << std::endl;
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
	std::cout << "[FragTrap " << _name << " destructor called]" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (_energy_point > 0) {
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "| FRAGTRAP " << _name << " give high fives!" << std::endl;
		std::cout << "----------------------------------------------------------";
	}
	else {
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "| FRAGTRAP " << _name << " has no energy point." << std::endl;
		std::cout << "----------------------------------------------------------";
	}
	std::cout << std::endl;
}