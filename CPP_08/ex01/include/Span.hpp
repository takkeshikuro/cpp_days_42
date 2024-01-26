/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 01:09:41 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/26 02:39:56 by tmorikaw         ###   ########.fr       */
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
		void addNumber(const std::vector<int> &vector);
		int shortestSpan();
		int longestSpan();
		
	private :
		unsigned int _N;
		std::vector<int> arr_span;
		Span();
};

#endif