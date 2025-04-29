/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:19:44 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/29 10:05:00 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <set>
#include <algorithm>

int main()
{
	try
	{
		std::vector<int> array1;
		std::cout <<"using vector container: "<<std::endl;
		array1.push_back(1);
		array1.push_back(99);
		array1.push_back(7);
		array1.push_back(1);
		array1.push_back(24);
		array1.push_back(9);

		std::deque<int> array2;
		std::cout <<"using deque container: "<<std::endl;
		array2.push_back(18);
		array2.push_back(1);
		array2.push_back(5);
		array2.push_back(1);
		array2.push_back(2);
		array2.push_back(9);
		
		easyfind(&array1, 1);
		easyfind(&array2, 1);
	}
	catch(const std::exception& e)
	{
		std::cout <<e.what()<<std::endl;
	}
}