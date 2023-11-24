/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:18:42 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/24 05:19:39 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"

/* int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	return 0;
} */


int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrongA = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	
	std::cout << "Type : " << cat->getType() << std::endl;
	std::cout << "Type : " << dog->getType() << std::endl;
	std::cout << "Type : " << wrongcat->getType() << std::endl;
	std::cout << "Type : " << wrongA->getType() << std::endl;
	std::cout << std::endl;
	
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();
	wrongA->makeSound();
	wrongcat->makeSound();
	
	delete meta;
	delete dog;
	delete cat;
	delete wrongA;
	delete wrongcat;
	return 0;
}