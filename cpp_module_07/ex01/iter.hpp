/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:51:01 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/27 23:13:08 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename MyType>
void function(MyType a)
{
	std::cout <<a<< " ";
}

template<typename T>
void iter(T *Array, int length, void (&func)(T const&))
{
	int i = 0;

	for(; i < length; i++)
	{
		func(Array[i]);
	}
}

#endif