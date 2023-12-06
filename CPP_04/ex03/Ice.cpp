/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 02:10:14 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/06 03:09:25 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Ice.hpp"

Ice::Ice() : AMateria() {
	this->type = "ice";
//	std::cout << "New ICE constructor called (inherit from AMateria)." << std::endl;
}

Ice::Ice(Ice const &cpy) : AMateria(cpy) {
//	std::cout << "ICE copy constructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &cpy) {
//	std::cout << "ICE copy assignment operator called" << std::endl;
	if (this != &cpy) {
		AMateria::operator=(cpy);
	}
	return *this;
}

Ice::~Ice() {
//	std::cout << "destructor called" << std::endl;
}

AMateria *Ice::clone() const {
	AMateria *clone;
	try {
		clone = new Ice();
	}
	catch (const std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
	return clone;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}