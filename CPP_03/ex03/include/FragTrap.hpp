/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:55:11 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/24 07:12:29 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap 
{
	public :
		FragTrap();
		FragTrap(std::string str);
		FragTrap(FragTrap const &cpy);
		FragTrap& operator=(FragTrap const &cpy);
		~FragTrap();
		void highFivesGuys(void);
		
	protected:
		static const int default_hp = 100;
		static const int default_energy_points = 100;
		static const int default_attack_damage = 30;
};

#endif