/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:18:42 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/26 23:45:29 by tmorikaw         ###   ########.fr       */
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
}  */


int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wronganimal = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	
	std::cout << "Type : " << cat->getType() << std::endl;
	std::cout << "Type : " << dog->getType() << std::endl;
	std::cout << "Type : " << wrongcat->getType() << std::endl;
	std::cout << "Type : " << wronganimal->getType() << std::endl;
	std::cout << std::endl;
	
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();
	wronganimal->makeSound();
	wrongcat->makeSound();

	const WrongCat *wrong_cat_object = new WrongCat();
	wrong_cat_object->makeSound();
	delete wrong_cat_object;
	
	delete meta;
	delete dog;
	delete cat;
	delete wronganimal;
	delete wrongcat;
	return 0;
}