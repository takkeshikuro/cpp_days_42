/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:18:42 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/24 06:52:10 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"
#include "include/Brain.hpp"

#include <sstream>

std::string iToStr(int i) {
	std::stringstream ss;
	ss << i;
	return ss.str();
}

int main() {
	std::cout <<  "[Test 3]"  << std::endl;
	Cat cat;
	std::endl(std::cout);

	for (int i = 0; i < 30; i++)
		cat.SetIdea("it's " + iToStr(i + 1), i);
	cat.DisplayIdea();
	std::endl(std::cout);
	
	Cat copy(cat);
	std::cout << "cat address: " << &cat << ", copy address:" << &copy << std::endl;
	std::cout << "type of copy is : " << copy.getType() << std::endl;
	copy.DisplayIdea();
	std::endl(std::cout);
	
	std::endl(std::cout);
}
/* int main()
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
} */