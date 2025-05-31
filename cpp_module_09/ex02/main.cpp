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
#include <ctime>
#include <iomanip>
#include <sys/time.h>

template<typename T>
void g(T &list)
{
	typedef typename T::iterator iter;
	iter it = list.begin();

	for (; it != list.end(); it++)
	{
		std::cout <<*it<<" ";
	}
}

template<typename T>
void binary_insertion(T &vect, int nbr)
{
	size_t left, right, mid;

	left = 0;
	right = vect.size();

	while (left < right)
	{
		mid = (left + right) / 2;
		if (vect[mid] == nbr)
			break ;
		else if (vect[mid] < nbr)
			left = mid + 1;
		else
			right = mid;
	}
	vect.insert(vect.begin() + left, nbr);
}


template<typename T>
void merge(T & vect)
{
	if (vect.size() <= 2)
		return ;
	int tmp;
	bool odd = false;
	if (vect.size() % 2 != 0)
	{
		odd = true;
		tmp = vect.back();
		vect.pop_back();
	}
	std::vector< T > collect;
	typedef typename T::iterator itera;
	itera it;
	size_t size = vect.size() / 2, i = 0;
	while (i < size)
	{
		T k;
		k.push_back(vect.back());
		vect.pop_back();
		k.push_back(vect.back());
		vect.pop_back();
		collect.push_back(k);
		i++;
	}
	i = 0;
	for (; i <  collect.size(); i++)
	{
		if (collect[i][0] < collect[i][1])
		{
			int tmp = collect[i][0];
			collect[i][0] = collect[i][1];
			collect[i][1] = tmp;
		}
	}
	T main_chain;
	T pain_chain;
	i = 0;
	typedef typename  std::vector< T >::iterator itter;
	itter itt = collect.begin();
	for (; itt != collect.end(); itt++)
	{
		pain_chain.push_back(itt->back());
		itt->pop_back();
		main_chain.push_back(itt->back());
		itt->pop_back();
	}
	merge(main_chain);
	if (main_chain.size() == 2 && (main_chain[0] > main_chain[1]))
	{
		int tmp = main_chain[0];
		main_chain[0] = main_chain[1];
		main_chain[1] = tmp;
	}
	it = pain_chain.begin();
	for (; it != pain_chain.end(); it++)
		binary_insertion(main_chain, *it);
	if (odd == 1)
		binary_insertion(main_chain, tmp);
	vect = main_chain;
}

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
	std::cout <<"Before : ", g(cont_v), std::cout<<std::endl;
	timeval start, end;

	gettimeofday(&start, NULL);
	merge(cont_v);
	gettimeofday(&end, NULL);
	double dur_us = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
	std::cout <<"After : ", g(cont_v), std::cout<<std::endl;
	std::cout <<"Time to process a range of "<<cont_v.size()<<" element with std::vector<int> : "<<std::fixed<<std::setprecision(5)<<dur_us<<"us"<<std::endl;

	gettimeofday(&start, NULL);
	merge(cont_d);
	gettimeofday(&end, NULL);
	dur_us = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
	std::cout <<"Time to process a range of "<<cont_d.size()<<" element with std::deque<int> : "<<std::fixed<<std::setprecision(5)<<dur_us<<"us"<<std::endl;
}