/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 04:53:59 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/27 04:30:30 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    this->type = "WrongAnimal";
	std::cout << "[New WrongAnimal main constructor called]" << std::endl;
	std::cout << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &cpy) {
	std::cout << "[WrongAnimal copy constructor called]" << std::endl;
	std::cout << std::endl;

	type = cpy.type;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &cpy) {
	std::cout << "[WrongAnimal copy assignment operator called]" << std::endl;
	std::cout << std::endl;

	if (this != &cpy)
		type = cpy.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal destructor called.]" << std::endl;
}
std::string WrongAnimal::getType() const {
	return type;
}


void WrongAnimal::makeSound() const {
    std::cout << "------------------------------" << std::endl;	
	std::cout << "| Wrong animal sounddd" << std::endl;
	std::cout << "------------------------------" << std::endl;	
	std::cout << std::endl;
}