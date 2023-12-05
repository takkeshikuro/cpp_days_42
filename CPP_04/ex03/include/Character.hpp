/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:22:19 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/05 06:22:02 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include <cstdlib> //exit
#include <sstream>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public :
   		virtual ~ICharacter() {}
		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;		
};

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string const &name);
		Character(Character const &cpy);
		Character& operator=(Character const &cpy);
		~Character();
		
		std::string const &getName() const {return name;};
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string name;
		AMateria* inventory[4]; // Inventaire de 4 items
};

#endif