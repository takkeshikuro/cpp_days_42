/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:22:54 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/27 06:05:00 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/AMateria.hpp"

AMateria::AMateria() : type("") {
//	std::cout << "[Default constructor AMateria called]" << std::endl;
//	std::cout << std::endl;
}

AMateria::AMateria(std::string const &type) { 
//	std::cout << "[Normal str constructor AMateria called]" << std::endl;
//	std::cout << std::endl;
	this->type = type;
}

AMateria::AMateria(AMateria const &cpy) : type(cpy.type) {
//	std::cout << "[AMateria copy constuctor called]" << std::endl;
//	std::cout << std::endl;
}

AMateria& AMateria::operator=(AMateria const &cpy) {
//	std::cout << "[AMateria copy assignment operator called]" << std::endl;
//	std::cout << std::endl;
	if (this != &cpy)
		type = cpy.type;
	return *this;
}

AMateria::~AMateria() {
//	std::cout << "[AMateria destructor called]" << std::endl;
}

std::string const & AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
    if (type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (type == "cure")
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	else
		std::cout << "Can't use, invalid type!" << std::endl;
}