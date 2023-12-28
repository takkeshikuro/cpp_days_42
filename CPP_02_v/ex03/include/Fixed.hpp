/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:17:38 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/22 07:40:09 by tmorikaw         ###   ########.fr       */
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
		bool operator>(const Fixed &cpy) const;
		bool operator<(const Fixed &cpy) const;
		bool operator>=(const Fixed &cpy) const;
		bool operator<=(const Fixed &cpy) const;
		bool operator==(const Fixed &cpy) const;
		bool operator!=(const Fixed &cpy) const;
		Fixed operator+(const Fixed &cpy);
		Fixed operator-(const Fixed &cpy);
		Fixed operator*(const Fixed &cpy);
		Fixed operator/(const Fixed &cpy);
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		
	private :
		int _value ;
		static const int nb_bits = 8;
};

std::ostream &operator<<(std::ostream &ostream, const Fixed &value);

#endif