/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:08:59 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 07:41:37 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/AAnimal.hpp"

AAnimal::AAnimal() {
	this->type = "AAnimal";
	std::cout << "[New AAnimal main constructor called]" << std::endl;
	std::cout << std::endl;
}

AAnimal::AAnimal(AAnimal const &cpy) {
	std::cout << "[AAnimal copy constuctor called]" << std::endl;
	std::cout << std::endl;
	type = cpy.type;
}

AAnimal& AAnimal::operator=(AAnimal const &cpy) {
	std::cout << "[AAnimal copy operator called]" << std::endl;
	std::cout << std::endl;
	if (this != &cpy)
		type = cpy.type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "[AAnimal destructor called.]" << std::endl;
}

void AAnimal::makeSound() const {
	std::cout << "------------------------------" << std::endl;	
	std::cout << "| normal sounddd (AAnimal)" << std::endl;
	std::cout << "------------------------------" << std::endl;	
	std::cout << std::endl;
}