/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:34:02 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/25 02:00:26 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>


template <typename T>
class Array {
	public :
		Array();
		Array(unsigned int n);
		Array(Array const &cpy);
		Array &operator=(Array const &cpy);
		~Array();

		// []operator to access array[index];
		T &operator[](unsigned int index);
		int size() const;
		
		class IndexOutOfRange : public std::exception {
			public :
				virtual const char * what() const throw();
		};

	private :
		T 				*arr_ptr;
		unsigned int	arr_size;
};


template <typename T>
Array<T>::Array() : arr_ptr(NULL), arr_size(0) {} //(nullptr)

template <typename T>
Array<T>::Array(unsigned int n) : arr_size(n) {
	arr_ptr = new T[n];
}

template <typename T>
Array<T>::Array(Array const &cpy) : arr_size(cpy.arr_size) 
{
	arr_ptr = new T[arr_size];
	for (unsigned int i = 0; i < arr_size; i++)
		arr_ptr[i] = cpy.arr_ptr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &cpy) 
{
	if (this != &cpy) {
		delete[] arr_ptr;
		arr_size = cpy.arr_size;
		arr_ptr = new T[arr_size];
		for (unsigned int i = 0; i < arr_size; i++)
			arr_ptr[i] = cpy.arr_ptr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() 
{
	delete[] arr_ptr;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) 
{
	if (index >= arr_size)
		throw IndexOutOfRange();
	return arr_ptr[index];
}

template <typename T>
int Array<T>::size() const 
{
	return arr_size;
}

template <typename T>
const char * Array<T>::IndexOutOfRange::what() const throw() 
{
	return "(error) Index out of range!";
}

#endif
