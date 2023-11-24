/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:33:35 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/24 05:12:33 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	std::cout << "new cat constructor called (inherit from Animal)." << std::endl;
}

Cat::Cat(Cat const &cpy) : Animal(cpy) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &cpy) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &cpy)
		Animal::operator=(cpy);
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;	
	std::cout << "moewwwwwww" << std::endl;
	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;	
	std::cout << std::endl;
}