/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 06:53:26 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/19 08:08:23 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Phonebook
{
	public :
	int i;

	Phonebook() {
		i = 1;
	}

	void print() {
		std::cout << "value is : " << i << std::endl;
	}
	void dbl() {
		i *= 2;
	}
};
