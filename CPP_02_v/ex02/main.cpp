/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:18:18 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/19 03:33:52 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Fixed.hpp"

void test()
{
	std::cout << "---------TEST--------" << std::endl;
	Fixed a(8);
	Fixed b(2);
	std::cout << "a = " << a << " ; b = " << b << std::endl;
	std::cout << std::endl;
	
	Fixed res = a + b;
	std::cout << "a + b = " << res << std::endl;
	res = a - b;
	std::cout << "a - b = " << res << std::endl;
	res = a * b;
	std::cout << "a * b = " << res << std::endl;
	res = a / b;
	std::cout << "a / b = " << res << std::endl;
	std::cout << std::endl;

	if (a >= b)
		std::cout << "a >= b" << std::endl;
	else if (a <= b)
		std::cout << "a <= b" << std::endl;
	if (a == b)
		std::cout << "a == b" << std::endl;
	else if (a != b)
		std::cout << "a != b" << std::endl;
	std::cout << std::endl;

	res = a++;
	std::cout << "a++ = " << a << std::endl;
	std::cout << "res = " << res << std::endl;
	res = ++b;
	std::cout << "++b = " << b << std::endl;
	std::cout << "res = " << res << std::endl;
	res = a--;
	std::cout << "a-- = " << a << std::endl;
	std::cout << "res = " << res << std::endl;
	res = --b;
	std::cout << "--b = " << b << std::endl;
	std::cout << "res = " << res << std::endl;
	std::cout << std::endl;

	res = res.min(a, b);
	std::cout << "res.min = " << res << std::endl;
	res = res.max(a, b);
	std::cout << "res.max = " << res << std::endl;
	std::cout << "---------------------" << std::endl;
}

int main( void ) 
{
	test();
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
} 

