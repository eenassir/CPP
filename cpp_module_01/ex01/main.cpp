/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:33:14 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/08 23:49:40 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
	Zombie *newZombie;
	int nbr_zombie = 5;

	newZombie = zombieHorde(5, "Zombie");
	if (!newZombie)
		return(std::cout <<"failed to create\n", 1);
	for (int i = 0; i < nbr_zombie; i++)
		newZombie[i].announce();
	std::cout <<"\n";
	delete[] newZombie;
	return (0);
}