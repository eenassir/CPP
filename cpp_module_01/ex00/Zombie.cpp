/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:45:55 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/27 13:15:31 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::~Zombie(void)
{
	std::cout<<"* \""<<name<<"\" is destroyed.\n";
}

void Zombie::announce(void)
{
	if (name == "FOO")
		std::cout<<name<<":BraiiiiiiinnnzzzZ...\n";
	else
		std::cout<<"<"<<name<<">:BraiiiiiiinnnzzzZ...\n";
}

void  Zombie::get_name(std::string na)
{
	name = na;
}