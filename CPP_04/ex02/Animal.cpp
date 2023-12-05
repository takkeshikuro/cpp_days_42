/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:20:04 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/24 06:36:18 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"

Animal::Animal() {
	this->type = "Animal";
	std::cout << "New animal (main constructor called)" << std::endl;
}

Animal::Animal(Animal const &cpy) {
	std::cout << "Animal copy constuctor called." << std::endl;
	type = cpy.type;
}

Animal& Animal::operator=(Animal const &cpy) {
	if (this != &cpy)
		type = cpy.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called." << std::endl;
}

void Animal::makeSound() const {
	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;	
	std::cout << "normal sounddd" << std::endl;
	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;	
	std::cout << std::endl;
}