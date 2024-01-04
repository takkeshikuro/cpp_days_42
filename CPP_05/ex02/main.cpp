/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:21:09 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/04 03:40:28 by tmorikaw         ###   ########.fr       */
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
	
	try {
			Bureaucrat tak("takeshi", 4);
		//create new bureaucrat

		
	}
	catch (std::exception & e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
}

int main()
{
	test1();
 ///   test2();
}