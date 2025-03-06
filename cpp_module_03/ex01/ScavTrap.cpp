/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:22:05 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/06 00:19:54 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

ScavTrap::ScavTrap() : ClapTrap()
{
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	HitPoints = 100;
	EnergiePoints = 50;
	AttackDamage = 20;
	std::cout <<"ScavTrap "<<this->Name<<" is created!"<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &mem)
{
	*this = mem;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &mem)
{
	if (this == &mem)
		return (*this);
	this->Name = mem.Name;
	this->HitPoints = mem.HitPoints;
	this->EnergiePoints = mem.EnergiePoints;
	this->AttackDamage = mem.AttackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout <<"ScavTrap "<<Name<<" is destroyed\n" ;
}

void ScavTrap::attack(const std::string &target)
{
	if (HitPoints > 0 && EnergiePoints > 0)
	{
		EnergiePoints--;
		std::cout <<"ScavTrap "<<Name<<" attacks "<<target<<", causing "<<AttackDamage<<" points of damage!"<<std::endl;
	}
	else if ((int)EnergiePoints <= 0)
		std::cout << "ScavTrap "<<Name<<" cannot attack because it have no energie points"<< std::endl;
}

void ScavTrap::guardGate()
{
	std::cout <<"ScavTrap "<<Name<<" is now in Gate keeper mode\n";
}