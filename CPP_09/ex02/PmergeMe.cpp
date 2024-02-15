/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 05:46:36 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/15 10:44:25 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &cpy) {
	(void)cpy;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &cpy) {
	if (this != &cpy)
		*this = cpy;
	return *this;
}

PmergeMe::PmergeMe(int ac, char **av) 
{
	if (ac < 2)
		throw ErrorBadInput();

	for (int i = 1; i < ac; i++)
	{
		int j = 0;
		while (av[i][j])
		{
			if (!isdigit(av[i][j]))
				throw ErrorBadInput();
			j++;
		}

		if (strlen(av[i]) > 11)
			throw ErrorBadInput();
		unsigned long long check_max = std::atoi(av[i]);
		if (check_max > 2147483646)
			throw ErrorBadInput();

		_vector.push_back(std::atoi(av[i]));
		_list.push_back(std::atoi(av[i]));
	}
	check_double();

	std::cout << "Before: ";
	for (std::vector<int>::iterator it = get_begin_vct(); it != get_end_vct(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return ;
}

PmergeMe::~PmergeMe() {}


void	PmergeMe::check_double() 
{
	std::vector<int>::iterator check = _vector.begin();
	std::vector<int>::iterator finder = check;

	while (check != _vector.end())
	{
		finder = check;
		finder++;
		while (finder != _vector.end())
		{
			if (*check == *finder)
				throw DoubledNbException();
			finder++;
		}
		check++;
	}
}

void	PmergeMe::display_vct()
{
	std::cout << "Vector : ";
	for (std::vector<int>::iterator  it = get_begin_vct(); it != get_end_vct(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

}

void	PmergeMe::display_lst()
{
	std::cout << "List : ";
	for (std::list<int>::iterator  it = get_begin_lst(); it != get_end_lst(); it++)
		std::cout << *it << " ";
	std::cout  << std::endl;
}

std::vector<int>::iterator PmergeMe::get_begin_vct() {
	return (_vector.begin());
}

std::vector<int>::iterator PmergeMe::get_end_vct() {
	return (_vector.end());
}

std::list<int>::iterator PmergeMe::get_begin_lst() {
	return (_list.begin());
}

std::list<int>::iterator PmergeMe::get_end_lst() {
	return (_list.end());
}

const char* PmergeMe::DoubledNbException::what() const throw() {
	return "Duplicate numbers into sequence.";
}

const char* PmergeMe::ErrorBadInput::what() const throw() {
	return "Bad input arg (only integers accepted)";
}

std::ostream	&	operator<<( std::ostream & o, PmergeMe &cpy) {
	o << "After: ";
	for (std::vector<int>::iterator it = cpy.get_begin_vct(); it != cpy.get_end_vct(); it++)
		o << *it << " ";
	return o;
}
