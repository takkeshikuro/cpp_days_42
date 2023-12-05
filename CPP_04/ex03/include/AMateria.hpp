/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:20:57 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/05 06:29:37 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include <cstdlib> //exit
#include <sstream>
#include "Character.hpp"

class ICharacter;

class AMateria
{

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria::AMateria(AMateria const &cpy);
		AMateria& AMateria::operator=(AMateria const &cpy);
		~AMateria();
		std::string const & getType() const {return type;}; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);

	protected:
		std::string type;
};

#endif