/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:22:49 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 02:38:11 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap(void);
		ScavTrap(std::string str);
		ScavTrap(ScavTrap const &cpy);
		ScavTrap& operator=(ScavTrap const &cpy);
		~ScavTrap(void);

		void attack(const std::string &target);
		void guardGate();
	private:
		bool _guarding_gate;
};

#endif