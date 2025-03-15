/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:35:53 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 17:37:44 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

Cure::Cure()
{
	type = "cure";
}

Cure::Cure(const Cure &mem)
{
	*this = mem;	
}

Cure &Cure::operator=(const Cure &mem)
{
	if (this == &mem)
		return (*this);
	this->type = mem.getType();
	return (*this);
}

Cure::~Cure(){}

Cure::Cure(const std::string &type)
{
	this->type = type;
}

AMateria *Cure::clone() const
{
	AMateria *mem = new(Cure);
	return (mem);
}

void Cure::use(ICharacter &target)
{
	std::cout <<"* shoots an ice bolt at "<<target.getName()<<std::endl;
}

