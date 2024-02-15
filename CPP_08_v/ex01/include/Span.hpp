/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 01:09:41 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/15 04:37:49 by tmorikaw         ###   ########.fr       */
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

		int		&operator[](unsigned int index);
		int		getSize() const;
		void	addNumber(unsigned int i_add);
		int		shortestSpan();
		int		longestSpan();
		void	display_span();
		
		template <typename inputIterator>
		void addRange(inputIterator begin, inputIterator end) 
		{
			if (arr_span.size() + std::distance(begin, end) > _N)
				throw ContainerFullException();
			arr_span.insert(arr_span.end(), begin, end);
		}

	private :
		Span();
		unsigned int		_N;
		std::vector<int>	arr_span;
		
};



#endif