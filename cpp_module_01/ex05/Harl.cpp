/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:36:36 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/06 11:19:33 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

void Harl::debug(void)
{
	std::cout <<"\"DEBUG\" level: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n";
	std::cout <<"I really do!.\n";
}

void Harl::info(void)
{
	std::cout <<"\"INFO\" level: I cannot believe adding extra bacon costs more money.\n";
	std::cout <<"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!.\n";
}
void Harl::warning(void)
{
	std::cout <<"\"WARNING\" level: I think I deserve to have some extra bacon for free.\n";
	std::cout <<"I’ve been coming for years whereas you started working here since last month.\n";
}
void Harl::error(void)
{
	std::cout <<"\"ERROR\" level: This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
	void (Harl::*complain[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	Harl mem;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for(int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			((mem.*complain[i])());
	}
}