/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 04:51:49 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/27 04:30:46 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public :
		WrongAnimal();
		WrongAnimal(WrongAnimal const &cpy);
		WrongAnimal& operator=(WrongAnimal const &cpy);
		virtual ~WrongAnimal();
	
		virtual void makeSound() const;
		std::string getType() const;

	protected :
		std::string type;
};

#endif