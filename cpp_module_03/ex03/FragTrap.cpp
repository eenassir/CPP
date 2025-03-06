/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:24:20 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/06 18:31:47 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

FragTrap::FragTrap() : ClapTrap()
{
	HitPoints = 100;
	EnergiePoints = 100;
	AttackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	HitPoints = 100;
	EnergiePoints = 100;
	AttackDamage = 30;
	std::cout <<"FragTrap "<<this->_name<<" is created!"<<std::endl;
}

FragTrap::FragTrap(const FragTrap &mem)
{
	*this = mem;
}
FragTrap &FragTrap::operator=(const FragTrap &mem)
{
	if (this == &mem)
		return (*this);
	this->_name = mem._name;
	this->HitPoints = mem.HitPoints;
	this->EnergiePoints = mem.EnergiePoints;
	this->AttackDamage = mem.AttackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout <<"FragTrap "<<_name<<" is destroyed!"<<std::endl ;
}

void FragTrap::highFivesGuys()
{
	std::cout <<"FragTrap : high_fives"<<std::endl;
}