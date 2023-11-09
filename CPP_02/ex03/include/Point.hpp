/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:18:32 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/09 10:25:28 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

class Point
{
	public :
		Point();
		Point(const float a, const float b);
		Point(const Point &cpy);
		Point &operator=(const Point &cpy);
		~Point();
	private :
		const Fixed x;
		const Fixed y;
		
};

#endif