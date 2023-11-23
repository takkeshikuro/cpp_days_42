/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:23:20 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/23 01:12:53 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Point.hpp"

Point::Point() : x(8), y(0) {
//	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float a, const float b) : x(a), y(b) {
	std::cout << "in this instance now : x=" << x << ", y=" << y << std::endl;
}

/* Point::Point(const Point &cpy) {
	(void)cpy;
//	std::cout << "cpy constructor called" << std::endl;
} */

Point::Point(const Point &cpy) : x(cpy.x), y(cpy.y){
    (void)cpy;
//    std::cout << "cpy constructor called" << std::endl;
}

Point &Point::operator=(const Point &cpy) {
	(void)cpy;
//	std::cout << "copy assignment operator called" << std::endl;
/* 	if (this != &cpy)
		x = cpy.x;
		y = cpy.y; */
	return *this;
}



Point::~Point() {
//	std::cout << "destructor called" << std::endl;
}

float	Point::get_x() const {
//	std::cout << "x float = " << x << std::endl;
	return x.toFloat();
}

float	Point::get_y() const {
//	std::cout << "y float = " << y << std::endl;
	return y.toFloat();
}