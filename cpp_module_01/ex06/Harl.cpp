/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:57:54 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/08 22:57:47 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout <<"[ DEBUG ]\nlevel: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n";
	std::cout <<"I really do!.\n\n";
}
void Harl::info(void)
{
	std::cout <<"[ INFO ]\nlevel: I cannot believe adding extra bacon costs more money.\n";
	std::cout <<"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!.\n\n";
}
void Harl::warning(void)
{
	std::cout <<"[ WARNING ]\nlevel: I think I deserve to have some extra bacon for free.\n";
	std::cout <<"I’ve been coming for years whereas you started working here since last month.\n\n";
}
void Harl::error(void)
{
	std::cout <<"[ ERROR ]\nlevel: This is unacceptable! I want to speak to the manager now.\n\n";
}
void Harl::complain(std::string level)
{
	int i = 0;
	void (Harl::*ptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	Harl mem;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4)
	{
		if (level == levels[i])
			break ;
		i++;
	}
	if (i < 4)
	{	
		while (i < 4)
		{
			(mem.*ptr[i])();
			i++;
		}
		return ;
	}
	std::cout <<"[ Probably complaining about insignificant problems ]\n";
}