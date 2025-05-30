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

// template<typename T>
void g(std::vector<int> &list)
{
	// typedef typename T::iterator iter;
	// iter it = list.begin();

	// for (; it != list.end(); it++)
	// {
	// 	std::cout <<*it<<std::endl;
	// }
	std::vector< std::vector<int> > l;
	l.push_back(list);
	std::cout << *l.begin()->begin();

	// l.push_back(list);
	// std::cout <<l.begin()->back();
}

void binary_insertion(std::vector<int> &vect, int nbr)
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

void merge(std::vector<int> & vect)
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
	std::vector< std::vector<int> > collect;
	std::vector<int>::iterator it;
	size_t size = vect.size() / 2, i = 0;
	while (i < size)
	{
		std::vector<int> k;
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
	std::vector<int> main_chain;
	std::vector<int> pain_chain;
	i = 0;
	std::vector< std::vector<int> >::iterator itt = collect.begin();
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
	merge(cont_v);
	g(cont_v);
	// g(cont_d);
}