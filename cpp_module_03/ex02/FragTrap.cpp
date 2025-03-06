/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:24:20 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/06 01:53:06 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

FragTrap::FragTrap() : ClapTrap()
{
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	HitPoints = 100;
	EnergiePoints = 50;
	AttackDamage = 20;
	std::cout <<"FragTrap "<<this->Name<<" is created!"<<std::endl;
}

FragTrap::FragTrap(const FragTrap &mem)
{
	*this = mem;
}
FragTrap &FragTrap::operator=(const FragTrap &mem)
{
	if (this == &mem)
		return (*this);
	this->Name = mem.Name;
	this->HitPoints = mem.HitPoints;
	this->EnergiePoints = mem.EnergiePoints;
	this->AttackDamage = mem.AttackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout <<"FragTrap "<<Name<<" is destroyed"<<std::endl ;
}

void FragTrap::highFivesGuys()
{
	std::cout <<"FragTrap : high_fives"<<std::endl;
}