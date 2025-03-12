/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:25:55 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/11 02:50:39 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

WrongAnimal::WrongAnimal()
{
	std::cout <<"The WrongAnimal_default constructor called"<<std::endl;
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &mem)
{
	std::cout <<"The WrongAnimal copy constructor called"<<std::endl;
	*this = mem;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &mem)
{
	if (this == &mem)
		return (*this);
	std::cout <<"The WrongAnimal copy assignement called"<<std::endl;
	this->type = mem.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout <<"The WrongAnimal destructor called"<<std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (type);
}

void WrongAnimal::makeSound() const
{
	std::cout <<"* Generic wrong animal sound  *"<<std::endl;	
}