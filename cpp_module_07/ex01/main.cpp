/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:37:52 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/28 13:03:06 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template<typename MyType>
void function(MyType const &a)
{
	std::cout <<a<<" ";
}

int main()
{
	int array1[] = {0, 1, 2, 3, 4};
	
	std::cout <<"Type of the array :int>"<<std::endl;
	iter(array1, 5, function<int>);
	std::cout <<std::endl;
	std::cout <<std::endl;
	
	float array2[] = {0.5f, 1.35f, 3.14f, 1.0f};
	
	std::cout <<"Type of the array :float>"<<std::endl;
	iter(array2, 4, function<float>);
	std::cout <<std::endl;
	std::cout <<std::endl;
	
	char array3[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w','o', 'r', 'l', 'd', '!'};
	
	std::cout <<"Type of the array :char>"<<std::endl;
	iter(array3, 12, function<char>);
	std::cout <<std::endl;
	std::cout <<std::endl;
	
	std::string array4[] = {"arc", "cercle", "cub", "triangle"};
	
	std::cout <<"Type of the array :std::string>"<<std::endl;
	iter(array4, 4, function<std::string>);
	std::cout <<std::endl;
	std::cout <<std::endl;
	
	double array5[] = {2.2, 2.5, 3.5};
	
	std::cout <<"Type of the array :double>"<<std::endl;
	iter(array5, 3, function<double>);
	std::cout <<std::endl;
}