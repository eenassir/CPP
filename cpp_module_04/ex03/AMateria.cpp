/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:54:54 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 17:29:19 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("Default") {}

AMateria::AMateria(const AMateria &mem)
{
	*this = mem;
}

AMateria &AMateria::operator=(const AMateria &mem)
{
	if (this == &mem)
		return (*this);
	this->type = mem.getType();
	return (*this);
}

AMateria::~AMateria(){}

AMateria::AMateria(std::string const & type) : type(type){}

std::string const &AMateria::getType() const
{
	return (this->type);
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout <<" "<<target.getName()<<" "<<std::endl;
}
