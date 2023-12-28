/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:06:59 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/14 04:30:48 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>

class Weapon;
//detient forcement une weapon donc &weapon

class HumanA
{
	public :
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void  attack() const;
	
	private : 
		Weapon &_weapon;
		std::string _name;
};

#endif