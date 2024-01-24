/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshikuro <keshikuro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 06:39:57 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/24 15:04:58 by keshikuro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/iter.hpp"

void    test_arr_int()
{
	std::cout << "TEST INT TAB" << std::endl;
	
	int arr_int[6] = {0,1,2,3,4,5};
	::iter(arr_int, 6, function_test);
	
	return ;
}

void    test_arr_double()
{
	std::cout << "TEST DOUBLE TAB" << std::endl;
	
	double arr_double[6] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.25};
	::iter(arr_double, 6, function_test);
	
	return ;
}

void    test_arr_string()
{
	std::cout << "TEST STRING TAB" << std::endl;
	
	std::string arr_string[4] = {"ok_0", "ok_1", "ok_2", "ok_3"};
	::iter(arr_string, 4, function_test);

	return ;
}

int main( void ) 
{
	test_arr_int();
	std::cout << std::endl;
	test_arr_double();
	std::cout << std::endl;
	test_arr_string();
	return 0;
}