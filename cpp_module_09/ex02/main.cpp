/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:22:17 by eenassir          #+#    #+#             */
/*   Updated: 2025/05/22 11:22:12 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <deque>
#include <vector>

int main(int ac, char **av)
{
	if (ac <= 1)
		return (std::cerr <<"Error"<<std::endl, 1);
	std::string buffer(av[1]);
	for (size_t i = 2; av[i] ; i++)
	{
		buffer.push_back(' ');
		for(size_t j = 0; av[i][j]; j++)
			buffer.push_back(av[i][j]);
	}
	for (size_t i = 0; i < buffer.size(); i++)
	{
		if (!(buffer[i] >= '0' && buffer[i] <= '9') && (buffer[i] != ' ' && buffer[i] != '+'))
			return (std::cerr<<"Error"<<std::endl, 1);
		if (buffer[i] == '+' && buffer[i + 1] == '+')
			return (std::cerr<<"Error"<<std::endl, 1);
		if ((buffer[i] >= '0' && buffer[i] <= '9') && buffer[i + 1] == '+')
			return (std::cerr<<"Error"<<std::endl, 1);
	}
	for (size_t i = 0; i < buffer.size(); i++)
		(buffer[i] == '+') && (buffer[i] = ' ');
	std::stringstream tmp;
	int nbr, count;
	std::deque<int> cont_d;
	std::vector<int> cont_v;
	for (size_t i = 0; i < buffer.size(); i++)
	{
		count = 0;
		for (; buffer[i] && buffer[i] == ' '; i++){}
		size_t s = i;
		for(; buffer[s] && (buffer[s] >= '0' && buffer[s] <= '9'); s++, count++){}
		char buffer_tmp[count + 1];
		size_t y = 0;
		for (; buffer[i] && (buffer[i] >= '0' && buffer[i] <= '9'); i++, y++)
			buffer_tmp[y] = buffer[i];
		buffer_tmp[y] = '\0';
		tmp.clear();
		std::string ll(buffer_tmp);
		tmp << ll;
		tmp >> nbr;
		if (tmp.fail())
			return (std::cerr<<"Error"<<std::endl, 1);
		cont_d.push_back(nbr);
		cont_v.push_back(nbr);
	}

	std::deque<int>::iterator it_d;
	std::vector<int>::iterator it_v;

	it_v = cont_v.begin();

	std::vector< std::vector<int> > contt;

	contt.push_back(cont_v);

	std::vector< std::vector<int> >::iterator itt;

	int tab[7] = {1, 2, 5, 3, 9, 7, 0};

	int i = 0;
	for (; i < 7 / 2; i++)
	{
		std::cout <<tab[i]<<std::endl;
	}
	std::cout <<"---------------"<<std::endl;
	for (;i < 7; i++ )
	{
		std::cout <<tab[i]<<std::endl;
	}
}