/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 05:31:41 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/23 06:34:15 by tmorikaw         ###   ########.fr       */
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
		ClapTrap(ClapTrap const &cpy);
		ClapTrap& operator=(ClapTrap const &cpy);
		ClapTrap(std::string str);
		~ClapTrap(void);
		std::string get_name() {return _name;};
		int	get_attack_damage() {return _attack_damage;};
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