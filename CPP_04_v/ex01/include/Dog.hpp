/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:37:52 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/28 00:31:53 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Brain;

class Dog : public Animal
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