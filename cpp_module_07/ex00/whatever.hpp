/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:24:14 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/16 00:51:10 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYCLASS_HPP
# define MYCLASS_HPP

#include <iostream>

template<typename T>
void swap(T &x, T &y){
	T tmp;
	
	tmp = x;
	x = y;
	y = tmp;	
}

template<typename T>
T max(T x, T y){
	return ((x > y) ? x : y);	
}

template<typename T>
T min(T x, T y){
	return ((x < y) ? x : y);
}
	
#endif