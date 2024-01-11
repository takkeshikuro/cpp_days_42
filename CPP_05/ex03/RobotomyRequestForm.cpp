/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:30:25 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/11 02:16:25 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
:  AForm("default_RobotomyRequestForm", 72, 45), _target("default_target") 
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
:   AForm("RobotomyRequestForm", 72, 45), _target(target) 
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy) 
:  AForm(cpy), _target(cpy._target) 
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &cpy) 
{
	if (this != &cpy) {
		this->_target = cpy._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::make_action() const
{
	std::srand(std::time(0));
	std::cout << "*drilling noises*" << std::endl;

	int randomValue = std::rand() % 2;
	if (randomValue == 0) 
		std::cout << _target << " has been robotomized." << std::endl;
	else 
		std::cout << "robotomy failed..." << std::endl;
	return ;
}
