/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:54:13 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/23 07:58:33 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap() {
	_name = "default_name";
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
	std::cout << "default constructor FLAGTRAP called" << std::endl;
	std::cout << "new DiamondTrap with default name set." << std::endl << std::endl; 
}

DiamondTrap::DiamondTrap(std::string str) {
	_name = str;
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
	std::cout << "[normal FLAGTRAP constructor called]" << std::endl;
	std::cout << "(new DiamondTrap " << str << ") name set." << std::endl  << std::endl; 
}

DiamondTrap::DiamondTrap(DiamondTrap const &cpy) : Cl>apTrap(cpy) {
	_name = cpy._name;
	_hit_point = cpy._hit_point;
	_energy_point = cpy._energy_point;
	_attack_damage = cpy._attack_damage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &cpy) {
	if (this != &cpy) {
		_name = cpy._name;
		_hit_point = cpy._hit_point;
		_energy_point = cpy._energy_point;
		_attack_damage = cpy._attack_damage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "(FLAGTRAP " << _name << ")";
	std::cout << " destructor called" << std::endl;
}