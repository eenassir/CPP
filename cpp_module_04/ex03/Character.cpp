/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:26:56 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/18 00:20:08 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

Character::Character() : name ("")
{
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;	
}

Character::Character(const std::string &Name) : name(Name)
{
	for (int i = 0; i < 4; i++){
		this->slot[i] = NULL;
	}
}

Character::Character(const Character &mem)
{
	for (int i = 0; i < 4 ; i++)
		this->slot[i] = NULL;
	for (int i = 0; i < 4; i++){
		if (mem.slot[i] != NULL)
			this->slot[i] = mem.slot[i]->clone();
	}
}

Character &Character::operator=(const Character &mem)
{
	if (this != &mem)
	{
		this->name = mem.name;
		for (int i = 0; i < 4; i++)
		{
			delete this->slot[i];
			this->slot[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i] != NULL){}
			this->slot[i] = mem.slot[i]->clone();
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i] == m)
			return;
		if (this->slot[i] == NULL)
		{
			this->slot[i] = m->clone();
			break;
		}
	}
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->slot[idx] != NULL)
	{
		if (this->saved_slots[idx] != NULL)
			delete saved_slots[idx];
		this->saved_slots[idx] = slot[idx];
        this->slot[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->slot[idx] != NULL)
        this->slot[idx]->use(target);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i] != NULL)
			delete this->slot[i];
		if (this->saved_slots[i] != NULL)
			delete(saved_slots[i]);
	}
}
