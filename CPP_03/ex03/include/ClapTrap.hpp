/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:54:59 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/23 07:55:06 by tmorikaw         ###   ########.fr       */
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
		
		std::string get_name() const {return _name;};
		int	get_attack_damage() const {return _attack_damage;};
		int get_energy_point() const {return _energy_point;};
		int get_hit_point() const {return _hit_point;};
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
	protected :
		std::string _name;
		unsigned int _hit_point;
		int _energy_point;
		int _attack_damage;
};

#endif