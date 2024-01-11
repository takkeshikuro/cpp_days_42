/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:33:57 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/11 02:16:29 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
:  AForm("default_PresidentialPardonForm", 25, 5), _target("default_target") 
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), _target(target) 
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy) 
: AForm(cpy), _target(cpy._target) 
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &cpy) 
{
	if (this != &cpy) {
		this->_target = cpy._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::make_action() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return ;
}
