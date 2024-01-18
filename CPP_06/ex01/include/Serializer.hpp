/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 01:25:29 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/18 02:44:42 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <iomanip>
#include <stdint.h>


#include "data_struct.hpp"

class Serializer {
	public :
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		
	private :
		Serializer();
		Serializer(Serializer const &cpy);
		Serializer& operator=(Serializer const &cpy);
		~Serializer();

};

#endif