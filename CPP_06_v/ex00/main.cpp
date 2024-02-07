/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshikuro <keshikuro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 05:31:22 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/17 17:10:26 by keshikuro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScalarConverter.hpp"

int main(int ac, char **av) 
{
	if (ac == 2)
	{
		try {
			ScalarConverter::convert(av[1]);
		}
		catch (std::exception & e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}
	else
		std::cout << "Error: need one argument." << std::endl;
}