/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:18:37 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/25 12:11:18 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HP
#define EASYFIND_HP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void easyfind(T* element, int nbr)
{	
	typename T::iterator it = std::find(element->begin(), element->end(), nbr);
	if (it != element->end())
	{
		std::cout <<"The first occurence position "<<nbr<<" is : "<<(it - element->begin()) + 1<<std::endl;
		return ;
	}
	else
		throw std::exception();
}

#endif