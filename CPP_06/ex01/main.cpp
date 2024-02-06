/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 02:41:35 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/06 05:19:47 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Serializer.hpp"

int	main()
{
	Data data;
	uintptr_t stock = 0;

	data.ok = 42;
	std::cout << "data = " << data.ok << std::endl;

	stock = Serializer::serialize(&data);
	std::cout << "data serialized : " << stock << std::endl;

	Data *data2 = Serializer::deserialize(stock);
	std::cout << "data deserialized : " << data2->ok << std::endl;
}