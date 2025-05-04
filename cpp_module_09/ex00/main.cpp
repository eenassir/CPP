/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:19:46 by eenassir          #+#    #+#             */
/*   Updated: 2025/05/04 12:08:59 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>

void parce_input(std::string &buffer)
{
	int i = 0;
	if (buffer[i] >= '0' && buffer[i] <= '9')
	{	
		for(;buffer[i] && i < 4; i++)
		{
			if (!(buffer[i] >= '0' && buffer[i] <= '9'))
				throw std::runtime_error("Error: bad input => " + buffer);
		}
		if (buffer[i + 1] == '\0')
			throw std::runtime_error("Error: bad input => " + buffer);
		i++;
		int k  =  i;
		
		for (; buffer[i] && i < k + 2; i++)
		{
			if (!(buffer[i] >= '0' && buffer[i] <= '9'))
			{
				throw std::runtime_error("Error: bad input => " + buffer);
			}
		}
		if (buffer[i + 1] == '\0')
			throw std::runtime_error("Error: bad input => " + buffer);
		i++;
		k = i;
		
		for (; buffer[i] && i < k + 2; i++)
		{
			if (!(buffer[i] >= '0' && buffer[i] <= '9'))
			{
				throw std::runtime_error("Error: bad input => " + buffer);
			}
		}
		if (buffer[i] == '\0')
			throw std::runtime_error("Error: bad input => " + buffer);
		if (buffer[i + 1] != '|')
			throw std::runtime_error("Error: bad input => " + buffer);
		i++;
		if (buffer[i + 1] != ' ')
			throw std::runtime_error("Error: bad input => " + buffer);
		i++;
		if (buffer[i + 1] == '-')
			throw std::runtime_error("Error: not a positive number.");
		if (!(buffer[i + 1] >= '0' && buffer[i + 1] <= '9'))
			throw std::runtime_error("Error: bad input => " + buffer);
	}
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ac != 2)
	{
		std::cout <<"Error: could not open file."<<std::endl;
		return (1);
	}
	std::ifstream infile(av[1]);
	if (infile.fail())
	{
		std::cout <<"Error: could not open file."<<std::endl;
		return (1);
	}
	std::string buffer;
	while (std::getline(infile, buffer))
	{
		if ((buffer[0] >= '0' && buffer[0] <= '9'))
		{
			try
			{
				parce_input(buffer);
				std::cout <<buffer<<std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() <<std::endl;
			}
		}
	}
}