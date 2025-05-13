/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:21:26 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/30 09:50:08 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <algorithm>
#include <list>
#include <sstream>
#include <iomanip>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr<<"Error"<<std::endl;
		return(1);
	}
	std::string str = av[1];
	if (str.size() == 0)
	{
		std::cerr<<"Error"<<std::endl;
		return(1);
	}
	if (!(str[0] >= '0' && str[0] <= '9'))
	{
		std::cerr<<"Error"<<std::endl;
		return (1);
	}
	std::list<int> lst;
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
		{
			std::cerr<<"Error"<<std::endl;
			return (1);
		}
		if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] && (str[i + 1] >= '0' && str[i + 1] <= '9')))
		{
			std::cerr<<"Error"<<std::endl;
			return (1);
		}
	}

	size_t i = 1;
	size_t count = 0;

	for (; i < str.size(); i++)
	{
		if (str[i] == ' ')
			count++;
	}
	char c[str.size() - count + 2];

	size_t j = 0;
	c[j] = av[1][0];
	j++;
	for (size_t i = 2; i < str.size(); i++)
	{
		if ((av[1][i] >= '0' && av[1][i] <= '9') && (av[1][i + 2] >= '0' && av[1][i + 2] <= '9'))
			av[1][i + 1] = '+';
		if (av[1][i] != ' ')
		{
			c[j] = av[1][i];
			j++;
		}
	}
	c[j] = '\0';
	size_t ll = 0;
	for (int w = 0; c[w]; w++)
	{
		if ((c[w] == '*' && c[w + 1] == '/') || (c[w] == '/' && c[w + 1] == '*'))
		{
			std::cerr<<"Error"<<std::endl;
			return (1);
		}
		if ((c[w] == '+' && c[w + 1] == '+') || (c[w] == '-' && c[w + 1] == '-'))
		{
			std::cerr<<"Error"<<std::endl;
			return (1);
		}
		if ((c[w] == '+' && c[w + 1] == '-' && c[w + 2] == '+') || (c[w] == '-' && c[w + 1] == '+' && c[w + 2] == '-'))
		{
			std::cerr<<"Error"<<std::endl;
			return (1);
		}
	}
	for (; c[ll]; ll++)
	{
		if ((c[ll] == '+' && c[ll + 1] == '-') || (c[ll] == '-' && c[ll + 1] == '+'))
		{
			c[ll] = '-';
			c[ll + 1] = ' ';
		}
	}
	for(size_t k = 0; c[k]; k++)
	{
		if (c[k] != ' ')
		{
			if (c[k] >= '0' && c[k] <= '9')
			lst.push_back(c[k] - 48);
			else
			lst.push_back(c[k]);
		}
	}
	std::list<int>::iterator it;

	it = lst.begin();
	int result = *it;
	it++;

	for (; it != lst.end(); it++)
	{
		if (*it == '+')
		{
			it--;
			result += *it;
			it++;
		}
		if (*it == '-')
		{
			it--;
			result -= *it;
			it++;
		}
		if (*it == '*')
		{
			it--;
			result *= *it;
			it++;
		}
		if (*it == '/')
		{
			it--;
			result /= *it;
			it++;
		}
	}
	std::cout<<result<<std::endl;
}
