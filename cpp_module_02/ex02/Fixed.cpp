/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:40:58 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/28 15:48:30 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed() : num_value(0){}

Fixed::Fixed(const int value) : num_value(value << fractional_bits){}

Fixed::Fixed(const float value) : num_value(static_cast<int>(roundf(value * (1 << fractional_bits)))){}

Fixed::Fixed(const Fixed &mem)
{
	this->num_value = mem.num_value;
}

int Fixed::getRawBits( void ) const
{
	return (this->num_value);
}

void Fixed::setRawBits( const int raw )
{
	this->num_value = raw;
}

int Fixed::toInt( void ) const
{
	return (this->num_value >> fractional_bits);
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->num_value) / (1 << fractional_bits));
}

Fixed &Fixed::operator=(const Fixed &mem)
{
	if (this == &mem)
		return (*this);
	this->num_value = mem.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &mem) const
{
	return (this->num_value > mem.num_value);
}

bool Fixed::operator<(const Fixed &mem) const
{
	return (this->num_value < mem.num_value);
}

bool Fixed::operator==(const Fixed &mem) const
{
	return (this->num_value == mem.num_value);
}

bool Fixed::operator!=(const Fixed &mem) const
{
	return (this->num_value != mem.num_value);
}

bool Fixed::operator>=(const Fixed &mem) const
{
	return (this->num_value >= mem.num_value);
}
bool Fixed::operator<=(const Fixed &mem) const
{
	return (this->num_value <= mem.num_value);
}

Fixed Fixed::operator+(const Fixed &mem) const
{
	return (this->toFloat() + mem.toFloat());
}

Fixed Fixed::operator-(const Fixed &mem) const
{
	return (this->toFloat() - mem.toFloat());
}

Fixed Fixed::operator*(const Fixed &mem) const
{
	return (this->toFloat() * mem.toFloat());
}

Fixed Fixed::operator/(const Fixed &mem) const
{
	return (this->toFloat() / mem.toFloat());
}

Fixed &Fixed::operator++()
{
	this->num_value += 1;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->num_value -= 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->num_value += 1;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->num_value -= 1;
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

Fixed::~Fixed(){}