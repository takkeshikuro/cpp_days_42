/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_sort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 06:11:09 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/20 04:14:43 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PmergeMe.hpp"

void merge_all(std::list<int>::iterator first, std::list<int>::iterator middle, std::list<int>::iterator last) 
{
	std::vector<int> temp;
	temp.reserve(std::distance(first, last));

	std::list<int>::iterator it1 = first;
	std::list<int>::iterator it2 = middle;

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


void	PmergeMe::sort_lst(std::list<int>::iterator first, std::list<int>::iterator last)
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
	std::list<int>::iterator middle = first;
	std::advance(middle, (std::distance(first, last) / 2));
	sort_lst(first, middle);
	sort_lst(middle, last);
	merge_all(first, middle, last);
}