/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:35:50 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/27 22:38:42 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "Fixed.h"

class Fixed
{
	private:
		int num_value;
		static const int fractional_bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &obj);
		
		int getRawBits( void ) const;
		void setRawBites( int const raw );
		
		Fixed &operator=(const Fixed& mem);
		
		~Fixed(void);
};

#endif