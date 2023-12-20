/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:18:42 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 07:44:53 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include "include/AAnimal.hpp"
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
	
	const Cat cat;
	cat.makeSound();
	cat.AAnimal::makeSound();
	std::cout << std::endl;
}

void test2() {
	std::cout << std::endl;
	std::cout << GREEN  "[Test Pointer Ver.]" RESET << std::endl;
	std::cout << std::endl;

	const AAnimal *cat = new Cat();
	cat->makeSound();
	cat->AAnimal::makeSound();
	delete cat;
	std::endl(std::cout);
}

void test3() {
	std::cout << std::endl;
	std::cout << GREEN  "[Test Reference Ver.]" RESET << std::endl;
	std::cout << std::endl;

	const Cat cat;
	const AAnimal &ref = cat;
	ref.makeSound();
	ref.AAnimal::makeSound();
	std::endl(std::cout);
}

int main() {
	test1();
	test2();
	test3();
	// system("leaks ex02");

	return 0;
}