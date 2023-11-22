/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 06:11:27 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/22 06:58:39 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <iomanip>

class ScavTrap 
{
	public :
        ScavTrap();
        ScavTrap(std::string str);
        ~ScavTrap();
        
        
		
	private :
		std::string _name;
		int _hit_point;
		int _energy_point;
		int _attack_damage;
};

#endif