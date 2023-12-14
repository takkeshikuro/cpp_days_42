/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:07:33 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/23 01:36:32 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Point.hpp"


float   bsp_dig(Point const point, Point const p1, Point const p2)
{
	float q1(point.get_x() * (p1.get_y() - p2.get_y()));
	float q2(p1.get_x() * (p2.get_y() - point.get_y()));
	float q3(p2.get_x() * (point.get_y() - p1.get_y()));
	
	float area = (q1 + q2 + q3) / 2;
	if (area < 0)
		area *= -1;
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) 
{
	float q1(a.get_x() * (b.get_y() - c.get_y()));
	float q2(b.get_x() * (c.get_y() - a.get_y()));
	float q3(c.get_x() * (a.get_y() - b.get_y()));
	
	float area = (q1 + q2 + q3) / 2;
	if (area < 0)
		area *= -1;    
	float Area1 = bsp_dig(point, a, b);
	float Area2 = bsp_dig(point, a, c);
	float Area3 = bsp_dig(point, b, c);
	std::cout << "main area is " << area << " and a1/a2/a3 are : "; // a supp attention
	std::cout << Area1 << "/" << Area2 << "/" << Area3 << std::endl; // ca aussi
	if (Area1 == 0 || Area2 == 0 || Area3 == 0)
		return false;
	if ((Area1 + Area2 + Area3) == area)
		return true;
	else
		return false;
}
