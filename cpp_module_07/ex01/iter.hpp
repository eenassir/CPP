/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:51:01 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/28 13:02:52 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T, typename S, typename G>
void iter(T *Array, S length, G func)
{	
	S i = 0;
	
	for(; i < length; i++)
		func(Array[i]);
}

#endif