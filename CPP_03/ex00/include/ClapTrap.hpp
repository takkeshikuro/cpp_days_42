/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 05:31:41 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 00:56:46 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>
#include <climits>  // UINT_MAX

class ClapTrap 
{
	public :
		ClapTrap(void);
		ClapTrap(std::string str);
		ClapTrap(ClapTrap const &cpy);
		ClapTrap& operator=(ClapTrap const &cpy);
		~ClapTrap(void);
		
		std::string get_name();
		int	get_attack_damage();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private :
		std::string _name;
		unsigned int _hit_point;
		int _energy_point;
		int _attack_damage;
};

#endif