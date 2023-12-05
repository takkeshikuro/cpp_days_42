/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:16:27 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/05 01:11:52 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"

class Brain;

class Cat : public AAnimal
{
	public :
		Cat();
		Cat(Cat const &cpy);
		Cat& operator=(Cat const &cpy);
		~Cat();
		void makeSound() const;
		void SetIdea(std::string idea, int i);
		void DisplayIdea() const;
	private :
		Brain *brain;
};

#endif