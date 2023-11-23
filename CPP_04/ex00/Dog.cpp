/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:37:13 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/23 08:45:33 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Dog.hpp"

Dog::Dog() {
    type = "dog";
	std::cout << "new Dog!! constructor called." << std::endl;
}

Dog::Dog(Dog const &cpy) {
	(void)cpy;
}

Dog &Dog::operator=(Dog const &cpy) {
    (void)cpy;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const {
	std::cout << "waaaaaaaaf" << std::endl;
}