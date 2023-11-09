/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:18:05 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/09 11:00:28 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int n_int) {
	std::cout << "Int constructor called" << std::endl;
	_value = n_int << nb_bits;
}

Fixed::Fixed(const float n_flo) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(n_flo * (1 << nb_bits));
}

Fixed::Fixed(const Fixed &cpy) {
	_value = cpy._value;
	std::cout << "copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &cpy) {
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &cpy)
		_value = cpy.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(int const raw) {
	_value = raw;
	std::cout << "setRawBits member function called" << std::endl;
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
	Fixed res;
	res.setRawBits(_value + cpy._value);
	return res;
}

Fixed Fixed::operator-(const Fixed &cpy) {
	Fixed res;
	res.setRawBits(_value - cpy._value);
	return _value - cpy._value;
}

Fixed Fixed::operator*(const Fixed &cpy) {
	long long product = static_cast<long long>(_value) * cpy._value;
	Fixed res;
	res.setRawBits(static_cast<int>(product >> nb_bits));
	return res;
}

Fixed Fixed::operator/(const Fixed &cpy) {
	if (cpy._value == 0)
		return Fixed();
	return Fixed(roundf(toFloat() / cpy.toFloat()));
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