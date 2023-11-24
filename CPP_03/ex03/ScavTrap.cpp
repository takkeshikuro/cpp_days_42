/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:53:22 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/24 07:40:31 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(), _guarding_gate(false) {
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 20;
	std::cout << "[SCAVTRAP] default constructor called" << std::endl;
	std::cout << "new ScavTrap with default name set." << std::endl << std::endl; 
}

ScavTrap::ScavTrap(std::string str) : _guarding_gate(false) {
	_name = str;
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 20;
	std::cout << "[SCAVTRAP] normal constructor called" << std::endl;
	std::cout << "(new ScavTrap " << str << ") name set." << std::endl  << std::endl; 
}

ScavTrap::ScavTrap(ScavTrap const &cpy) : ClapTrap(cpy) {
	_name = cpy._name;
	_hit_point = cpy._hit_point;
	_energy_point = cpy._energy_point;
	_attack_damage = cpy._attack_damage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &cpy) {
	if (this != &cpy) {
		_name = cpy._name;
		_hit_point = cpy._hit_point;
		_energy_point = cpy._energy_point;
		_attack_damage = cpy._attack_damage;
	}
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "(ScavTrap " << _name << ")";
	std::cout << " [SCAVTRAP] destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target) 
{
	if (_energy_point > 0 && _hit_point > 0)
	{
		_energy_point -= 1;
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		std::cout << "SCAVTRAP " << _name << " attacks " << target;
		std::cout << ", causing " << _attack_damage << " points of damage!" << std::endl;
		std::cout << _name << " has now " <<_energy_point << " energy points and ";
		std::cout << _hit_point << " health point." << std::endl;
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		if (_energy_point <= 0) {
			std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
			std::cout << "SCAVTRAP " << _name << " doesn't have enough energy point! ";
			std::cout << target << " is lucky and nothing happened." << std::endl;
			std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
			std::cout << std::endl;
		}
		else if (_hit_point <= 0) {
			std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
			std::cout << "SCAVTRAP " << _name << " is dead!!";
			std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
			std::cout << std::endl;
		}		
	}
}

void	ScavTrap::guardGate() 
{
	if (_guarding_gate == false) 
	{
		if (_energy_point <= 0) {
			std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
			std::cout << "SCAVTRAP " << _name << " doesn't have enough energy point! " << std::endl;
			std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		}
		else if (_hit_point <= 0) {
			std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
			std::cout << "SCAVTRAP " << _name << " is dead!!" << std::endl;
			std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
			std::cout << std::endl;
		}
		else {
			_energy_point -= 1;
			_guarding_gate = true;
			std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
			std::cout << "SCAVTRAP " << _name << " is now in Gatekeeper mode!!" << std::endl;
			std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		}
	}
	else
	{
		_guarding_gate = false;
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		std::cout << "SCAVTRAP " << _name << " remove his Gatekeeper mode!!" << std::endl;
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;	
	}
}