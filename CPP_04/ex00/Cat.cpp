/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:33:35 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/23 08:45:24 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "new cat!! constructor called." << std::endl;
}

Cat::Cat(Cat const &cpy) {
	(void)cpy;
}

Cat &Cat::operator=(Cat const &cpy) {
	(void)cpy;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "moewwwwwww" << std::endl;
}