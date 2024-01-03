/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:14:19 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/03 02:49:53 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
# define GREEN "\033[32m"
# define RESET "\033[0m"

void    test1() {
	std::cout << std::endl;
	std::cout << GREEN "[Test 1]" RESET << std::endl;
	std::cout << std::endl;
	
	Bureaucrat tak("takeshi", 4);
	std::cout << "[INFO BUREAUCRAT] " << tak << std::endl;

	tak.grade_increment();
	std::cout << "[INFO BUREAUCRAT] " << tak << std::endl;
	
	tak.grade_decrement();
	tak.grade_decrement();
	std::cout << "[INFO BUREAUCRAT] " << tak << std::endl;

	for (int i = 0; i < 10; i++)
		tak.grade_increment();

	std::cout << "[INFO BUREAUCRAT] " << tak << std::endl;
	return ;
}

int main()
{
	test1();
}