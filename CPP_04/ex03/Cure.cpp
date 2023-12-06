/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 02:25:55 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/06 03:09:06 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Cure.hpp"

Cure::Cure() : AMateria("cure") {
//	std::cout << "New Cure constructor called (inherit from AMateria)." << std::endl;
}

Cure::Cure(Cure const &cpy) : AMateria(cpy) {
//	std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &cpy) {
//	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &cpy) {
		AMateria::operator=(cpy);
	}
	return *this;
}

Cure::~Cure() {
//	std::cout << "destructor called" << std::endl;
}

AMateria *Cure::clone() const {
	AMateria *clone;
	try {
		clone = new Cure();
	}
	catch (const std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
	return clone;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}