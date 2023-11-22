/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:07:33 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/22 09:20:16 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) 
{
    (void)point;
    std::cout << "a.x into bsp: " << a.get_f_x() << std::endl;
    std::cout << "a.y into bsp: " << a.get_f_y() << std::endl;

 //   std::cout << a.get_x() << std::endl;
    float p1(a.get_x() * (b.get_y() - c.get_y()));
    float p2(b.get_x() * (c.get_y() - a.get_y()));
    float p3(c.get_x() * (a.get_y() - b.get_y()));
    
    float area = (p1 + p2 + p3) / 2;
    std::cout << "area is : " << area << std::endl;
    return 1;
}