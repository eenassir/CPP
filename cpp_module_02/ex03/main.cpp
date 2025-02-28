/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:11:51 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/28 11:54:54 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

std::ostream &operator<<(std::ostream &os, const Fixed &mem)
{
	os << mem.toFloat();
	return (os);
}

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point point(1, 1);
    std::cout << "Is point inside the triangle? " << (bsp(a, b, c, point) ? "Yes" : "No") << std::endl;
    Point point2(10, 10);
    std::cout << "Is point2 inside the triangle? " << (bsp(a, b, c, point2) ? "Yes" : "No") << std::endl;
    Point point3(0, 0);
    std::cout << "Is point3 inside the triangle? " << (bsp(a, b, c, point3) ? "Yes" : "No") << std::endl;

    return 0;
}