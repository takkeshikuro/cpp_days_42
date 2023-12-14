/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:47:59 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/14 03:29:16 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

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
