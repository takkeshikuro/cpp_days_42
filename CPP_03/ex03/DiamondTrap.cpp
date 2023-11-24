/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:54:13 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/24 07:37:16 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap() {
	name = "default_name";
	_hit_point = FragTrap::default_hp;
	_energy_point = ScavTrap::default_energy_points;
	_attack_damage = FragTrap::default_attack_damage;
	std::cout << "[DIAMONDTRAP] default constructor called" << std::endl;
	std::cout << "new DiamondTrap with default name set." << std::endl << std::endl; 
}

DiamondTrap::DiamondTrap(std::string str)
: ClapTrap(str + "_clap_name"), ScavTrap(), FragTrap(), name(_name) {
//	name = str; (plus besoin)
	_hit_point = FragTrap::default_hp;
	_energy_point = ScavTrap::default_energy_points;
	_attack_damage = FragTrap::default_attack_damage;
	std::cout << "[DIAMONDTRAP] normal constructor called" << std::endl;
	std::cout << "(new DiamondTrap " << str << ") name set." << std::endl  << std::endl; 
}

DiamondTrap::DiamondTrap(DiamondTrap const &cpy) 
: ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy) {
	name = cpy.name;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &cpy) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &cpy) {
        ScavTrap::operator=(cpy);
        FragTrap::operator=(cpy);
        _name = cpy._name; 
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "(DIAMONDTRAP " << _name << ")";
	std::cout << " [DIAMONDTRAP] destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
	if (_hit_point > 0)
	{
		std::cout << "My name is " << name << std::endl;
		std::cout << "and my ClapTrap's name is " << ClapTrap::_name << std::endl;
	}
	else
		std::cout	<< "DiamondTrap " << _name << " is dead" << std::endl;
}

void DiamondTrap::printAttributes() const {
	std::cout	<< "HP:" << _hit_point
				<< " Energy Points: " << _energy_point 
				<< " Attack Damage: "  <<  _attack_damage << std::endl;
}
