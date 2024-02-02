/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 04:59:44 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/26 01:04:11 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

class OccurenceNotFound : public std::exception {
    public :
        virtual const char *what() const throw();
};

template <typename T>
void   easyfind(T const &container, int i) {

	typename T::const_iterator it = std::find(container.begin(), container.end(), i);
	
	if (it != container.end())
		std::cout << "occurence found for : " << i << std::endl;
    else
    	throw OccurenceNotFound();
}


#endif