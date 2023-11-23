/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 06:59:35 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/23 01:34:44 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Point.hpp"

int main(void)
{
    const Point A(2, 1);
    const Point B(4, 3);
    const Point C(5, 1);
    const Point P(3, 1);

    if (bsp(A, B, C, P) == true)
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "FALSE" << std::endl;
    return 0;
}