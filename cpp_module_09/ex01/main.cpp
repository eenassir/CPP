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
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <stack>
#include <string>
#include <list>

int main(int ac, char **av)
{
	std::list<std::string> strs;
	std::stack<int> holder;

    if (ac != 2)
    {
        std::cerr<<"Error"<<std::endl;
        return (1);
    }
    std::string str= av[1];
    if (!str.size())
    {
        std::cerr<<"Error"<<std::endl;
        return (1);
    }
    if (RPN::parce_input(str, strs) == 1)
		return (1);
	if (RPN::rpn(strs, holder) == 1)
		return (1);
    if (holder.size() != 1)
    {
        std::cerr<<"Error"<<std::endl;
        return (1);
    }
    std::cout <<"\033[1;31m"<<holder.top()<<"\033[0m"<<std::endl;
    return (0);
}