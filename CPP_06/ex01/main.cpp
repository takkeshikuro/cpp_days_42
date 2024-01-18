/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 02:41:35 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/18 02:43:09 by tmorikaw         ###   ########.fr       */
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

	std::cout << stock << std::endl;

	Data *data2 = Serializer::deserialize(stock);

	std::cout << "data2 = " << data2->ok << std::endl;

}