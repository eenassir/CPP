/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:35:50 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/13 23:33:12 by eenassir         ###   ########.fr       */
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
		Fixed(void)
		{
			num = 0;
		}
		Fixed(const Fixed &obj)
		{
			num = obj.num;
		}
		int getRawBits(void) const
		{
			return (num);
		}
		void setRawBites(int const raw)
		{
			num = raw % 8;
		}
		~Fixed(void)
		{};
		
	
};

#endif