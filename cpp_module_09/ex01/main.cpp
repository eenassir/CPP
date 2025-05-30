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



int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr<<"Error"<<std::endl;
		return(1);
	}
	std::list<int> lst;
	if (RPN::parce_input(av, lst))
		return(1);
	RPN::rpn(lst);

}
