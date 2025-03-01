/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:16:24 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/14 00:16:25 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string _name) : Name(_name),HitPoints(10), EnergiePoints(10), AttackDamage(0) 
{
	std::cout <<"Now we have a new Claptrap named : " << this->Name<<"!"<<std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &mem)
{
	*this = mem;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &mem)
{
	if (this == &mem)
		return (*this);
	*this = mem;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout <<this->Name<<" is destroyed!"<<std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (HitPoints > 0 && EnergiePoints > 0)
	{
		EnergiePoints--;
		std::cout <<"ClapTrap "<<Name<<" attacks "<<target<<", causing "<<AttackDamage<<" points of damage!"<<std::endl;
	}
	else
		std::cout << "ClapTrap "<<Name<<" cannot attack because it's not have any hit points : "<<HitPoints<<" energie points : "<<EnergiePoints << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::stringstream str;
	int result = 0;

	str << (int)amount;
	str >> result;
	if (result < 0)
	{
		std::cout <<"The amount not valid. reset amount to 0!"<<std::endl;
		amount = 0;
	}
	if (HitPoints > 0)
	{
		HitPoints -= amount;
		if (HitPoints <= 0)
			HitPoints = 0;
		std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!" << std::endl;
	}
	else
		std::cout <<"The hit points is full for claptrap "<<Name<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::stringstream str;
	int result = 0;

	str << (int)amount;
	str >> result;
	if (result < 0)
	{
		std::cout <<"The amount not valid. reset amount to 0!"<<std::endl;
		amount = 0;
	}
	if (EnergiePoints > 0 && HitPoints > 0)
	{
		EnergiePoints--;
		HitPoints = amount;
		std::cout << "ClapTrap " << Name << " is repaired by " << amount << " points!" << std::endl;
	}
	else
		std::cout <<"The hit points is full for claptrap "<<Name<<std::endl;
}