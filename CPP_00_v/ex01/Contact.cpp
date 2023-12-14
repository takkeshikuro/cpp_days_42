/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 03:17:12 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/07 03:20:09 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Phonebook.hpp"

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

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

void get_one_line(std::string var, int ok)
{
	std::string str_cut;
	std::string rm_tab = if_tab(var);

	if (var.length() <= 10) {
		std::cout << "|" << std::setfill (' ') << std::setw (10);
		std::cout << rm_tab;
	}
	else {
		str_cut = rm_tab.substr(0, 9);
		std::cout << "|" << str_cut << ".";
	}
	if (ok)
		std::cout << "|" << std::endl;
	return ;
}

void Contact::print_tab_line()
{
	std::cout << "|";
	std::cout << std::setfill (' ') << std::setw (10) << index;
	get_one_line(_first_name, 0);
	get_one_line(_last_name, 0);
	get_one_line(_nickname, 1);
	std::cout << "|" << std::setfill ('-') << std::setw (44) << "|" << std::endl;
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
