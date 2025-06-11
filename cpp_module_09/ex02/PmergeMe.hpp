/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:46:24 by eenassir          #+#    #+#             */
/*   Updated: 2025/06/11 21:30:15 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <deque>
#include <vector>
#include <ctime>   
#include <iomanip>
#include <sys/time.h>

class PmergeMe
{
    private:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
    public:
        template<typename T>
        static void binary_insertion(T &vect, int nbr);

        template<typename T>
        static void display_list(T &list);

        template<typename T>
        static void merge(T & vect);

        static int parce_input(char **av, std::vector<int> &cont_v, std::deque<int> &cont_d);
        static std::vector<size_t> generate_insertion_order(size_t n);
        static std::vector<size_t> generate_jacobsthal_sequence(size_t n);
};

template<typename T>
void PmergeMe::display_list(T &list)
{
	typedef typename T::iterator iter;
	iter it = list.begin();

	for (; it != list.end(); it++)
		std::cout <<*it<<" ";
}

template<typename T>
void PmergeMe::binary_insertion(T &vect, int nbr)
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
void PmergeMe::merge(T & vect)
{
	if (vect.size() < 2)
	{
		return ;
	}
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
	if (!pain_chain.empty())
	{
		std::vector<size_t> insertion_order = generate_insertion_order(pain_chain.size());
		for (size_t j = 0; j < insertion_order.size(); j++)
		{
			size_t idx = insertion_order[j];
			if (idx < pain_chain.size())
			    binary_insertion(main_chain, pain_chain[idx]);
		}
	}
	if (odd == 1)
	binary_insertion(main_chain, tmp);
	vect = main_chain;
}

#endif