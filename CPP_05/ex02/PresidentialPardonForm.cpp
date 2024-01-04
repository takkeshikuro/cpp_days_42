/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:33:57 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/04 05:06:52 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
:  AForm("default_PresidentialPardonForm", 25, 5), _target("default_target") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	std::cout << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm normal constructor called" << std::endl;
	std::cout << std::endl;
	
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy) 
: AForm(cpy), _target(cpy._target) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	std::cout << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &cpy) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	std::cout << std::endl;
	if (this != &cpy) {
		this->_target = cpy._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
   
}

void PresidentialPardonForm::make_action() {
	
}