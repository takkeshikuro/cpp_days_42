/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 01:09:41 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/13 16:42:01 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

class Span {
	public :
		Span(unsigned int N);
		Span(Span const &cpy);
		Span &operator=(Span const &cpy);
		~Span();
		
		class ContainerFullException : public std::exception {
			public :
				virtual const char *what() const throw();
		};

		class ArrListTooShort : public std::exception {
			public :
				virtual const char *what() const throw();
		};

		int &operator[](unsigned int index);

		int	getSize() const;
		
		void addNumber(unsigned int i_add);
		void addNumbers(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end, std::vector<int> n);

		int shortestSpan();
		int longestSpan();
		void	display_span();

	private :
		Span();
		unsigned int		_N;
		std::vector<int>	arr_span;
		
};

#endif