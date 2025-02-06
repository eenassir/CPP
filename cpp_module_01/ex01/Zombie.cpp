/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:23:59 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/27 15:33:14 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::~Zombie(void)
{
	std::cout <<"\""<<name<<"\" is destroyed\n";
}
void Zombie::announce(void)
{
	if (name != "FOO")
		std::cout <<"<"<<name<<">"<<"BraiiiiiiinnnzzzZ...\n";
	else
		std::cout <<name<<"BraiiiiiiinnnzzzZ...\n";
}
void Zombie::get_name(std::string na)
{
	name = na;
}