/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshikuro <keshikuro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 05:28:41 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/17 16:07:53 by keshikuro        ###   ########.fr       */
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
		std::cout << "'" << c << "'\n";
	else
		std::cout << "Non displayable\n";
//	if (check overflow)
	std::cout << "int : " << i << "\n";
	std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f\n";
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << "\n";
}

void	print_float_convert(const std::string &value)
{
	float f = std::atof(value.c_str());
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	std::cout << "char : ";
	if (std::isprint(c))
		std::cout << "'" << c << "'\n";
	else
		std::cout << "Non displayable\n";
//	if (check overflow)
	std::cout << "int : " << i << "\n";
	std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f\n";
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << "\n";
}

void	print_double_convert(const std::string &value)
{
	double d = std::atof(value.c_str());
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(f);

	std::cout << "char : ";
	if (std::isprint(c))
		std::cout << "'" << c << "'\n";
	else
		std::cout << "Non displayable\n";
//	if (check overflow)
	std::cout << "int : " << i << "\n";
	std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f\n";
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << "\n";
}

void print_char(char c)
{
	std::cout << c << std::endl;
}

void print_special(const std::string &value)
{
	if (value == "nanf" || value == "nan")
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : nanf\n";
		std::cout << "double : nan\n";
	}
	else if (value == "inff" || value == "inf")
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : inff\n";
		std::cout << "double : inf\n";
	}
	else if (value == "+inff" || value == "+inf")
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : +inff\n";
		std::cout << "double : +inf\n";
	}
	else if (value == "-inff" || value == "-inf")
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : -inff\n";
		std::cout << "double : -inf\n";
	}
}

void ScalarConverter::convert(const std::string &value)
{
	if (value.size() == 0)
		throw invalid_input_exeption();

	else if (value.size() == 1)
	{
		if (std::isdigit(value[0]))
			print_int_convert(value);
		else
			print_char(value[0]);
	}
	else if (is_special(value))
		print_special(value);
	else
	{
		if (is_float(value))
		 	print_float_convert(value);
		else if (is_double(value))
			print_float_convert(value);
		else if (is_int(value))
			print_int_convert(value);
		else
			throw invalid_input_exeption();
	}
}


const char *ScalarConverter::invalid_input_exeption::what() const throw() {
	return "bad arg ";
}


