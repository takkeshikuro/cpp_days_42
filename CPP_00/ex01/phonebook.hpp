/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 06:53:26 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/20 08:41:50 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>

class Contact
{
	public :
	
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_nb;
	std::string _dark_secret;
	int			index;
	
	Contact(void);
	~Contact(void);

	private :

};

class Phonebook
{
	public :
	
	Contact contacts[8];
	int nbcontact;
	
	Phonebook(void);
	~Phonebook(void);
	
	void add_contact(Contact &contacts);
	void search_contact(Phonebook &Phonebook) const;
	void exit_phonebook(void) const;
	
	private :
	
	
};

int only_digit(const std::string& str);
void init_index(Phonebook &Phonebook);


#endif
