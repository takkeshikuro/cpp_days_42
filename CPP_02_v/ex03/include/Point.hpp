/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:18:32 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/23 01:12:14 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public :
		Point();
		Point(const float a, const float b);
		Point(const Point &cpy);
		Point &operator=(const Point &cpy);
		~Point();
		float get_x() const;
		float get_y() const;
	private :
		const Fixed x;
		const Fixed y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);


#endif