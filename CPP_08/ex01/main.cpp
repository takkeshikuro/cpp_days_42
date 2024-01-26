/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 05:57:09 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/26 02:59:11 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Span.hpp"

int main()
{
	try {
		std::cout << "TEST WITH 5 VALUE :" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	//	sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try {
		std::cout << std::endl << "TEST WITH 10000 VALUE :" << std::endl;
		Span sp = Span(10000);
		for (int i = 0; i < 10000; ++i) {
			sp.addNumber(i);
		};
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	return 0;
}

/*
sould print :
$> ./ex01
2
14
$>
*/
