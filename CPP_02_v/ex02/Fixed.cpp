/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:18:05 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/19 03:23:07 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
	//std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const int n_int) {
//	std::cout << "Int constructor called" << std::endl;
	_value = n_int << nb_bits; // (value * 256)
}

Fixed::Fixed(const float n_flo) {
//	std::cout << "Float constructor called" << std::endl;
	_value = roundf(n_flo * (1 << nb_bits)); // (value * 256)
}

Fixed::Fixed(const Fixed &copy) {
//	std::cout << "copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed() {
//	std::cout << "destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy) {
//	std::cout << "copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_value = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
//	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(int const raw) {
//	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_value) / (1 << nb_bits); // (value/256)
}

int Fixed::toInt() const {
	return _value >> nb_bits; // (value/256)
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

Fixed Fixed::operator+(const Fixed &cpy) const {
	Fixed res;
	res.setRawBits(_value + cpy._value);
	return res;
}

Fixed Fixed::operator-(const Fixed &cpy) const {
	Fixed res;
	res.setRawBits(_value - cpy._value);
	return res;
}

Fixed Fixed::operator*(const Fixed &cpy) const {
	long long product = static_cast<long long>(_value) * cpy._value;
	Fixed res;
	res.setRawBits(static_cast<int>(product >> nb_bits));
	return res;
}

Fixed Fixed::operator/(const Fixed &cpy) const {
	if (cpy._value == 0) {
		std::cout << "try to div by zero." << std::endl;	
		return Fixed();
	}
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