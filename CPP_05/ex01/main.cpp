/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:21:09 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/04 01:54:12 by tmorikaw         ###   ########.fr       */
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
	
	Bureaucrat tak("takeshi", 4);
	//create new bureaucrat
	

    Form form_ok("new_file", 10, 1);
	//create new form

	std::cout << form_ok << std::endl;
    //display form's statut and data
	
	form_ok.beSigned(tak);
	std::cout << std::endl;
	//try to sign form by tak
	
    
	std::cout << form_ok << std::endl;
	std::cout << std::endl;
    //display new statue and data
}

void test2() {
    std::cout << std::endl;
	std::cout << GREEN "[Test 2]" RESET << std::endl;
	std::cout << std::endl;
	
	Bureaucrat tak("takeshi", 4);
	std::cout << "[INFO BUREAUCRAT] " << tak << std::endl;
	//create new bureaucrat
	
	Form form_ko("impossible_file", 150, 1);
	std::cout << form_ko << std::endl;
	//create new form
	
	form_ko.beSigned(tak);
	//try
	
	tak.grade_increment();
	tak.grade_increment();
	//get tak new level
	
	std::cout << "[INFO BUREAUCRAT] " << tak << std::endl;
	
	form_ko.beSigned(tak);
	//try again

	std::cout << form_ko << std::endl;
	std::cout << std::endl;

}

int main()
{
	test1();
    test2();
}