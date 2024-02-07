/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:14:19 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/04 03:27:37 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
# define GREEN "\033[32m"
# define RESET "\033[0m"

void    test1() {
	std::cout << std::endl;
	std::cout << GREEN "[Test 1]" RESET << std::endl;
	std::cout << std::endl;
	
	try {
		Bureaucrat tak("takeshi", 15);
		std::cout << "[INFO BUREAUCRAT] " << tak << std::endl;
		tak.grade_increment();
		std::cout << "[INFO BUREAUCRAT] " << tak << std::endl;
		tak.grade_decrement();
		tak.grade_decrement();
		std::cout << "[INFO BUREAUCRAT] " << tak << std::endl;
		for (int i = 0; i < 10; i++)
			tak.grade_increment();
		std::cout << "[INFO BUREAUCRAT] " << tak << std::endl;
 	}
	catch (std::exception & e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
}

int main()
{
	test1();
}