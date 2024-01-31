/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 06:55:39 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/31 07:40:47 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PmergeMe.hpp"

#include <iostream>
#include <vector>

// Fonction de tri par insertion
void insertion_sort(std::vector<int>& arr) {
	int n = arr.size();
	for (int i = 1; i < n; ++i) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

// Fonction de fusion de deux sous-séquences triées
void merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& arr) {
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (i < nL && j < nR) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		} else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < nL) {
		arr[k] = left[i];
		i++;
		k++;
	}

	while (j < nR) {
		arr[k] = right[j];
		j++;
		k++;
	}
}

// Fonction principale de tri merge-insert
void merge_insert_sort(std::vector<int>& arr, int threshold) {
	int n = arr.size();

	if (n <= threshold) {
		insertion_sort(arr);
	} else {
		int middle = n / 2;
		std::vector<int> left(arr.begin(), arr.begin() + middle);
		std::vector<int> right(arr.begin() + middle, arr.end());

		merge_insert_sort(left, threshold);
		merge_insert_sort(right, threshold);

		merge(left, right, arr);
	}
}

const char *ErrorBadInput::what() const throw() {
	return "bad input";
}


void    go_sort(int ac, char **av) 
{
	std::vector<int> sequence;
	for (int i = 1; i < ac; ++i) {
		try {
			sequence.push_back(std::atoi(av[i]));
		}
		catch (const std::exception &e) {
			throw ErrorBadInput();
		}
	}
	for (size_t i = 0; i < sequence.size();  ++i) {
		std::cout << sequence[i] << std::endl;
	}
	std::cout << std::endl;
	
	const std::clock_t c_start_vector = std::clock();
	merge_insert_sort(sequence, 10);
	const std::clock_t c_end_vector = std::clock();
	
	for (size_t i = 0; i < sequence.size();  ++i) {
		std::cout << sequence[i] << std::endl;
	}
	std::cout << "time to process a range of " << (ac - 1);
	std::cout << " element with std::vector : " << (c_end_vector - c_start_vector) << " us" << std::endl;
}

int main(int ac, char **av)
{
	try {
			go_sort(ac, av);
	}
	catch (const std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
}