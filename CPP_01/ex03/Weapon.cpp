/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:11:32 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/14 04:31:43 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Weapon.hpp"

Weapon::Weapon(std::string str) {
	this->setType(str); 
}

Weapon::~Weapon(void) {}


const std::string& Weapon::getType(void) const {
    return this->_type;
}

void Weapon::setType(std::string str) {
    this->_type = str;
}
