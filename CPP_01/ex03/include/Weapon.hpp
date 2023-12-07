/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshikuro <keshikuro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:54:15 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/03 14:21:14 by keshikuro        ###   ########.fr       */
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

		const std::string getType(void) const; // attention ->
		//The getType() function returns a const reference to the type string.
		void setType(std::string str);
		
	private :
		std::string _type;
};


#endif
