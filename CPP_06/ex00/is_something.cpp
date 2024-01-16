/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 06:40:20 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/16 07:03:54 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/is_something.hpp"

int is_int(const std::string &value) 
{
	for (std::size_t i = 0; i < value.size(); ++i)
	{
		char c = value[i];
		if ((c == '+' || c == '-') && i == 0)
			continue;
		if (!std::isdigit(c))
			return 0;
	}
	return 1;
}

int is_float(const std::string& value) 
{
	for (std::size_t i = 0; i < value.size(); ++i)
	{
		char c = value[i];
		if ((c == '+' || c == '-') && i == 0)
			continue;
		
		if (c == '.' && i > 0 && std::isdigit(value[i - 1]) && i < value.size() - 1 && std::isdigit(value[i + 1]))
			continue; // Le point est autorisé s'il est entouré de chiffres
	   
		if ((c == 'f' || c == 'F') && i == value.size() - 1)
			return 1;
			
		if (!std::isdigit(c))
			return 0;
	}
	return 0; // value sans F a la fin
}

int is_double(const std::string& value) 
{
	for (std::size_t i = 0; i < value.size(); ++i) 
	{
		char c = value[i];

		if ((c == '+' || c == '-') && i == 0)
			continue;

		if (c == '.' && i > 0 && std::isdigit(value[i - 1]) && i < value.size() - 1 && std::isdigit(value[i + 1]))
			continue; // Le point est autorisé s'il est entouré de chiffres

		if (!std::isdigit(c))
			return 0;
	}
	return 1;
}

int is_special(const std::string &value)//idk
{
	return ( value == "nan" || value == "nanf"
			|| value == "-inff" || value =="+inff"
			||  value == "-inf" || value == "+inf");
}

