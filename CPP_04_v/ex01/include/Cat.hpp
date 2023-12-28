/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:16:27 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/28 00:31:47 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Brain;

class Cat : public Animal
{
	public :
		Cat();
		Cat(Cat const &cpy);
		Cat& operator=(Cat const &cpy);
		~Cat();

		void makeSound() const;
		void SetIdea(std::string idea, int i);
		void DisplayIdea() const;
		Brain *Get_brain() const;

	private :
		Brain *brain;
};

#endif