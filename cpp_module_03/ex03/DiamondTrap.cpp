/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:51:47 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/07 15:45:39 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

DiamondTrap::DiamondTrap() : _name("Diamond_default")
{
	_hitPoints = FragTrap::_hitPoints;
	_energiePoints = ScavTrap::_copy_energiePoints;
	_attackDamage = FragTrap::_attackDamage;
	std ::cout<<"The DiamondTrap default constructor is called" <<std::endl;
}

DiamondTrap::DiamondTrap(const std::string &_name) : ClapTrap(_name + "_clap_name"), _name(_name)
{
	std::cout <<"DiamondTrap "<<_name<<" is created"<<std::endl;
	_hitPoints = FragTrap::_hitPoints;
	_energiePoints = ScavTrap::_copy_energiePoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &mem) : ClapTrap(mem), ScavTrap(mem), FragTrap(mem)
{
	*this = mem;
	std ::cout<<"The DiamondTrap copy constructor is called" <<std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &mem)
{
	if (this == &mem)
		return (*this);
	this->_name = mem._name;
	this->_hitPoints = mem._hitPoints;
	this->_energiePoints = mem._energiePoints;
	this->_attackDamage = mem._attackDamage;
	std::cout <<"The DiamondTrap copy assignement is called"<<std::endl;
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