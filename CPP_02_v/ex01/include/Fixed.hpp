/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 05:30:16 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/09 07:11:32 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public :
		Fixed();
		Fixed(const int n_int);
		Fixed(const float n_flo);
		Fixed(const Fixed &cpy);
		Fixed &operator=(const Fixed &cpy);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		
	private :
		int value;
		static const int nb_bits = 8;
};

std::ostream &operator<<(std::ostream &ostream, const Fixed &value);

#endif