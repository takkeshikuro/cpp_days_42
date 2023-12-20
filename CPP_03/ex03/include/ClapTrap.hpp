/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:54:59 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 02:46:01 by tmorikaw         ###   ########.fr       */
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
		
		std::string get_name() const;
		int	get_attack_damage() const;
		int get_energy_point() const;
		int get_hit_point() const;
		
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