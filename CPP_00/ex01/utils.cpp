/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:40:33 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/20 08:41:46 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phonebook.hpp"

int only_digit(const std::string& str)
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

void init_index(Phonebook &Phonebook)
{
	int i = 0;

	while (i < 8)
	{
		Phonebook.contacts[i].index = 0;
		i++;
	}
	return ;
}