/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:35:53 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/28 15:48:03 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed() : num_value(0)
{
	std::cout <<"Default constructor called\n";
}

Fixed::Fixed(const Fixed &mem)
{
	std::cout <<"Copy constructor called\n";
	*this = mem;
}

Fixed &Fixed::operator=(const Fixed& mem)
{
	if (this == &mem)
		return *this;
	std::cout << "Copy assignment operator called\n";
	this->num_value = mem.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout <<"getRawBits member function called\n";
	return (num_value);
}

void Fixed::setRawBites( int const raw )
{
	this->num_value = raw;
}

Fixed::~Fixed()
{
	std::cout <<"Destructor called\n";
}