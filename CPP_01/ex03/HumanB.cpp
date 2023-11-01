/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:15:58 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/01 08:26:27 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Weapon.hpp"

HumanB::HumanB(void) {}


HumanB::HumanB(std::string name) 
: _weapon(NULL), _name(name) {}


HumanB::HumanB(std::string name, Weapon *weapon)
: _weapon(weapon), _name(name) {}


HumanB::~HumanB(void) {}


void    HumanB::attack() const
{
    std::cout << _name << " attack with their ";
    if (_weapon)
        std::cout << _weapon->getType() << std::endl;
    else
        std::cout << "...nothing.." << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}