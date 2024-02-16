/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 06:56:06 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/15 10:44:29 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP


#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"

class PmergeMe {
	public :
		PmergeMe(int ac, char **av);
		~PmergeMe();

		class DoubledNbException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class ErrorBadInput : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		
		void	check_double();
		void	print_before();
		void	print_summary(int nb_range, int time, std::string container_name);
		
		void	sort_vct();
		void	sort_first_vct(std::vector<int> &first, std::vector<int> &second);
		void	merge_all_vct(std::vector<int> &first, std::vector<int> &second);
		void	display_vct();
		
		void	sort_lst();
		void	sort_first_lst(std::list<int> &first, std::list<int> &second);
		void	merge_all_lst(std::list<int> &first, std::list<int> &second);
		void	display_lst();
		
		std::vector<int>::iterator get_begin_vct();
		std::vector<int>::iterator get_end_vct();
		
		std::list<int>::iterator get_begin_lst();
		std::list<int>::iterator get_end_lst();

	private:
		PmergeMe();
		PmergeMe(PmergeMe const &cpy);
		PmergeMe &operator=(PmergeMe const &cpy);
		
		std::vector<int> _vector;
		std::vector<int>::iterator _ite_f_vct;
		std::vector<int>::iterator _ite_s_vct;

		std::list<int> _list;
		std::list<int>::iterator _ite_f_lst;
		std::list<int>::iterator _ite_s_lst;
};

std::ostream	&operator<<(std::ostream &o, PmergeMe &cpy);

#endif