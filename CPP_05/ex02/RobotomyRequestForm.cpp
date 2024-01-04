/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:30:25 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/04 05:07:20 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
:  AForm("default_RobotomyRequestForm", 72, 45), _target("default_target") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	std::cout << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
:   AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm normal constructor called" << std::endl;
	std::cout << std::endl;
	
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy) 
:  AForm(cpy), _target(cpy._target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	std::cout << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &cpy) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	std::cout << std::endl;
	if (this != &cpy) {
		this->_target = cpy._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
   
}

void RobotomyRequestForm::make_action() {
	
}