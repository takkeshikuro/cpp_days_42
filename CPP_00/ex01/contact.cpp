/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 03:17:12 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/02 06:06:35 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Phonebook.hpp"

std::string	print_ask(std::string line, std::string str)
{
	int ok = 1;

	while (ok)
	{
		std::cout << str;
		if (!std::getline(std::cin,line))
            error(2);
		if (!noblank(line))
			ok = 0;
		else
			std::cout << "You must write something or something correct." << std::endl;
	}
	return (line);
}

void Contact::add_contact()
{
	std::string line;

	_first_name = print_ask(line, "First name : ");
	_last_name = print_ask(line, "Last name : ");
	_nickname = print_ask(line, "Nickname : ");
	_phone_nb = print_ask(line, "Phone number : ");
	_dark_secret = print_ask(line, "Darkest secret : ");
	return ;
}

void Contact::print_tab_line()
{
	int i;
	std::string str_cut;

	std::cout << "|         " << index;
	if (_first_name.length() <= 10)
	{
		i = 0;
		std::cout << "|";
		while (++i <= 10 - (int)_first_name.length())
			std::cout << " ";
		std::cout << _first_name;
	}
	else
	{
		std::cout << "|";
		str_cut = _first_name.substr(0, 9);
		std::cout << str_cut << ".";
	}
	if (_last_name.length() <= 10)
	{
		i = 0;
		std::cout << "|";
		while (++i <= 10 - (int)_last_name.length())
			std::cout << " ";
		std::cout << _last_name;
	}
	else
	{
		std::cout << "|";
		str_cut = _last_name.substr(0, 9);
		std::cout << str_cut << ".";
	}
	if (_nickname.length() <= 10)
	{
		i = 0;
		std::cout << "|";
		while (++i <= 10 - (int)_nickname.length())
			std::cout << " ";
		std::cout << _nickname << "|" << std::endl;
	}
	else
	{
		std::cout << "|";
		str_cut = _nickname.substr(0, 9);
		std::cout << str_cut << ".|" << std::endl;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
}

void	Contact::print_index_found()
{
	std::cout << "First name : " << _first_name << std::endl;
	std::cout << "Last name : " << _last_name << std::endl;
	std::cout << "Nickname : " << _nickname << std::endl;
	std::cout << "Phone number : " << _phone_nb << std::endl;
	std::cout << "Darkest secret : " << _dark_secret << std::endl;
	return ;
}
