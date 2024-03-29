/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 02:10:14 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/28 02:42:12 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Ice.hpp"

Ice::Ice() : AMateria() {
	this->type = "ice";
//	std::cout << "[New ICE constructor called] (inherit from AMateria)." << std::endl;
//	std::cout << std::endl;
}

Ice::Ice(Ice const &cpy) : AMateria(cpy) {
//	std::cout << "[Ice copy constructor called]" << std::endl;
//	std::cout << std::endl;
}

Ice &Ice::operator=(Ice const &cpy) {
//	std::cout << "[Ice copy assignment operator called]" << std::endl;
//	std::cout << std::endl;
	if (this != &cpy) {
		AMateria::operator=(cpy);
	}
	return *this;
}

Ice::~Ice() {
//	std::cout << "[Ice destructor called]" << std::endl;
}

AMateria *Ice::clone() const {
	AMateria *clone;
	clone = new Ice();
	if (!clone) {
		std::cerr << "alloc error" << std::endl;
		exit(1);
	}
	return clone;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}