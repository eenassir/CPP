/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:38:55 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/28 15:53:13 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed() : num_value(0)
{
	std::cout <<"Default constructor called\n";	
}

int Fixed::getRawBits( void ) const
{
	std::cout <<"getRawBits member function called\n";
	return this->num_value;
}

Fixed &Fixed::operator=(const Fixed &mem)
{
	if (this == &mem)
		return (*this);
	std::cout <<"Copy assignment operator called\n";
	this->num_value = mem.num_value;
	return *this;
}

void Fixed::setRawBits( int const raw )
{
	this->num_value = raw;
}

Fixed::~Fixed()
{
	std::cout <<"Destructor called\n";
}

Fixed::Fixed(const int value) : num_value(value << fractional_bits)
{
	std::cout <<"Int constructor called\n";
}

Fixed::Fixed(const float value) : num_value(static_cast<int>(roundf(value * (1 << fractional_bits))))
{
	std::cout <<"Float constructor called\n";
}

Fixed::Fixed(const Fixed &mem)
{
	std::cout <<"Copy constructor called\n";
	*this = mem;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->num_value) / (1 << fractional_bits));
}

int Fixed::toInt( void ) const
{
	return (this->num_value >> fractional_bits);
}
