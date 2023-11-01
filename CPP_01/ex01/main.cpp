/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:47:59 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/01 04:22:56 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"


void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

int main(void)
{
	Zombie *newhorde;
	int N = 10;

	newhorde = zombieHorde(N, "zombie_name");
	for (int i = 0; i < N; i++)
	{
		std::cout << "this is a new zombie :" << std::endl;	
		newhorde[i].announce();
	}
	delete [] newhorde;
	return 0;
}
