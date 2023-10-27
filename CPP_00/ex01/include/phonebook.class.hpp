/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 06:53:26 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/27 09:49:32 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib> //exit
#include <sstream> //fake atoi
#include "contact.class.hpp"

class Phonebook
{
	public :
	Phonebook(void);
	~Phonebook(void);
	
	void go_phonebook();  
	void search_contact();
	int only_digit(const std::string& str);
	void init_index();

	private :
	Contact contacts[8];	
};

int		fake_atoi(const std::string& str);
void	error(int ok);

#endif
