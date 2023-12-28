/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:23:20 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/23 03:45:17 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float a, const float b) : x(a), y(b) {}

Point::Point(const Point &cpy) : x(cpy.x), y(cpy.y) {}

Point &Point::operator=(const Point &cpy) {
	(void)cpy;
	return *this;
}

Point::~Point() {}

float	Point::get_x() const {
	return x.toFloat();
}

float	Point::get_y() const {
	return y.toFloat();
}