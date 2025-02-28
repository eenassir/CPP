/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:11:49 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/27 22:47:46 by eenassir         ###   ########.fr       */
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
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &mem);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		int toInt( void ) const;
		float toFloat( void ) const;
		
		Fixed &operator=(const Fixed &mem);

		bool operator>(const Fixed &mem) const;
		bool operator<(const Fixed &mem) const;
		bool operator>=(const Fixed &mem) const;
		bool operator<=(const Fixed &mem) const;
		bool operator==(const Fixed &mem) const;
		bool operator!=(const Fixed &mem) const;
		
		Fixed operator+(const Fixed &mem) const;
		Fixed operator-(const Fixed &mem) const;
		Fixed operator*(const Fixed &mem) const;
		Fixed operator/(const Fixed &mem) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		~Fixed();
};

#endif