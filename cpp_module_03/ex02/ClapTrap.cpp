/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:21:55 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/06 02:18:44 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(const std::string &_name) : Name(_name), HitPoints(10), EnergiePoints(10), AttackDamage(0)
{
	std::cout <<"ClapTrap "<<this->Name<<" is created!"<<std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &mem)
{
	*this = mem;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &mem)
{
	if (this == &mem)
		return (*this);
	this->Name = mem.Name;
	this->HitPoints = mem.HitPoints;
	this->EnergiePoints = mem.EnergiePoints;
	this->AttackDamage = mem.AttackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout <<"ClapTrap "<<this->Name<<" is destroyed!"<<std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (HitPoints > 0 && EnergiePoints > 0)
	{
		EnergiePoints--;
		std::cout <<"ClapTrap "<<Name<<" attacks "<<target<<", causing "<<AttackDamage<<" points of damage!"<<std::endl;
	}
	else if ((int)EnergiePoints <= 0)
		std::cout << "ClapTrap "<<Name<<" cannot attack because it have no energie points"<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (HitPoints > 0)
	{
		HitPoints -= amount;
		AttackDamage = amount;
		std::cout <<"ClapTrap "<<Name<<" lose "<<AttackDamage<<" points"<<std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (EnergiePoints > 0)
	{
		EnergiePoints--;
		HitPoints +=amount;
		std::cout << "ClapTrap "<<Name<<" is repaired itself get "<<amount<<" hit_points!" << std::endl;
	}
	else
		std::cout <<"ClapTrap "<<Name<< " can't repaire itself because have no energie points"<<std::endl;
}