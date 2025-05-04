/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:27:24 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/29 18:13:06 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout <<std::endl;

	try
	{
        Span sp = Span(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

	try
	{
		Span numbers(10000);
		for (unsigned int i = 0; i < 10000; i++)
		{
			numbers.addNumber(i);
		}
		std::cout << numbers.shortestSpan() << std::endl;
		std::cout << numbers.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what()<<std::endl;
	}

	try
	{
		Span mem(10);
		std::vector<int> l;

		l.push_back(1);
		l.push_back(5);
		l.push_back(6);
		l.push_back(3);
		
		mem.addMultipleNbr(l);

		std::cout << mem.shortestSpan() << std::endl;
		std::cout << mem.longestSpan() << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() <<std::endl;
	}
	
	return 0;
}