/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:49:24 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/14 03:29:22 by tmorikaw         ###   ########.fr       */
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

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

std::string Zombie::get_name() const {
	return name;
}

void    Zombie::set_name(std::string str)
{
	this->name = str;
	return ;
}