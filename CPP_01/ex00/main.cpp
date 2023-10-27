/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:16:48 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/27 10:41:42 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"
#include "include/Zombie.h"

Zombie::Zombie(void)
{
	std::cout << "start" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "end" << std::endl;
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

Zombie* newZombie( std::string name )
{
	Zombie *newZombie;
	
	newZombie->set_name(name);
	return (newZombie);
}


void randomChump( std::string name )
{
	
}

int main(void)
{
	Zombie newZ;
	newZ = newZombie("tak");
	
}