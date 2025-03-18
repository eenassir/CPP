/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:37:47 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/17 23:15:02 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice(const Ice &mem)
{
	*this = mem;
}

Ice &Ice::operator=(const Ice &mem)
{
	if (this == &mem)
		return (*this);
	this->type = mem.type;
	return (*this);	
}

Ice::~Ice(){}

Ice::Ice(const std::string &type)
{
	this->type = type;
}

AMateria *Ice::clone() const
{
	AMateria *mem = new(Ice);
	return (mem);
}

void Ice::use(ICharacter &target)
{
	std::cout <<"* shoots an ice bolt at "<<target.getName()<< " *" <<  std::endl;
}