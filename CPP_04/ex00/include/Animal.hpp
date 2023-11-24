/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:13:17 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/24 05:18:34 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public :
		Animal();
		Animal(Animal const &cpy);
		Animal& operator=(Animal const &cpy);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const {return type;};
	protected :
		std::string type;
};

#endif