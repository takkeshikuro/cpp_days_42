/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:22:00 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 02:39:37 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	_name = "default_name";
	_hit_point = 10;
	_energy_point = 10;
	_attack_damage = 0;
	std::cout << "[Default constructor CLAPTRAP called]" << std::endl;
	std::cout << "New ClapTrap with default name set." << std::endl << std::endl; 
}

ClapTrap::ClapTrap(std::string str) {
	_name = str;
	_hit_point = 10;
	_energy_point = 10;
	_attack_damage = 0;
	std::cout << "[Normal constructor CLAPTRAP called]" << std::endl;
	std::cout << "New ClapTrap " << str << " name set." << std::endl  << std::endl; 
}

ClapTrap::ClapTrap(ClapTrap const &cpy) {
	_name = cpy._name;
	_hit_point = cpy._hit_point;
	_energy_point = cpy._energy_point;
	_attack_damage = cpy._attack_damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &cpy) {
	if (this != &cpy) {
		_name = cpy._name;
		_hit_point = cpy._hit_point;
		_energy_point = cpy._energy_point;
		_attack_damage = cpy._attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "[ClapTrap " << _name << " destructor called]" << std::endl;
}

std::string ClapTrap::get_name() const {
	return _name;
}

int	ClapTrap::get_attack_damage() const {
	return _attack_damage;
}

int ClapTrap::get_energy_point() const {
	return _energy_point;
}

int ClapTrap::get_hit_point() const {
	return _hit_point;
}

void ClapTrap::attack(const std::string& target) {
	if (_energy_point > 0 && _hit_point > 0)
	{
		_energy_point -= 1;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "| ClapTrap " << _name << " attacks " << target;
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
			std::cout << "| ClapTrap " << _name << " doesn't have enough energy point!" << std::endl;
			std::cout << "| " << target << " is lucky and nothing happened." << std::endl;
			std::cout << "----------------------------------------------------------" << std::endl;
			std::cout << std::endl;
		}
		else if (_hit_point <= 0) {
			std::cout << "----------------------------------------------------------" << std::endl;
			std::cout << "| ClapTrap " << _name << " is dead!!";
			std::cout << "----------------------------------------------------------" << std::endl;
			std::cout << std::endl;
		}
		
	}
}

void ClapTrap::takeDamage(unsigned int amount) {

	int hp_left = _hit_point - amount;
	if (hp_left > 0)
	{
		_hit_point -= amount;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "| ClapTrap " << _name << " took " << amount << " damage! ";
		if (amount == 0)
			std::cout << "so it's ok lol" << std::endl;
		else
			std::cout << "but he can resist the attack! " << std::endl;
		std::cout << "| " << _name << " has now " << _hit_point << " hp." << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}
	else if (hp_left <= 0)
	{
		_hit_point =  0;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "| ClapTrap " << _name << " took " << amount << " damage! ";
		std::cout << "| " << _name << " died..." << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy_point > 0 && _hit_point > 0)
	{
		_energy_point -= 1;
		if (_hit_point <= UINT_MAX - amount)
			_hit_point += amount;
		else
			_hit_point = UINT_MAX;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "| ClapTrap " << _name << " regenerates ";
		std::cout << amount << " health points and look better." << std::endl;
		std::cout << "| " << _name << " has now " <<_energy_point << " energy points and ";
		std::cout << _hit_point << " health points." << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "| ClapTrap " << _name << " doesn't have enough energy point! " << std::endl;
		std::cout << "| He can't regenerates and looks weakened..." << std::endl;
		std::cout << "| " << _name << " has only " << _hit_point << " health points." << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}
}
