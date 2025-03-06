/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:51:47 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/06 18:33:20 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

DiamondTrap::DiamondTrap() : ClapTrap() {}

DiamondTrap::DiamondTrap(const std::string &_name) : ClapTrap(_name + "_clap_name"), ScavTrap(), FragTrap(), _name(_name)
{
	std::cout <<"DiamondTrap "<<_name<<" is created"<<std::endl;
	HitPoints = FragTrap::HitPoints;
	EnergiePoints = ScavTrap::save;
	AttackDamage = FragTrap::AttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &mem)
{
	*this = mem;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &mem)
{
	if (this == &mem)
		return (*this);
	this->_name = mem._name;
	this->HitPoints = mem.HitPoints;
	this->EnergiePoints = mem.EnergiePoints;
	this->AttackDamage = mem.AttackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout <<"DiamondTrap "<<_name<<" is destroyed!"<<std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout <<"DiamondTrap :I am "<<DiamondTrap::_name<<std::endl;
	std::cout <<"ClapTrap :I am "<<ClapTrap::_name <<std::endl;	
}