/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_sort.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 06:05:19 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/20 04:25:55 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PmergeMe.hpp"

void merge_all(std::vector<int>::iterator first, std::vector<int>::iterator middle, std::vector<int>::iterator last) 
{
	std::vector<int> temp;
	temp.reserve(std::distance(first, last));

	std::vector<int>::iterator it1 = first;
	std::vector<int>::iterator it2 = middle;

	while (it1 != middle && it2 != last) 
	{
		if (*it2 < *it1) {
			temp.push_back(*it2);
			++it2;
		} 
		else {
			temp.push_back(*it1);
			++it1;
		}
	}
	// Copy remaining elements from the first range if any
	while (it1 != middle) {
		temp.push_back(*it1);
		++it1;
	}
	// Copy remaining elements from the second range if any
	while (it2 != last) {
		temp.push_back(*it2);
		++it2;
	}
	std::copy(temp.begin(), temp.end(), first);
}

void	PmergeMe::sort_vct(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	if (std::distance(first, last) <= 1) 
	{ 
		if ( *last < *first ) {
			int tempf = *last;
			*last = *first;
			*first = tempf;
		}
		return;
	}
	std::vector<int>::iterator middle = first;
	std::advance(middle, (std::distance(first, last) / 2));
	sort_vct(first, middle);
	sort_vct(middle, last);
	merge_all(first, middle, last);
}
