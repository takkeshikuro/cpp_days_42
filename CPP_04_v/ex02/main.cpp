/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:18:42 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/28 01:09:33 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/AAnimal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"
#include "include/Brain.hpp"
#include <sstream>

# define GREEN "\033[32m"
# define RESET "\033[0m"

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
	std::cout << "cat's brain address: " << cat.Get_brain() << std::endl;
	std::cout << "copy's brain address: " << copy.Get_brain() << std::endl;
	std::cout << "type of copy is : " << copy.getType() << std::endl;
	std::cout << std::endl;
	copy.DisplayIdea();
	std::cout << std::endl;
	
	// operator (=) test
	Cat assig;
	assig = cat;
	std::cout << std::endl;
	std::cout << "cat's brain address: " << cat.Get_brain() << std::endl;
	std::cout << "assig's brain address: " << assig.Get_brain() << std::endl;	std::cout << std::endl;
	assig.DisplayIdea();
	std::cout << std::endl;

	cat.makeSound();
	std::cout << std::endl;
}

int main() {
	
	test3();
	return 0;
}