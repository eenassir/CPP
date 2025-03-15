/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:26:56 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 17:44:01 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

Character::Character(){}

Character::Character(const Character &mem)
{
	
}

Character &Character::operator=(const Character &mem)
{
	
}

std::string const &Character::getName() const
{
	
}

std::string const &Character::getType() const
{
	
}

void Character::equip(AMateria *m)
{
	
}

void Character::unequip(int idx)
{
	
}

void Character::use(int idx, ICharacter &target)
{
	
}

Character::~Character()
{
	for (int i = 0; i++; i < 4)
		delete(slot[i]);
}
