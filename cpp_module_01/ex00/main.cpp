/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:33:56 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/09 00:05:56 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
	Zombie *new_Zombie1;
	Zombie *new_Zombie2;

	randomChump("MAKEL");
	randomChump("JACK");
	new_Zombie1 = newZombie("FOO");
	new_Zombie2 = newZombie("BOO");
	new_Zombie1->announce();
	new_Zombie2->announce();
	delete new_Zombie1;
	delete new_Zombie2;
}