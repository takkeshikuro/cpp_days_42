/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:55:21 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/24 07:35:12 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public :
		ScavTrap(void);
		ScavTrap(ScavTrap const &cpy);
		ScavTrap& operator=(ScavTrap const &cpy);
		ScavTrap(std::string str);
		~ScavTrap(void);
		void attack(const std::string &target);
		void guardGate();
		
	protected:
		static const int default_hp = 100;
		static const int default_energy_points = 50;
		static const int default_attack_damage = 100;
		bool _guarding_gate;
};

#endif