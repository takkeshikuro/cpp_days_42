/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:23:20 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/09 10:29:33 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Fixed.hpp"

Point::Point() : x(0), y(0) {
    std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float a, const float b) : x(a), y(b) {
    std::cout << "param constructor called" << std::endl;
}

Point::Point(const Point &cpy) {
    x = cpy.x;
    y = cpy.y;
    std::cout << "cpy constructor called" << std::endl;
}


Point &Point::operator=(const Point &cpy) {
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &cpy)
		_value = cpy.getRawBits();
	return *this;
}