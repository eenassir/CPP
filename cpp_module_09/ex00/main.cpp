/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:19:46 by eenassir          #+#    #+#             */
/*   Updated: 2025/05/06 10:28:15 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <list>

double parce_input(std::string &buffer)
{
	int i = 0;
	double res = -1;
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
		i++;
		std::stringstream tmp;
		for(;buffer[i]; i++)
		{
			if (buffer[i] == '.' && (buffer[i + 1] && buffer[i + 1] == '.'))
				throw std::runtime_error("Error: bad input => " + buffer);
			if (!(buffer[i] >= '0' && buffer[i] <= '9') && buffer[i] != '.')
				throw std::runtime_error("Error: bad input => " + buffer);
			tmp << buffer[i];
		}
		tmp >> res;
		if (tmp.fail())
			throw std::runtime_error("Error: bad input => " + buffer);
		if (res > 1000)
			throw std::runtime_error("Error: too large a number");
	}
	return (res);
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
		std::map<int,double> vect;

		if ((buffer[0] >= '0' && buffer[0] <= '9'))
		{
			try
			{
				double tmp;
				if ((tmp = parce_input(buffer)) != -1)
					vect.insert(std::pair(1, 1.2));
				std::cout <<buffer<<std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() <<std::endl;
			}
		}
	}
}