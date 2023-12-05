/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:37:13 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/05 01:11:27 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Dog.hpp"

Dog::Dog() : AAnimal() {
    this->type = "Dog";
	std::cout << "New Dog constructor called (inherit from AAnimal)." << std::endl;
	this->brain = new Brain();
	if (!this->brain) {
		std::cerr << "alloc error" << std::endl;
		exit(1);
	}
}

Dog::Dog(Dog const &cpy) : AAnimal(cpy), brain(NULL) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*cpy.brain);
	if (!this->brain) {
		std::cerr << "alloc error" << std::endl;
		exit(1);
	}
}

Dog &Dog::operator=(Dog const &cpy) {
    std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &cpy) {
		AAnimal::operator=(cpy);
		delete brain;
		this->brain = new Brain(*cpy.brain);
		if (!this->brain) {
			std::cerr << "alloc error" << std::endl;
			exit(1);
		}
	}
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const {
	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;	
	std::cout << "waaaaaaaaf" << std::endl;
	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;	
	std::cout << std::endl;
}

void Dog::SetIdea(std::string idea, int i) {
	brain->SetIdea(idea, i);
}

void Dog::DisplayIdea() const {
	for (int i = 0; i < 100; i++) {
		const std::string &idea = brain->GetIdea(i);
		if (!idea.empty())
			std::cout << "Dog's idea : " << idea << std::endl;
	}
}