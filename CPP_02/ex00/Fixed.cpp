/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:38:29 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/09 07:15:48 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Fixed.hpp"

Fixed::Fixed(void) {
	value = 0;
	std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	value = copy.value;
	std::cout << "copy constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &copy)
		value = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits(int const raw) {
	value = raw;
	std::cout << "setRawBits member function called" << std::endl;
}