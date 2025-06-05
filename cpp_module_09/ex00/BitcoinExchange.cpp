/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:20:30 by eenassir          #+#    #+#             */
/*   Updated: 2025/06/05 09:57:17 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

double BitcoinExchange::parce_input(std::string &buffer)
{
	int i = 0;
	double res = -1;
	std::string d("0000");
	std::stringstream kk;
	int u;
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
		if (buffer[i] == '+')
		{
			i++;
		}
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

std::map<std::string, double> BitcoinExchange::load_data(std::ifstream &infile)
{
	std::map<std::string, double> map;
	std::string buffer;
	std::string buffer_i;

	getline(infile, buffer_i);
	if (buffer_i.size() == 0)
	{
		return (std::map<std::string, double>());
	}
	if (buffer_i != "date,exchange_rate")
	{
		return (std::map<std::string, double>());
	}

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

int BitcoinExchange::Btc(char* av)
{
	std::ifstream infile(av);
	if (infile.fail())
	{
		std::cout <<"Error: could not open file."<<std::endl;
		return (1);
	}
	std::string buffer;

	std::map<std::string, double> map;
	std::map<std::string, double>::iterator it;

	std::ifstream indata("data.csv");
	if (indata.fail())
	{
		std::cout <<"Error : could not to open file"<<std::endl;
		return (1);
	}
	map = load_data(indata);
	if (map.size() == 0)
	{
		std::cout <<"Error: invalid data file"<<std::endl;
		return (1);
	}
	double res = -1;
	std::string buffer_i;
	std::getline(infile, buffer_i);
	if (buffer_i.size() == 0)
	{
		std::cout <<"Error: empty file"<<std::endl;
		return (1);
	}
	if (buffer_i != "date | value")
	{
		std::cout <<"Error: invalid file"<<std::endl;
		return (1);
	}
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
    return (0);
}