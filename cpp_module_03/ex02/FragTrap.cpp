/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:24:20 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/08 00:54:56 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

FragTrap::FragTrap() : ClapTrap()
{
	_name = "Frag_default";
	_hitPoints = 100;
	_energiePoints = 100;
	_attackDamage = 30;
	std::cout <<"The FragTrap default constructor is called"<<std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energiePoints = 100;
	_attackDamage = 30;
	std::cout <<"FragTrap "<<this->_name<<" is created!"<<std::endl;
}

FragTrap::FragTrap(const FragTrap &mem) : ClapTrap(mem)
{
	std::cout <<"The FragTrap copy constructor is called"<<std::endl;
	*this = mem;
}

FragTrap &FragTrap::operator=(const FragTrap &mem)
{
	if (this == &mem)
		return (*this);
	this->_name = mem._name;
	this->_hitPoints = mem._hitPoints;
	this->_energiePoints = mem._energiePoints;
	this->_attackDamage = mem._attackDamage;
	std::cout <<"The FragTrap copy assignement is called"<<std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout <<"FragTrap "<<_name<<" is destroyed"<<std::endl ;
}

void FragTrap::highFivesGuys()
{
	std::cout <<"FragTrap : high_fives"<<std::endl;
}