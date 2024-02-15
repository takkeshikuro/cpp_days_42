/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 06:55:39 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/15 10:49:47 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PmergeMe.hpp"

int main(int ac, char **av)
{
	try {
		PmergeMe sequence(ac, av);
	
		const std::clock_t c_start_vector = std::clock();
		sequence.sort_vct();
		const std::clock_t c_end_vector = std::clock();

		const std::clock_t c_start_list = std::clock();
		sequence.sort_lst();
		const std::clock_t c_end_list = std::clock();
		
		std::cout << sequence << std::endl << std::endl;

		std::cout  << "Time to process a range of " << (ac - 1) << " elements with std::vector : " << (c_end_vector - c_start_vector) << " us" << std::endl;
		std::cout << "Time to process a range of " << (ac - 1) << " elements with std::list : " << (c_end_list - c_start_list) << " us" << std::endl;

	}
	catch (const std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
}