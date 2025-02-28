/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:11:54 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/28 11:40:21 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Point::Point() : x(0), y(0){}

Point::Point(const float a, const float b) : x(a), y(b) {}

Point &Point::operator=(const Point &mem)
{
	if (this == &mem)
		return (*this);
	return (*this);
}

Point ::Point(const Point &mem) : x(mem.x), y(mem.y) {}

Fixed Point::getx() const
{
	return (x);
}

Fixed Point::gety() const
{
	return (y);
}

Point::~Point(){}