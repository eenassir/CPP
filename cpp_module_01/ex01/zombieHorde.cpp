/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:24:09 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/27 15:27:04 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (nullptr);
	Zombie *zombie = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombie[i].get_name(name);
	return (zombie);
}