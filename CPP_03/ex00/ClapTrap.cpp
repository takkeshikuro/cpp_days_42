/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 03:09:59 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/22 05:30:57 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	_name = "default_name";
	_hit_point = 10;
	_energy_point = 10;
	_attack_damage = 0;
	std::cout << "default constructor called" << std::endl;
	std::cout << "new ClapTrap w default name set." << std::endl << std::endl; 
}

ClapTrap::ClapTrap(std::string str) {
	_name = str;
	_hit_point = 10;
	_energy_point = 10;
	_attack_damage = 0;
	std::cout << "[normal constructor called]" << std::endl;
	std::cout << "(new ClapTrap " << str << ") name set." << std::endl  << std::endl; 
}

ClapTrap::~ClapTrap(void) {
	std::cout << "(ClapTrap " << _name << ")";
	std::cout << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_energy_point > 0 && _hit_point > 0)
	{
		_energy_point -= 1;
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		std::cout << "ClapTrap " << _name << " attacks " << target;
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
			std::cout << "ClapTrap " << _name << " doesn't have enough energy point! ";
			std::cout << target << " is lucky and nothing happened." << std::endl;
			std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
			std::cout << std::endl;
		}
		else if (_hit_point <= 0) {
			std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
			std::cout << "ClapTrap " << _name << " is dead!!";
			std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
			std::cout << std::endl;
		}
		
	}
}

void ClapTrap::takeDamage(unsigned int amount) {

	int hp_left = _hit_point - amount;
	if (hp_left > 0)
	{
		_hit_point -= amount;
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		std::cout << "ClapTrap " << _name << " took " << amount << " damage! ";
		if (amount == 0)
			std::cout << "so it's ok lol" << std::endl;
		else
			std::cout << "but he can resist the attack! " << std::endl;
		std::cout << _name << " has now " << _hit_point << " hp." << std::endl;
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		std::cout << std::endl;
	}
	else if (hp_left <= 0)
	{
		_hit_point =  0;
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		std::cout << "ClapTrap " << _name << " took " << amount << " damage! ";
		std::cout << _name << " died..." << std::endl;
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		std::cout << std::endl;
	}
	
	
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy_point > 0 && _hit_point > 0)
	{
		_energy_point -= 1;
		_hit_point += amount;
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		std::cout << "ClapTrap " << _name << " regenerates ";
		std::cout << amount << " health points and look better." << std::endl;
		std::cout << _name << " has now " <<_energy_point << " energy points and ";
		std::cout << _hit_point << " health points." << std::endl;
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		std::cout << "ClapTrap " << _name << " doesn't have enough energy point! ";
		std::cout << "He can't regenerates and looks weakened..." << std::endl;
		std::cout << _name << " has only " << _hit_point << " health points." << std::endl;
		std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;		
		std::cout << std::endl;
	}
}
