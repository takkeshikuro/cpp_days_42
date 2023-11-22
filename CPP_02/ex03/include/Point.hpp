/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:18:32 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/22 09:20:00 by tmorikaw         ###   ########.fr       */
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
		float get_f_x() const {return _x;};
		float get_f_y() const {return _y;};
	private :
		const Fixed x;
		const Fixed y;
		float _x;
		float _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);


#endif