/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:22:54 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/06 03:08:27 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/AMateria.hpp"

AMateria::AMateria() : type("") {
//	std::cout << "default constructor AMateria called" << std::endl;
}

AMateria::AMateria(std::string const &type) { 
	this->type = type;
//	std::cout << "default constructor AMateria called" << std::endl;
}

AMateria::AMateria(AMateria const &cpy) : type(cpy.type) {
//	std::cout << "AMateria copy constuctor called." << std::endl;
}

AMateria& AMateria::operator=(AMateria const &cpy) {
	if (this != &cpy)
		type = cpy.type;
	return *this;
}

AMateria::~AMateria() {
//	std::cout << "destructor called" << std::endl;
}

void AMateria::use(ICharacter& target) {
    if (type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (type == "cure")
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	else
		std::cout << "Can't use, invalid type!" << std::endl;
}