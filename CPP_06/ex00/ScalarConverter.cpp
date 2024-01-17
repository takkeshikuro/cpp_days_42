/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshikuro <keshikuro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 05:28:41 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/17 17:30:44 by keshikuro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScalarConverter.hpp"
#include "is_something.cpp"


void print_int_convert(const std::string &value)
{
	double i = std::atol(value.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	std::cout << "char : ";
	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	if (i >= INT_MIN && i <= INT_MAX)
		std::cout << "int : " << i << std::endl;
	else
		std::cout << "int : impossible" << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << "" << std::endl;
}

void	print_float_convert(const std::string &value)
{
	float f = std::atof(value.c_str());
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	std::cout << "char : ";
	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	if (i >= INT_MIN && i <= INT_MAX)
		std::cout << "int : " << i << std::endl;
	else
		std::cout << "int : impossible" << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	print_double_convert(const std::string &value)
{
	double d = std::atof(value.c_str());
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	std::cout << "char : ";
	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;;
	
	if (i >= INT_MIN && i <= INT_MAX)
		std::cout << "int : " << i << std::endl; // pb overfloww
	else
		std::cout << "int : impossible" << std::endl;
		
	std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;;
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
}

void print_char_convert(char c)
{
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	
	std::cout << "char : " << c << std::endl;
	std::cout << "int : " << i << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
}

void print_special(const std::string &value)
{
	if (value == "nanf" || value == "nan")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : nanf" << std::endl;
		std::cout << "double : nan" << std::endl;
	}
	else if (value == "inff" || value == "inf")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : inff" << std::endl;
		std::cout << "double : inf" << std::endl;
	}
	else if (value == "+inff" || value == "+inf")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : +inff" << std::endl;
		std::cout << "double : +inf" << std::endl;
	}
	else if (value == "-inff" || value == "-inf")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : -inff" << std::endl;
		std::cout << "double : -inf" << std::endl;
	}
}

short	get_type(const std::string &value)
{
	if (value.size() == 1)
	{
		if (std::isdigit(value[0]))
			return INT;
		else
			return CHAR;
	}
	else if (is_special(value))
		return SPECIAL;
	else
	{
		if (is_float(value))
		 	return FLOAT;
		else if (is_double(value))
			return DOUBLE;
		else if (is_int(value))
			return INT;
		else
			return INVALID;
	}
}

void ScalarConverter::convert(const std::string &value)
{
	if (value.size() == 0)
		throw invalid_input_exeption();
	
	short type = get_type(value);
	switch (type)
	{
		case 1 :
			print_char_convert(value[0]);
			break;
		case 2 :
			print_int_convert(value);
			break;
		case 3 :
			print_float_convert(value);
			break;
		case 4 :
			print_double_convert(value);
			break;
		case 5 :
			print_special(value);
			break;
		case 6 :
			throw invalid_input_exeption();
			break;	
	}
}

const char *ScalarConverter::invalid_input_exeption::what() const throw() {
	return "bad arg";
}
