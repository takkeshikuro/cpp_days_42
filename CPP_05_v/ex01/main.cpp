/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:21:09 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/02 02:08:02 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"
# define GREEN "\033[32m"
# define RESET "\033[0m"

void    test1() {
    std::cout << std::endl;
	std::cout << GREEN "[Test 1]" RESET << std::endl;
	std::cout << std::endl;
	try 
	{
		Bureaucrat tak("takeshi", 1);
		//create new bureaucrat

		Form form_ok("new_file", 10, 1);
		//create new form

		std::cout << form_ok << std::endl;
		//display form's statut and data
		
		tak.signForm(form_ok);
		std::cout << std::endl;
		//try to sign form by tak

		std::cout << form_ok << std::endl;
		std::cout << std::endl;
		//display new statue and data
	}
	catch (std::exception & e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
}


void test2() {
    std::cout << std::endl;
	std::cout << GREEN "[Test 2]" RESET << std::endl;
	std::cout << std::endl;
	
	try {
		Bureaucrat tak("takeshi", 4);
		std::cout << "[INFO BUREAUCRAT] " << tak << std::endl;
		//create new bureaucrat
		
		Form form_ko("impossible_file", 2, 1);
		std::cout << form_ko << std::endl;
		//create new form
		
		tak.signForm(form_ko);
		std::cout << std::endl;
		
		//try
		std::cout << form_ko << std::endl;
		std::cout << std::endl;
		
		tak.grade_increment();
		tak.grade_increment();
		std::cout << "[INFO BUREAUCRAT] " << tak << std::endl;
		//get tak new level
		
		tak.signForm(form_ko);
		std::cout << std::endl;
		//try again

		std::cout << form_ko << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
}

int main()
{
	test1();
    test2();
}