/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 05:28:41 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/16 07:05:50 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScalarConverter.hpp"
#include "is_something.cpp"


void print_int(int i)
{
	std::cout << i << std::endl;
}

void print_char(char c)
{
	std::cout << c << std::endl;
}

void print_special(const std::string &value)
{}

void ScalarConverter::convert(const std::string &value)
{
	if (value.size() == 0)
		throw invalid_input_exeption();
	else if (value.size() == 1)
	{
		if (std::isdigit(value[0]))
		{
			int i = std::atoi(value.c_str());
			print_int(i);
		}
		else
			print_char(value[0]);
	}
	else if (is_special(value))
		print_special(value);
	else
	{
		if (is_float(value))
		{}
		else if (is_double(value))
		{}
		else if (is_int(value))
		{}
		else
			throw invalid_input_exeption();
	}
}


const char *ScalarConverter::invalid_input_exeption::what() const throw() {
	return "ervlkefnv";
}


