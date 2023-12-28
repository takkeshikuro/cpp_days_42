/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:27:10 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/23 03:47:02 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Fixed.hpp"

Fixed::Fixed() {
	_value = 0;
}

Fixed::Fixed(const int n_int) {
	_value = n_int << nb_bits;
}

Fixed::Fixed(const float n_flo) {
	_value = roundf(n_flo * (1 << nb_bits));
}

Fixed::Fixed(const Fixed &cpy) {
	_value = cpy._value;
}

Fixed &Fixed::operator=(const Fixed &cpy) {
	if (this != &cpy)
		_value = cpy.getRawBits();
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
	return _value;
}

void	Fixed::setRawBits(int const raw) {
	_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_value) / (1 << nb_bits);
}

int Fixed::toInt() const {
	return _value >> nb_bits;
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &cpy) {
	return ostream << cpy.toFloat();
}

bool Fixed::operator>(const Fixed &cpy) const {
	return _value > cpy._value;
}

bool Fixed::operator<(const Fixed &cpy) const {
	return _value < cpy._value;
}

bool Fixed::operator>=(const Fixed &cpy) const {
	return _value >= cpy._value;
}

bool Fixed::operator<=(const Fixed &cpy) const {
	return _value <= cpy._value;
}

bool Fixed::operator==(const Fixed &cpy) const {
	return _value == cpy._value;
}

bool Fixed::operator!=(const Fixed &cpy) const {
	return _value != cpy._value;
}

Fixed Fixed::operator+(const Fixed &cpy) {
	return _value + cpy._value;
}

Fixed Fixed::operator-(const Fixed &cpy) {
	return _value - cpy._value;
}

Fixed Fixed::operator*(const Fixed &cpy) {
	return _value * cpy._value;
}

Fixed Fixed::operator/(const Fixed &cpy) {
	return _value / cpy._value;
}

Fixed &Fixed::operator++() {
	_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	_value++;
	return tmp;
}

Fixed &Fixed::operator--() {
	_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	_value--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a <= b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a <= b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a >= b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a >= b)
		return a;
	return b;
}