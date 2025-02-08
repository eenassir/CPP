/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:46:01 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/08 23:44:13 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie * newZombie(std::string name)
{
	Zombie *new_z = new Zombie();
	new_z->set_name(name);
	
	return (new_z);
}