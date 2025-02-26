/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:39:01 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/25 22:45:02 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include "Fixed.h"

class Fixed
{
	private:
		int num_value;
		static const int fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &mem);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
		Fixed(const int param);
		Fixed(const float param);
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed &operator=(const Fixed &mem);
};

#endif
