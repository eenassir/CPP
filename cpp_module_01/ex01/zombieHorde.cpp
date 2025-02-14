/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:24:09 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/09 08:14:34 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	Zombie *zombie = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombie[i].set_name(name);
	return (zombie);
}