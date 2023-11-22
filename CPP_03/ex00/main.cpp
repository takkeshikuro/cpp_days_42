/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:23:46 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/22 05:14:04 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"

int main(void)
{
	ClapTrap tak("tak");
	ClapTrap joe("joe");

	tak.attack(joe.get_name());
	joe.takeDamage(tak.get_attack_damage());
	
	joe.beRepaired(2);
	
	joe.attack(tak.get_name());
	tak.takeDamage(joe.get_attack_damage());
	
	
	return 0;
}