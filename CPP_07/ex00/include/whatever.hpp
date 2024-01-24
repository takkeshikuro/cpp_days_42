/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:42:29 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/24 06:36:04 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void	swap(T &a, T &b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T	min(T &a, T &b) {
	if (a < b)
		return a;
	return b;
}

template<typename T>
T	max(T &a, T &b) {
	if (a > b)
		return a;
	return b;
}


#endif