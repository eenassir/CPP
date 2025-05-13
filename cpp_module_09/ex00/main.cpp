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
	std::string d("0000");
	std::stringstream kk;
	int u;
	if (buffer == "date | value")
		return (-1);
	if (!(buffer[i] >= '0' && buffer[i] <= '9'))
	{
		std::cout <<"Error: bad input => " + buffer<<std::endl;
		return (-1);
	}
	if (buffer[i] >= '0' && buffer[i] <= '9')
	{
		int j = 0;
		for(;buffer[i] && i < 4; i++)
		{
			d[j] = buffer[i];
			j++;
			if (!(buffer[i] >= '0' && buffer[i] <= '9'))
			{
				std::cout <<"Error: bad input => " + buffer<<std::endl;
				return (-1);
			}
		}
		kk << d;
		kk >> u;
		if (u < 2009)
		{
			std::cout <<"Error: bad input => " + buffer<<std::endl;
			return (-1);
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
	return(res);
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
			bool flag = false;
			if (it != map.end())
				std::cout <<tmp<<" => "<<res<<" = "<<res * it->second<<std::endl;
			else if (it == map.end())
			{
				while (str[0] != '0' - 1)
				{
					while(str[5] != '0' - 1)
					{
						while (str[8] != '0' - 1)
						{
							it = map.find(str);
							if (it != map.end())
							{
								std::cout <<tmp<<" => "<<res<<" = "<<res * it->second<<std::endl;
								flag = true;
								break ;
							}
							str[9]--;
							if (str[9] == '0' - 1)
							{
								str[9] = '9';
								str[8]--;
							}
						}
						if (flag)
							break ;
						if (str[8] == '0' - 1)
						{
							str[8] = '3';
							str[9] = '1';
							str[6]--;
							if (str[6] == '0' - 1)
							{
								str[6] = '9';
								str[5]--;
							}
						}   
					}
					if (str[5] == '0' - 1)
					{
						str[6] = '2';
						str[5] = '1';
						str[3]--;
						if (str[3] == '0' - 1)
						{
							str[3] = '9';
							str[2]--;
							if (str[2] == '0' - 1)
							{
								str[2] = '9';
								str[1]--;
								if (str[1] == '0' - 1)
								{
									str[1] = '9';
									str[0]--;
								}
							}
						}
					}
					if(flag)
						break;
				}
			}
		}
		
	}
}