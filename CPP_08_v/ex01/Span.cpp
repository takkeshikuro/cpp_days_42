/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 01:15:14 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/15 04:38:34 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(Span const &cpy) : _N(cpy._N) {}

Span	&Span::operator=(const Span &cpy)
{
	if (this != &cpy) {
		this->_N = cpy._N;
		this->arr_span = cpy.arr_span;
	}
	return *this;
}

Span::~Span() {}

const char	*Span::ContainerFullException::what() const throw() {
	return "The container is full, cannot add more value.";
}

const char	*Span::ArrListTooShort::what() const throw() {
	return "The container is too short.";
}

int	Span::getSize() const {
	return arr_span.size();
}

int	&Span::operator[](unsigned int index) 
{
	if (index >= arr_span.size())
		throw ArrListTooShort();
	return arr_span[index];
}

//////////////////////////////////////////////////////////////////////

void	Span::addNumber(unsigned int i_add)
{
	if (arr_span.size() >= _N)
		throw ContainerFullException();
	else
		arr_span.push_back(i_add);
}

void	Span::display_span()
{
	for (size_t i = 0; i < arr_span.size(); ++i) {
		std::cout << "arr[" << i << "] = " << arr_span[i] << std::endl;
	}
}

int	Span::longestSpan()
{
	if (arr_span.size() < 2)
		throw ArrListTooShort();
	
	std::vector<int> sorted_arr = arr_span;
	std::sort(sorted_arr.begin(), sorted_arr.end());
	
//	for (std::vector<int>::iterator it = sorted_arr.begin(); it != sorted_arr.end(); ++it)
//		std::cout << "sorted vector : " << *it << std::endl;
	
	int l_span = sorted_arr.back() - sorted_arr.front();
	return l_span;
}

int	Span::shortestSpan()
{
	if (arr_span.size() < 2)
		throw ArrListTooShort();
	
	std::vector<int> sorted_arr = arr_span;
	std::sort(sorted_arr.begin(), sorted_arr.end());

	int s_span = sorted_arr[1] - sorted_arr[0];
	
	for (size_t i = 2; i < sorted_arr.size(); ++i) 
	{
		int current_span = sorted_arr[i] - sorted_arr[i - 1];
		if (current_span < s_span)
			s_span = current_span;
	}
	return s_span;
}
