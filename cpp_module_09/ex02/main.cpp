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

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	std::deque<int> cont_d;
	std::vector<int> cont_v;

	if (ac <= 1)
		return (std::cerr <<"Error"<<std::endl, 1);
	if (PmergeMe::parce_input(av, cont_v, cont_d) == 1)
		return (1);
	std::cout <<"\033[1;31mBefore : ";
	PmergeMe::display_list(cont_v);
	std::cout<<"\033[0m"<<std::endl;
	timeval start, end;

	gettimeofday(&start, NULL);
	PmergeMe::merge(cont_v);
	gettimeofday(&end, NULL);
	double dur_us = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
	std::cout <<std::endl<<"\033[1;32m"<<"After : ";
	PmergeMe::display_list(cont_v);
	std::cout<<"\033[0m"<<std::endl<<std::endl;
	std::cout <<"\033[1;36mTime to process a range of "<<cont_v.size()<<" element with std::vector : "<<std::fixed<<std::setprecision(5)<<dur_us<<"us\033[0m"<<std::endl;

	gettimeofday(&start, NULL);
	PmergeMe::merge(cont_d);
	gettimeofday(&end, NULL);
	dur_us = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
	std::cout <<"\033[1;33mTime to process a range of "<<cont_d.size()<<" element with std::deque : "<<std::fixed<<std::setprecision(5)<<dur_us<<"us\033[0m"<<std::endl;
}