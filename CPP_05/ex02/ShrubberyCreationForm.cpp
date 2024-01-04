/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:16:39 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/04 05:07:35 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("default_ShrubberyCreationForm", 145, 137), _target("default_target") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	std::cout << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm normal constructor called" << std::endl;
	std::cout << std::endl;
	
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy) 
: AForm(cpy), _target(cpy._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	std::cout << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &cpy) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	std::cout << std::endl;
	if (this != &cpy) {
		this->_target = cpy._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
   
}

void ShrubberyCreationForm::make_action() {
	
}