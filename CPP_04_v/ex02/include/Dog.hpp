/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:37:52 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/28 01:06:15 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Brain;

class Dog : public AAnimal
{
    public :
        Dog();
        Dog(Dog const &cpy);
        Dog& operator=(Dog const &cpy);
        ~Dog();

        void makeSound() const;
        void SetIdea(std::string idea, int i);
        void DisplayIdea() const;
		Brain *Get_brain() const;

    private :
        Brain *brain;
};

#endif