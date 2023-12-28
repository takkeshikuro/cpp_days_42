/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:21:24 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 02:39:54 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(), _guarding_gate(false) {
	_name = "default_name";
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 20;
	std::cout << "[Default constructor SCAVTRAP called]" << std::endl;
	std::cout << "New ScavTrap with default name set." << std::endl << std::endl; 
}

ScavTrap::ScavTrap(std::string str) : _guarding_gate(false) {
	_name = str;
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 20;
	std::cout << "[Normal constructor SCAVTRAP called]" << std::endl;
	std::cout << "New ScavTrap " << str << " name set." << std::endl  << std::endl; 
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
	std::cout << "[ScavTrap " << _name << " destructor called]" << std::endl;
}

void	ScavTrap::attack(const std::string& target) 
{
	if (_energy_point > 0 && _hit_point > 0)
	{
		_energy_point -= 1;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "| SCAVTRAP " << _name << " attacks " << target;
		std::cout << ", causing " << _attack_damage << " points of damage!" << std::endl;
		std::cout << "| " << _name << " has now " <<_energy_point << " energy points and ";
		std::cout << _hit_point << " health point." << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		if (_energy_point <= 0) {
			std::cout << "----------------------------------------------------------" << std::endl;
			std::cout << "| SCAVTRAP " << _name << " doesn't have enough energy point! " << std::endl;
			std::cout << "| " << target << " is lucky and nothing happened." << std::endl;
			std::cout << "----------------------------------------------------------" << std::endl;
			std::cout << std::endl;
		}
		else if (_hit_point <= 0) {
			std::cout << "----------------------------------------------------------" << std::endl;
			std::cout << "| SCAVTRAP " << _name << " is dead!!";
			std::cout << "----------------------------------------------------------" << std::endl;
			std::cout << std::endl;
		}		
	}
}

void	ScavTrap::guardGate() 
{
	if (_guarding_gate == false) 
	{
		if (_energy_point <= 0) {
			std::cout << "----------------------------------------------------------" << std::endl;
			std::cout << "| SCAVTRAP " << _name << " doesn't have enough energy point! " << std::endl;
			std::cout << "----------------------------------------------------------" << std::endl;
		}
		else if (_hit_point <= 0) {
			std::cout << "----------------------------------------------------------" << std::endl;
			std::cout << "| SCAVTRAP " << _name << " is dead!!" << std::endl;
			std::cout << "----------------------------------------------------------" << std::endl;
			std::cout << std::endl;
		}
		else {
			_energy_point -= 1;
			_guarding_gate = true;
			std::cout << "----------------------------------------------------------" << std::endl;
			std::cout << "| SCAVTRAP " << _name << " is now in Gatekeeper mode!!" << std::endl;
			std::cout << "----------------------------------------------------------" << std::endl;
		}
	}
	else
	{
		_guarding_gate = false;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "| SCAVTRAP " << _name << " remove his Gatekeeper mode!!" << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;	
	}
}