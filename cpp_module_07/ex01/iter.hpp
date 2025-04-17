/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:51:01 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/16 20:48:05 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename MyType>

void iter(MyType Array, int length, int (*func)(MyType ))
{
	for (int i ; i < length; i++)
	{
		std::cout <<func(array[i])<<std::endl;
	}
}

#endif