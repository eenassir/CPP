/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:22:05 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/07 00:33:48 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energiePoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energiePoints = 50;
	_attackDamage = 20;
	std::cout <<"ScavTrap "<<this->_name<<" is created!"<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &mem) : ClapTrap(mem)
{
	*this = mem;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &mem)
{
	if (this == &mem)
		return (*this);
	this->_name = mem._name;
	this->_hitPoints = mem._hitPoints;
	this->_energiePoints = mem._energiePoints;
	this->_attackDamage = mem._attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout <<"ScavTrap "<<_name<<" is destroyed\n" ;
}

void ScavTrap::attack(const std::string &target)
{
	if (_hitPoints > 0 && _energiePoints > 0)
	{
		_energiePoints--;
		std::cout <<"ScavTrap "<<_name<<" attacks "<<target<<", causing "<<_attackDamage<<" points of damage!"<<std::endl;
	}
	else if ((int)_energiePoints <= 0)
		std::cout << "ScavTrap "<<_name<<" cannot attack because it have no energie points"<< std::endl;
}

void ScavTrap::guardGate()
{
	std::cout <<"ScavTrap "<<_name<<" is now in Gate keeper mode\n";
}