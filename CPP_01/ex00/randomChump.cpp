/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:34:35 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/01 03:28:29 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

void randomChump( std::string name )
{
	Zombie newZombie;

	newZombie.set_name(name);
	std::cout << newZombie.get_name() << ":  BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
	return ;
}