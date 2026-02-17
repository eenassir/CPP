/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:58:18 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/08 23:00:37 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main(int ac, char **av)
{
	Harl obj;
	std::string str;

	if (ac != 2)
		return (std::cout <<"ERROR USAGE: ./harlFilter \"arg\"\n", 1);
	str = av[1];
	obj.complain(str);
}