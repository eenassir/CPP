/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:19:46 by eenassir          #+#    #+#             */
/*   Updated: 2025/05/07 10:39:14 by eenassir         ###   ########.fr       */
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
#include <algorithm>

double parce_input(std::string &buffer)
{
	int i = 0;
	double res = -1;
	if (buffer[i] >= '0' && buffer[i] <= '9')
	{	
		for(;buffer[i] && i < 4; i++)
		{
			if (!(buffer[i] >= '0' && buffer[i] <= '9'))
			{
				std::cout <<"Error: bad input => " + buffer<<std::endl;
				return (-1);
			}	
		}
		
		if (buffer[i + 1] == '\0')
		{
			std::cout <<"Error: bad input => " + buffer<<std::endl;
			return (-1);
		}
		i++;
		int k  =  i;
		
		for (; buffer[i] && i < k + 2; i++)
		{
			if (!(buffer[i] >= '0' && buffer[i] <= '9'))
			{
				std::cout << "Error: bad input => " + buffer<<std::endl;
				return (-1);
			}
		}
		if (buffer[i + 1] == '\0')
		{
			std::cout <<"Error: bad input => " + buffer<<std::endl;
			return (-1);
		}
		
		i++;
		k = i;
		
		for (; buffer[i] && i < k + 2; i++)
		{
			if (!(buffer[i] >= '0' && buffer[i] <= '9'))
			{
				std::cout << "Error: bad input => " + buffer<<std::endl;
				return (-1);
			}
		}
		if (buffer[i] == '\0')
		{
			std::cout << "Error: bad input => " + buffer<<std::endl;
			return (-1);
		}
		if (buffer[i + 1] != '|')
		{
			std::cout << "Error: bad input => " + buffer<<std::endl;
			return (-1);
		}
		i++;
		if (buffer[i + 1] != ' ')
		{
			std::cout << "Error: bad input => " + buffer<<std::endl;
			return (-1);
		}
		i++;
		if (buffer[i + 1] == '-')
		{
			std::cout << "Error: not a positive number."<<std::endl;
			return (-1);
		}
		i++;
		std::stringstream tmp;
		for(;buffer[i]; i++)
		{
			if (buffer[i] == '.' && (buffer[i + 1] && buffer[i + 1] == '.'))
			{
				std::cout << "Error: bad input => " + buffer<<std::endl;
				return (-1);
			}
			if (!(buffer[i] >= '0' && buffer[i] <= '9') && buffer[i] != '.')
			{
				std::cout << "Error: bad input => " + buffer<<std::endl;
				return (-1);
			}
			tmp << buffer[i];
		}
		tmp >> res;
		if (tmp.fail())
			std::cout << "Error: bad input => " + buffer<<std::endl;
		if (res > 1000)
		{
			res = -1;
			std::cout << "Error: too large a number"<<std::endl;
		}
	}
	return (res);
}

std::map<std::string, double> load_data(void)
{
	std::ifstream infile("data.csv");
	if (infile.fail())
		std::cout <<"Error to open file";
	std::map<std::string, double> map;
	std::string buffer;
	while (getline(infile, buffer))
	{
		if (buffer[0] >= '0' && buffer[0] <= '9')
		{
			int i = 0;
			char tmp[11];
			for(; buffer[i] && buffer[i] != ','; i++)
				tmp[i] = buffer[i];
			tmp[i] = '\0';
			if (buffer[i] == ',')
				i++;
			std::stringstream stmp;
			double value;
			for (;buffer[i];i++)
			{
				if ((buffer[i] >= '0' && buffer[i] <= '9') || buffer[i] == '.')
					stmp << buffer[i];
			}
			stmp >> value;
			std::string key = tmp;
			map.insert(std::make_pair(key, value));
		}
	}
	return (map);
}

int main(int ac, char **av)
{
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
	std::map<std::string, double> map;
	std::map<std::string, double>::iterator it;
	map = load_data();
	double res = -1;
	while (std::getline(infile, buffer))
	{
		if ((buffer[0] >= '0' && buffer[0] <= '9'))
		{
			res = parce_input(buffer);
			if (res != -1)
			{
				char tmp[11];
				std::string tmp_buff;
				int j = 0;
				for (int i = 0; buffer[i] && buffer[i] != ' ' ; i++)
				{
					if ((buffer[i] >= '0' && buffer[i] <= '9') || buffer[i] == '-')
					{
						tmp[j] = buffer[i];
						j++;
					}
				}
				tmp[j] = '\0';
				std::string str(tmp);
				std::map<std::string, double>::iterator it = map.find(str);
				if (it == map.end())
				{
					
				}
				else if (it != map.end())
					std::cout <<str<<" => "<<res<<" = "<<res * it->second<<std::endl;
			}
		}
	}
}