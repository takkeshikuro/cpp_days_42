/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:20:04 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 07:33:11 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"

Animal::Animal() {
	this->type = "Animal";
	std::cout << "[New animal constructor called]" << std::endl;
	std::cout << std::endl;
}

Animal::Animal(Animal const &cpy) {
	std::cout << "[Animal copy constructor called]" << std::endl;
	std::cout << std::endl;
	type = cpy.type;
}

Animal& Animal::operator=(Animal const &cpy) {
	std::cout << "[Animal copy assignment operator called]" << std::endl;
	std::cout << std::endl;
	if (this != &cpy)
		type = cpy.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "[Animal destructor called.]" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "------------------------------" << std::endl;	
	std::cout << "| normal sounddd" << std::endl;
	std::cout << "------------------------------" << std::endl;	
	std::cout << std::endl;
}