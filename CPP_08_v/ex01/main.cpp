/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 05:57:09 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/15 04:48:32 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Span.hpp"

int main()
{
	try {
		std::cout << "TEST SIMPLE ADDNUMBER : " << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortest span found : " << sp.shortestSpan() << std::endl;
		std::cout << "longest span found : " << sp.longestSpan() << std::endl;
		sp.display_span();
	}
	catch (const std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
/////////////////////////////////////////////////////////////////////////////////////////
	try {
		std::cout << std::endl << "TEST FULL CONTAINER : " << std::endl;
		Span sp = Span(2);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(4);
	}
	catch (const std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
/////////////////////////////////////////////////////////////////////////////////////////
	try
	{
		std::cout << std::endl << "TEST ADDRANGE (tab): " << std::endl;
		Span sp = Span(20);

		int nb_tab[] = {1,12062,51636,50019,34867,8077,80437,78090,2,55893, \
							31965,439,27150,61614,22963,9864,100000,11288,7622,5069};	
			
		sp.addRange(nb_tab, nb_tab + sizeof(nb_tab) / sizeof(nb_tab[0]));
		std::cout << "shortest span found : " << sp.shortestSpan() << std::endl;
		std::cout << "longest span found : " << sp.longestSpan() << std::endl;
	//	sp.display_span();
	}
	catch (const std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
/////////////////////////////////////////////////////////////////////////////////////////
	try {
		std::cout << std::endl << "TEST ADDRANGE (vector): " << std::endl;
		srand(time(NULL));
		Span sp = Span(100);

		std::vector<int> random_nb;
		for (int i = 0; i < 100; ++i) {
			random_nb.push_back(rand() % 1000 + 1);
		}
		sp.addRange(random_nb.begin(), random_nb.end());
		std::cout << "shortest span found : " << sp.shortestSpan() << std::endl;
		std::cout << "longest span found : " << sp.longestSpan() << std::endl;
	//	sp.display_span();
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
