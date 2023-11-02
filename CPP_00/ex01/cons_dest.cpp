/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cons_dest.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:35:02 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/02 06:05:48 by tmorikaw         ###   ########.fr       */
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

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}
