/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:20:04 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/23 08:42:05 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"

Animal::Animal() {
    std::cout << "new animal (main constructor called)" << std::endl;
}

Animal::Animal(Animal const &cpy) {
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
	std::cout << "jspppppp" << std::endl;
}