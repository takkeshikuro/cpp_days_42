/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:18:10 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/25 02:06:07 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Array.hpp"
#include <random>

#define MAX_VAL 750

int main() {
	try {
		// tableau vide
		Array<int> emptyArray;
		std::cout << "Empty Array Size: " << emptyArray.size() << std::endl;

		// tableau de 5 int
		Array<int> intArray(5);
		std::cout << "Initialized Array Size: " << intArray.size() << std::endl;

		for (int i = 0; i < intArray.size(); ++i) {
			intArray[i] = i * 2;
		}

		// display
		for (int i = 0; i < intArray.size(); ++i) {
			std::cout << "array[" << i << "] : " << intArray[i] << std::endl;
		}

		// Cpy
		Array<int> cpyArray(intArray);
		std::cout << "cpy Array Size: " << cpyArray.size() << std::endl;

		// modif et check
		intArray[0] = 99;
		std::cout << "Original Array[0]: " << intArray[0] << std::endl;
		std::cout << "cpy Array[0]: " << cpyArray[0] << std::endl;

		// Tentative d'accéder à un index hors limite
		std::cout << "try index [6] : " << intArray[6] << std::endl;

	} 
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

/* int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
} */
