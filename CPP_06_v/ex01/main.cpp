/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 02:41:35 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/07 00:43:03 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Serializer.hpp"

int	main()
{
	Data data;
	data.i_int = 42;
	data.c_char = 'w';
	
	std::cout << "data.i_int = " << data.i_int << std::endl;
	std::cout << "data.c_char = " << data.c_char << std::endl;
	std::cout << std::endl;
	
	uintptr_t stock = Serializer::serialize(&data);
	
	std::cout << "data serialized : " << stock << std::endl;
	std::cout << std::endl;
	
	Data *data2 = Serializer::deserialize(stock);
	
	std::cout << "data2->i_int = " << data2->i_int << std::endl;
	std::cout << "data2->c_char = " << data2->c_char << std::endl;
}