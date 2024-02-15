/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:18:36 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/15 04:58:22 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> 
{
	public :
		MutantStack();
		MutantStack(MutantStack const &cpy);
		MutantStack &operator=(MutantStack const &cpy);
		~MutantStack();
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};


template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() 
{}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &cpy) : std::stack<T>(cpy) 
{}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &cpy) {
	if (this != &cpy) {
		std::stack<T>::operator=(cpy);
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return std::stack<T>::c.end();
}

#endif