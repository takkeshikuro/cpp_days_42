/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:54:13 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 03:40:54 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap() {
	name = "default_name";
	_hit_point = FragTrap::default_hp;
	_energy_point = ScavTrap::default_energy_points;
	_attack_damage = FragTrap::default_attack_damage;
	std::cout << "[Default constructor DIAMONDTRAP called" << std::endl;
	std::cout << "New DiamondTrap with default name set." << std::endl << std::endl; 
}

DiamondTrap::DiamondTrap(std::string str)
: ClapTrap(str + "_clap_name"), ScavTrap(), FragTrap(), name(_name) {
	_hit_point = FragTrap::default_hp;
	_energy_point = ScavTrap::default_energy_points;
	_attack_damage = FragTrap::default_attack_damage;
	std::cout << "[Normal constructor DIAMONDTRAP called]" << std::endl;
	std::cout << "New DiamondTrap " << str << " name set." << std::endl  << std::endl; 
}

DiamondTrap::DiamondTrap(DiamondTrap const &cpy) 
: ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy) {
	name = cpy.name;
	std::cout << "[DiamondTrap copy constructor called]" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &cpy) {
	std::cout << "[DiamondTrap copy assignment operator called]" << std::endl;
	if (this != &cpy) {
        ScavTrap::operator=(cpy);
        FragTrap::operator=(cpy);
        _name = cpy._name; 
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "[DiamondTrap " << _name << " destructor called]" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
	if (_hit_point > 0)
	{
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "| My name is " << name << std::endl;
		std::cout << "| and my ClapTrap's name is " << ClapTrap::_name << std::endl;
		std::cout << "----------------------------------------------------------";
	}
	else {
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout	<< "DiamondTrap " << _name << " is dead" << std::endl;
		std::cout << "----------------------------------------------------------";
	}
	std::cout << std::endl;
}

void DiamondTrap::printAttributes() const {
	std::cout << "Attributes :" << std::endl;
	std::cout	<< "{HP:" << _hit_point
				<< " Energy Points: " << _energy_point 
				<< " Attack Damage: "  <<  _attack_damage << "}" << std::endl;
	std::cout << std::endl;
}
