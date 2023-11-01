/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:49:24 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/01 04:12:34 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "one zombie is created." << std::endl;
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