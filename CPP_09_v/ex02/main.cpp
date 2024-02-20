/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 06:55:39 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/20 04:13:02 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PmergeMe.hpp"

int main(int ac, char **av)
{
	try {
		PmergeMe sequence(ac, av);

		// std::vector usage
		const std::clock_t c_start_vector = std::clock();
		sequence.sort_vct(sequence.get_begin_vct(), sequence.get_end_vct()-1);
		const std::clock_t c_end_vector = std::clock();

		// std::list usage
		const std::clock_t c_start_list = std::clock();
		sequence.sort_lst(sequence.get_begin_lst(), sequence.get_end_lst()--);
		const std::clock_t c_end_list = std::clock();
		
		// display sorted sequence 
		std::cout << sequence << std::endl << std::endl;
		
		sequence.print_summary(ac - 1, c_end_vector - c_start_vector, "std::vector");	
		sequence.print_summary(ac - 1, c_end_list - c_start_list, "std::list");	
	}
	catch (const std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
}