/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:54:53 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/01 02:55:12 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "one Zombie " << " is created." << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "one Zombie " << name << " is destroyed." << std::endl;
	return ;
}

std::string Zombie::get_name() const {
	return name;
}

void    Zombie::set_name(std::string str)
{
	this->name = str;
	return ;
}