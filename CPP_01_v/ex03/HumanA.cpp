/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:12:42 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/01 08:26:46 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
: _weapon(weapon), _name(name) {}

HumanA::~HumanA(void) {}


void    HumanA::attack() const
{
    std::cout << this->_name << " attack with their ";
    std::cout << this->_weapon.getType() << std::endl;
}
