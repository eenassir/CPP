/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:35:50 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/25 13:51:24 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "Fixed.h"

class Fixed
{
	private:
		int num;
		static const int cte = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &obj);
		Fixed & operator=(const Fixed& mem);
		int getRawBits(void) const;
		void setRawBites(int const raw);
		~Fixed(void);
};

#endif