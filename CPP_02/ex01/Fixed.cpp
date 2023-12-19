/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 07:11:41 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/19 03:38:50 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Fixed.hpp"

Fixed::Fixed(void) : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n_int) {
	std::cout << "Int constructor called" << std::endl;
	value = n_int << nb_bits;
}

Fixed::Fixed(const float n_flo) {
	std::cout << "Float constructor called" << std::endl;
	value = roundf(n_flo * (1 << nb_bits));
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed() {
	std::cout << "destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->value = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
//	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits(int const raw) {
	value = raw;
//	std::cout << "setRawBits member function called" << std::endl;
}

float Fixed::toFloat() const {
	return static_cast<float>(value) / (1 << nb_bits);
}

int Fixed::toInt() const {
	return value >> nb_bits;
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &cpy) {
	return ostream << cpy.toFloat();
}