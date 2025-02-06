/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:33:56 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/27 13:15:23 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
	Zombie *new_Zombie1;
	Zombie *new_Zombie2;

	new_Zombie1 = newZombie("FOO");
	new_Zombie2 = newZombie("BOO");
	new_Zombie1->announce();
	new_Zombie2->announce();
	randomChump("JACK");
	delete new_Zombie1;
	delete new_Zombie2;
}