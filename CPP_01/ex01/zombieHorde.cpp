/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:51:06 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/01 04:18:45 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;
	
	horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].set_name(name);

	return horde;
}