/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:44:41 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/05 06:06:52 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Character.hpp"

Character::Character() : ICharacter(), name("") {
	
	std::cout << "default character constructor called" << std::endl;
	int i = 0;
	while (i < 4) {
		inventory[i++] = NULL;
	}    
}

Character::Character(std::string const &name) : ICharacter() {

	std::cout << "normal character constructor called" << std::endl;
	this->name = name;
	int i = 0;
	while (i < 4) {
		inventory[i++] = NULL;
	}    
}


Character::Character(Character const &cpy) : ICharacter(cpy), name(cpy.name) {
	std::cout << "cpy character constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (cpy.inventory[i])
			inventory[i] = cpy.inventory[i];
		else
			inventory[i] = NULL;
	}	
}

Character &Character::operator=(Character const &cpy) {
	std::cout << "operator Character = called" << std::endl;
	if (this != &cpy) 
	{
		this->name = cpy.name;
		for (int i = 0; i < 4; i++) 
		{
			if (cpy.inventory[i])
				inventory[i] = cpy.inventory[i];
			else
				inventory[i] = NULL;
		}		
	}
	return *this;
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete inventory[i];
}


void Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			std::cout << m->getType() << " now equipped" << std::endl;
			return ;
		}
	}
	std::cout << "Cannot equip " << m->getType() << " materia, no more slots available!" << std::endl;
}
	
	
void Character::unequip(int idx) {
	if (idx < 0 || 4 <= idx) {
		std::cout << "Cannot unequip, index out of range!" << std::endl;
		return;
	}
	if (inventory[idx]) {
		std::cout << "Unequipped " << inventory[idx]->getType() << " materia!" << std::endl;
		inventory[idx] = NULL;
		return;
	}
	std::cout << "Cannot unequip, no materia equipped in slot!" << std::endl;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || 4 <= idx) {
		std::cout << "Cannot use, index out of range!" << std::endl;
		return;
	}
	if (inventory[idx])
		inventory[idx]->use(target);
	else
		std::cout << "Cannot use, no materia equipped in slot!" << std::endl;
}