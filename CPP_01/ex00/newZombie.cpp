/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:54:15 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/01 03:28:25 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *newZombie;

	newZombie = new Zombie;
	newZombie->set_name(name);
	return newZombie;
}
