/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:33:35 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/24 06:56:46 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Cat.hpp"
#include "include/Brain.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
	std::cout << "New Cat constructor called (inherit from Animal)." << std::endl;
	this->brain = new Brain();
	if (!this->brain) {
		std::cerr << "alloc error" << std::endl;
		exit(1);
	}
}

Cat::Cat(Cat const &cpy) : Animal(cpy), brain(NULL) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*cpy.brain);
	if (!this->brain) {
		std::cerr << "alloc error" << std::endl;
		exit(1);
	}
}

Cat &Cat::operator=(Cat const &cpy) {
    std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &cpy) {
		Animal::operator=(cpy);
		delete brain;
		this->brain = new Brain(*cpy.brain);
		if (!this->brain) {
			std::cerr << "alloc error" << std::endl;
			exit(1);
		}
	}
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;	
	std::cout << "waaaaaaaaf" << std::endl;
	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;	
	std::cout << std::endl;
}

void Cat::SetIdea(std::string idea, int i) {
	brain->SetIdea(idea, i);
}

void Cat::DisplayIdea() const {
	for (int i = 0; i < 100; i++) {
		const std::string &idea = brain->GetIdea(i);
		if (!idea.empty())
			std::cout << "Cat's idea : " << idea << std::endl;
		if (i == 99)
			std::cout << "END OF TAB" << std::endl;
	}
}