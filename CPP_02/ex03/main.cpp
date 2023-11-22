/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 06:59:35 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/22 09:21:39 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Point.hpp"

int main(void)
{
    const Point A(2, 1);
    const Point B(4.0, 3.0);
    const Point C(5.0, 1.0);
    const Point P(5.0, 5.0);

/*      int i = 2;
    Fixed ok(i);
    float f_ok = ok.toFloat();
    f_ok += 0.5;
    std::cout << f_ok << std::endl;  */
    std::cout << "a.x into main = " << A.get_f_x() << std::endl;
    std::cout << "a.y into main = " << A.get_f_y() << std::endl;

    bsp(A, B, C, P);
    return 0;
}