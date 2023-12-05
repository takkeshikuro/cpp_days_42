/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 04:57:04 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/24 05:16:18 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "New WrongCat constructor called (inherit from WrongAnimal)" << std::endl;
}

WrongCat::WrongCat(WrongCat const &cpy) : WrongAnimal(cpy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &cpy) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &cpy)
		WrongAnimal::operator=(cpy);
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called." << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
	std::cout << "Wrong cat moewwwwwww" << std::endl;
	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;	
	std::cout << std::endl;
}