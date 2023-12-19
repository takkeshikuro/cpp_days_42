/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 06:59:35 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/19 03:59:32 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Point.hpp"

int main(void)
{
    const Point A(2, 2);
    const Point B(7, 2);
    const Point C(3, 6);
    const Point P(4, 3);

    if (bsp(A, B, C, P) == true)
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "FALSE" << std::endl;
    return 0;
}