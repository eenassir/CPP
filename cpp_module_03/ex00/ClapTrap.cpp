/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:16:24 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/08 01:10:48 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

ClapTrap::ClapTrap() : _name("Clap_default"), _hitPoints(10), _energiePoints(10), _attackDamage(0)
{
	std::cout <<"ClapTrap default constructor is called!"<<std::endl;
}

ClapTrap::ClapTrap(const std::string &_name) : _name(_name), _hitPoints(10), _energiePoints(10), _attackDamage(0)
{
	std::cout <<"ClapTrap "<<this->_name<<" is created!"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &mem)
{
	std::cout <<"ClapTrap copy constructor is called!"<<std::endl;
	*this = mem;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &mem)
{
	if (this == &mem)
		return (*this);
	this->_name = mem._name;
	this->_hitPoints = mem._hitPoints;
	this->_energiePoints = mem._energiePoints;
	this->_attackDamage = mem._attackDamage;
	std::cout <<"The ClapTrap copy assignement is called!"<<std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout <<"ClapTrap "<<this->_name<<" is destroyed!"<<std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints > 0 && _energiePoints > 0)
	{
		_energiePoints--;
		std::cout <<"ClapTrap "<<_name<<" attacks "<<target<<", causing "<<_attackDamage<<" points of damage!"<<std::endl;
	}
	else if ((int)_energiePoints <= 0)
		std::cout << "ClapTrap "<<_name<<" cannot attack because it have no energie points!"<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)(_hitPoints - amount) >= 0)
	{
		_hitPoints -= amount;
		_attackDamage = amount;
		std::cout <<"ClapTrap "<<_name<<" lose "<<_attackDamage<<" points!"<<std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energiePoints > 0)
	{
		_energiePoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap "<<_name<<" is repaired itself get "<<amount<<" hit_points!" << std::endl;
	}
	else
		std::cout <<"ClapTrap "<<_name<< " can't repaire itself because have no energie points!"<<std::endl;
}