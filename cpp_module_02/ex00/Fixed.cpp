/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:35:53 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/25 13:53:40 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed()
{
	std::cout <<"Default constructor called\n";
	num = 0;
}

Fixed::Fixed(const Fixed& mem)
{
	std::cout <<"Copy constructor called\n";
	*this = mem;
	
}
Fixed & Fixed::operator=(const Fixed& mem)
{
	std::cout << "Copy assignment operator called\n";
	if ( this == &mem)
		return *this;
	this->num = mem.getRawBits();
	return *this;
}


int Fixed::getRawBits(void) const
{
	std::cout <<"getRawBits member function called\n";
	return (num);
}

void Fixed::setRawBites(int const raw)
{
	num = raw;
}

Fixed::~Fixed()
{
	std::cout <<"Destructor called\n";
}