/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:21:09 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/10 06:07:27 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

# define GREEN "\033[32m"
# define RESET "\033[0m"

void    test1() {
    std::cout << std::endl;
	std::cout << GREEN "[Test 1] (sign and exec with good grade)" RESET << std::endl;
	std::cout << std::endl;
	
	try {
		Bureaucrat tak("takeshi", 4);
		ShrubberyCreationForm s_form("s_target");
		std::cout << tak << s_form << std::endl;
		tak.signForm(s_form);
		std::cout << std::endl << s_form << std::endl;
		tak.executeForm(s_form);
	}
	catch (std::exception & e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
}

void    test2() {
    std::cout << std::endl;
	std::cout << GREEN "[Test 2] (try to exec whithout requiered grad)" RESET << std::endl;
	std::cout << std::endl;

	try {     
		Bureaucrat tak("takeshi", 70); 
		RobotomyRequestForm r_form("r_target");
		
		std::cout << tak << r_form << std::endl;
		tak.signForm(r_form);
		std::cout << std::endl << r_form << std::endl;
		tak.executeForm(r_form);
	}
	catch (std::exception & e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
}

void    test3() {
    std::cout << std::endl;
	std::cout << GREEN "[Test 3] (try to exec unsigned form)" RESET << std::endl;
	std::cout << std::endl;

	try {     
		Bureaucrat tak("takeshi", 30); 
		PresidentialPardonForm p_form("p_target");
		std::cout << tak << p_form << std::endl;
		tak.signForm(p_form);
		std::cout << std::endl << p_form << std::endl;
		tak.executeForm(p_form);
	}
	catch (std::exception & e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
}

int main()
{
	test1();
    test2();
	test3();
}