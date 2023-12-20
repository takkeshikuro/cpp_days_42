/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:37:13 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 07:31:23 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
	std::cout << "[New Dog constructor called] (inherit from Animal)." << std::endl;
	std::cout << std::endl;
}

Dog::Dog(Dog const &cpy) : Animal(cpy) {
	std::cout << "[Dog copy constructor called]" << std::endl;
	std::cout << std::endl;
}

Dog &Dog::operator=(Dog const &cpy) {
    std::cout << "[Dog copy assignment operator called]" << std::endl;
	std::cout << std::endl;
	if (this != &cpy)
		Animal::operator=(cpy);
	return *this;
}

Dog::~Dog() {
	std::cout << "[Dog destructor called.]" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "------------------------------" << std::endl;	
	std::cout << "| waaaaaaaaf" << std::endl;
	std::cout << "------------------------------" << std::endl;	
	std::cout << std::endl;
}