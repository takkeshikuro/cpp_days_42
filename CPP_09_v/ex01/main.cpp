/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:10:22 by keshikuro         #+#    #+#             */
/*   Updated: 2024/02/20 05:02:43 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/RPN.hpp"

int main(int ac, char **av)
{
	try {
		if (ac == 2) {
			std::string input = av[1];
			double result = ope_rpn(input);
			std::cout << "result is " << result << std::endl;
		}
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

/*$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
$>*/
