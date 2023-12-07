/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:40:33 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/07 01:07:45 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Phonebook.hpp"

void	error(int ok)
{
	if (ok == 1)
		std::cout << std::endl << "error during the main process." << std::endl;
	else if (ok == 2)
		std::cout << std::endl << "error while retrieving user data." << std::endl;
	else if (ok == 3)
		std::cout << std::endl << "error while retrieving index search." << std::endl;
	std::exit(1);
}

std::string if_tab(const std::string s)
{
	std::string ok = s;

	for (std::size_t i = 0; i < s.length(); i++) {
		if (std::isspace(s[i]))
			ok[i] = ' ';
	}
	return ok;
}

int noblank(std::string line)
{
	int i = 0;
	
	if (line[0] == '\0')
		return 1;
	while (std::isspace(line[i]))
	{
		if (!line[i + 1])
			return 1;
		i++;
	}
	return 0;
}

int	fake_atoi(const std::string& str) 
{
	int ok;
	
	std::istringstream iss(str);
	iss >> ok;
	if (iss.fail())
		return -1;
	return ok;
}

int Phonebook::only_digit(const std::string& str)
{
	int i = 0;

	if (!str[i])
		return 1;
	while (str[i])
	{
		if (!std::isdigit(str[i]) || str[0] == '-')
		{
			std::cout << "doesnt digit found" << std::endl;
			return 1;
		}
		i++;
	}
	return 0;
}

