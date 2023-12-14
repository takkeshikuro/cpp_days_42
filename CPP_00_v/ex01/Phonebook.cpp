/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:34:42 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/07 03:23:20 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Phonebook.hpp"

Phonebook::Phonebook()
{
	std::cout << "Welcom to your phonebook" << std::endl << std::endl;
	return ;
}

Phonebook::~Phonebook()
{
	std::cout  << std::endl << "goodbye." << std::endl;
	return ;
}

void Phonebook::search_contact()
{
	std::string str_index;
	int			int_index;
	int 		ctc = -1;

	std::cout << "|" << std::setfill ('-') << std::setw (44) << "|" << std::endl;
	std::cout << "|     index|  fst name|  lst name|  nickname|" << std::endl;
	std::cout << "|" << std::setfill ('-') << std::setw (44) << "|" << std::endl;
	
	while (ctc < 8 && contacts[++ctc].index > 0)
		contacts[ctc].print_tab_line();
	
	while (42)
	{
		if (ctc == 0) {
			std::cout << "no contact yet." << std::endl;
			return ;
		}
		std::cout << "which contact ?" << std::endl << "(index)>";
		if (!std::getline(std::cin,str_index))
			error(3);
		if (!only_digit(str_index) && str_index.length() == 1) {
			int_index = fake_atoi(str_index);
			if ((int_index > 0 && int_index < 9) && contacts[int_index - 1].index != 0)
				return contacts[int_index - 1].print_index_found();
			else
				std::cout << std::endl << "No contact at this index." << std::endl << std::endl;
		}
		else	
			std::cout  << std::endl << "wrong type of index." << std::endl << std::endl;
	}
	return ;
}

void Phonebook::init_index(void)
{
	int i = 0;

	while (i < 8)
	{
		contacts[i].index = 0;
		i++;
	}
	return ;
}

void	Phonebook::go_phonebook(void) 
{
	std::string	command;
	int i = -1;

	init_index();
	while (42)
	{
		std::cout << std::endl << "command accepted : ADD/SEARCH/EXIT" << std::endl;
		std::cout << ">";
		if (!std::getline(std::cin,command))
			error(1);
		if (command == "ADD" && command.length() == 3)
		{
			i += 1;
			if (i == 8)
				i = 0;
			contacts[i].index = i + 1;
			contacts[i].add_contact();
		}
		else if (command == "SEARCH" && command.length() == 6)
			search_contact();
		else if (command == "EXIT" && command.length() == 4)
			break ;
	}

}

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 1)
	{
		Phonebook Phonebook;
		Phonebook.go_phonebook();
		return 0;
	}
}
