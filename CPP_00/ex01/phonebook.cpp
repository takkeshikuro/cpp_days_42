/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:34:42 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/20 08:42:01 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phonebook.hpp"

std::string	print_ask(std::string line, std::string str)
{
	int ok = 1;

	while (ok)
	{
		std::cout << str;
		std::getline (std::cin,line);
		if (line[0] != '\0')
			ok = 0;
		else
			std::cout << "You must write something.." << std::endl;
	}
	return (line);
}

void Phonebook::add_contact(Contact &contacts)
{
	std::string line;

	contacts._first_name = print_ask(line, "First name : ");
	contacts._last_name = print_ask(line, "Last name : ");
	contacts._nickname = print_ask(line, "Nickname : ");
	contacts._phone_nb = print_ask(line, "Phone number : ");
	contacts._dark_secret = print_ask(line, "Darkest secret : ");
	return ;
}

void print_tab_line(Contact &contacts)
{
	int i;
	std::string str_cut;

	std::cout << "|         " << contacts.index;
	if (contacts._first_name.length() <= 10)
	{
		i = 0;
		std::cout << "|";
		while (++i <= 10 - (int)contacts._first_name.length())
			std::cout << " ";
		std::cout << contacts._first_name;
	}
	else
	{
		std::cout << "|";
		str_cut = contacts._first_name.substr(0, 9);
		std::cout << str_cut << ".";
	}
	if (contacts._last_name.length() <= 10)
	{
		i = 0;
		std::cout << "|";
		while (++i <= 10 - (int)contacts._last_name.length())
			std::cout << " ";
		std::cout << contacts._last_name;
	}
	else
	{
		std::cout << "|";
		str_cut = contacts._last_name.substr(0, 9);
		std::cout << str_cut << ".";
	}
	if (contacts._nickname.length() <= 10)
	{
		i = 0;
		std::cout << "|";
		while (++i <= 10 - (int)contacts._nickname.length())
			std::cout << " ";
		std::cout << contacts._nickname << "|" << std::endl;
	}
	else
	{
		std::cout << "|";
		str_cut = contacts._nickname.substr(0, 9);
		std::cout << str_cut << ".|" << std::endl;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
}

void	print_index_found(Contact &contacts)
{
	std::cout << "First name : " << contacts._first_name << std::endl;
	std::cout << "Last name : " << contacts._last_name << std::endl;
	std::cout << "Nickname : " << contacts._nickname << std::endl;
	std::cout << "Phone number : " << contacts._phone_nb << std::endl;
	std::cout << "Darkest secret : " << contacts._dark_secret << std::endl;
	return ;
}

void Phonebook::search_contact(Phonebook &Phonebook) const
{
	std::string str_index;
	int			int_index;
	int 		ctc = -1;

	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     index|  fst name|  lst name|  nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	while (Phonebook.contacts[++ctc].index > 0)
		print_tab_line(Phonebook.contacts[ctc]);
	while (42)
	{
		std::cout << "which contact ?" << std::endl << "(index)>";
		std::getline (std::cin,str_index);
		if (!only_digit(str_index) && str_index.length() == 1)
		{
			int_index = std::stoi(str_index);
			if ((int_index > 0 && int_index < 9) && Phonebook.contacts[int_index - 1].index != 0)
				return print_index_found(Phonebook.contacts[int_index - 1]);
			else
				std::cout << std::endl << "No contact at this index." << std::endl << std::endl;
		}
		else	
			std::cout  << std::endl << "wrong type of index." << std::endl << std::endl;
	}
	return ;
}

int main(void) 
{
	Phonebook Phonebook;
	std::string	command;
	int i = -1;

	init_index(Phonebook);
	while (42)
	{
		std::cout << "command accepted : ADD/SEARCH/EXIT" << std::endl;
		std::cout << ">";
		std::getline (std::cin,command);
		if (command == "ADD" && command.length() == 3)
		{
			i += 1;
			if (i == 8)
				i = 0;
			Phonebook.contacts[i].index = i + 1;
			Phonebook.add_contact(Phonebook.contacts[i]);
		}
		else if (command == "SEARCH" && command.length() == 6)
			Phonebook.search_contact(Phonebook);
		else if (command == "EXIT" && command.length() == 4)
			break ;
	}
	return 0;
}
