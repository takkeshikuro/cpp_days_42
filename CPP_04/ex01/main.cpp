/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:18:42 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/27 04:25:20 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"
#include "include/Brain.hpp"
#include <sstream>

# define GREEN "\033[32m"
# define RESET "\033[0m"

void test1() {
 	std::cout << std::endl;
	std::cout << GREEN "[Test 1]" RESET << std::endl;
	std::cout << std::endl;
	
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	delete j;//should not create a leak
	delete i;
}

void test2() {
	std::cout << std::endl;
	std::cout << GREEN "[Test 2]" RESET << std::endl;
	std::cout << std::endl;

	int nb_animals = 4;
	const Animal *animals[nb_animals];
	
	
	for (int i = 0; i < nb_animals / 2; i++)
		animals[i] = new Cat();

	for (int i = nb_animals / 2; i < nb_animals; i++)
		animals[i] = new Dog();
	std::cout << std::endl;

	for (int i = 0; i < nb_animals; i++)
		delete animals[i];
}

std::string iToStr(int i) {
	std::stringstream ss;
	ss << i;
	return ss.str();
}

void test3() {
	std::cout << std::endl;
	std::cout << GREEN "[Test 3]" RESET << std::endl;
	std::cout << std::endl;
	
	Cat cat;
	for (int i = 0; i < 30; i++)
		cat.SetIdea("it's " + iToStr(i + 1), i);
	cat.DisplayIdea();
	std::cout << std::endl;
	
	// copy constructor test
	Cat copy(cat);
	std::cout << std::endl;
	std::cout << "cat address: " << &cat << ", copy address:" << &copy << std::endl;
	std::cout << "type of copy is : " << copy.getType() << std::endl;
	std::cout << std::endl;
	copy.DisplayIdea();
	std::cout << std::endl;
	
	// operator (=) test
	Cat assig;
	assig = cat;
	std::cout << std::endl;
	std::cout << "cat address: " << &cat << ", assig address:" << &assig << std::endl;
	std::cout << std::endl;
	assig.DisplayIdea();
	std::cout << std::endl;
}

int main() {
	test1();
	std::cout << std::endl;
	test2();
	std::cout << std::endl;
	test3();
	return 0;

}
