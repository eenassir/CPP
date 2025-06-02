/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:46:20 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/30 09:46:21 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::parce_input(char **av, std::vector<int> &cont_v, std::deque<int> &cont_d)
{
	std::string buffer(av[1]);
	for (size_t i = 2; av[i] ; i++)
	{
		buffer.push_back(' ');
		for(size_t j = 0; av[i][j]; j++)
		{
			buffer.push_back(av[i][j]);
		}
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
	for (size_t i = 0; i < buffer.size(); i++)
	{
		count = 0;
		for (; buffer[i] && buffer[i] == ' '; i++)
		{}
		size_t s = i;
		for(; buffer[s] && (buffer[s] >= '0' && buffer[s] <= '9'); s++, count++)
		{}
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
	for (size_t i = 0; i < cont_v.size(); i++)
	{
		size_t j = i + 1;
		for (; j < cont_v.size(); j++)
		{
			if (cont_v[i] == cont_v[j])
			{
				std::cout <<"Error"<<std::endl;
				return (1);
			}
		}
	}
	return (0);
}

std::vector<size_t> PmergeMe::generate_jacobsthal_sequence(size_t n)
{
	std::vector<size_t> jacobsthal;
    if (n == 0)
		return (jacobsthal);
    jacobsthal.push_back(1);
    if (n == 1)
        return (jacobsthal);
    jacobsthal.push_back(3);
    while (jacobsthal.back() < n)
    {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next > n)
            break ;
        jacobsthal.push_back(next);
    }
    return (jacobsthal);
}

std::vector<size_t> PmergeMe::generate_insertion_order(size_t n)
{
    if (n == 0)
        return (std::vector<size_t>());
    std::vector<size_t> jacobsthal = generate_jacobsthal_sequence(n);
    std::vector<size_t> insertion_order;
    std::vector<bool> used(n + 1, false);

    size_t prev = 1;
    for (size_t i = 1; i < jacobsthal.size(); i++)
    {
        size_t current = jacobsthal[i];
        if (current > n)
            current = n;
        for (size_t j = current; j > prev ; j--)
        {
            if (j <= n && !used[j])
            {
                insertion_order.push_back(j - 1);
                used[j] = true;
            }
        }
        prev = current;
    }
    for (size_t i = 1; i <= n; i++)
    {
        if (!used[i])
            insertion_order.push_back(i - 1);

    }
    return (insertion_order);
}

