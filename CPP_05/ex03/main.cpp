/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:21:09 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/11 02:42:32 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/Intern.hpp"

# define GREEN "\033[32m"
# define RESET "\033[0m"


void test1(const std::string &form_name, const std::string &target)
{
	std::cout << std::endl;
	std::cout << GREEN "[Test] " << form_name << RESET << std::endl;
	std::cout << std::endl;

	
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm(form_name, target);
		
		Bureaucrat boss("takeshi", 1);
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
	}
	catch (std::exception & e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
}

int main()
{
	test1("shrubbery creation", "target_S");
	std::cout << std::endl;
	test1("robotomy request", "target_R");
	std::cout << std::endl;
	test1("presidential pardon", "target_P");
	std::cout << std::endl;
	test1("error test request", "target_error_test");
}