/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:09:54 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/14 04:39:25 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>

class Weapon;
//pas tjr de weapon donc *weapon

class HumanB
{
	public :
		HumanB(std::string name);
		HumanB(std::string name, Weapon *weapon);
		~HumanB(void);
		
		void  attack() const;
		void setWeapon(Weapon &weapon);
	
	private : 
		Weapon *_weapon;
		std::string _name;
};

#endif