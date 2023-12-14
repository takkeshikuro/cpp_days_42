/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:54:15 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/14 04:40:52 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

class Weapon
{
	public :
		//Weapon();
		Weapon(std::string str);
		~Weapon(void);

		const std::string& getType(void) const;
		void setType(std::string str);
		
	private :
		std::string _type;
};


#endif
