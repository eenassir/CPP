/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:11:40 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/28 11:51:37 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed area(const Point &a, const Point &b, const Point &c)
{
	return (a.getx() * (b.gety() - c.gety()) + 
			b.getx() * (c.gety() - a.gety()) + 
			c.getx() * (a.gety() - b.gety())) / Fixed(2);
}

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point)
{
	Fixed mainArea = area(a, b, c);

	Fixed area1 = area(point, a, b);
	Fixed area2 = area(point, b, c);
	Fixed area3 = area(point, c, a);

	if (area1 <= Fixed(0) || area2 <= Fixed(0) || area3 <= Fixed(0))
		return (0);
	return (area1 + area2 + area3) == mainArea;
}