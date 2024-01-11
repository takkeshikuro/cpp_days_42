/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 06:34:01 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/11 02:44:39 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &cpy) {
	*this = cpy;
}

Intern & Intern::operator=(Intern const &cpy) {
	(void)cpy;
	return *this;
}

Intern::~Intern() {}

///////////////////////////////////////////////////////////////

const char *Intern::BadFormNameException::what() const throw() {
		return "Bad form type/name. (exeption)";
}

int find_good_case(std::string form_name)
{
	std::string forms[3] = 
	{
		"shrubbery creation", 
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++) 
	{
		if (forms[i] == form_name)
			return i + 1;
	}
	return 0;
}

AForm * Intern::makeForm(std::string form_name, std::string target)
{
	AForm *form_created = NULL;

	switch (find_good_case(form_name))
	{
		case 1 :
				form_created = new ShrubberyCreationForm(target);
				break ;
		case 2 :
				form_created = new RobotomyRequestForm(target);
				break ;
		case 3 :
				form_created = new PresidentialPardonForm(target);
				break ;
		default :
				std::cout << "Form type not found in database." << std::endl;
				throw BadFormNameException();
	}
	std::cout << "+ Intern creates " << form_created->getName() << "'s form. +" << std::endl;
	return form_created;
}
