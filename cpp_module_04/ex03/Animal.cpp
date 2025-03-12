/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:48:20 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/11 02:23:18 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Animal::Animal() : type("Animal_def")
{
	std::cout <<"The Animal_default constructor called" <<std::endl;
}

Animal::Animal(const Animal &mem)
{
	std::cout <<"The Animal copy constructor called" <<std::endl;
	*this = mem;
}

Animal &Animal::operator=(const Animal &mem)
{
	if (this == &mem)
		return (*this);
	this->type = mem.type;
	std::cout <<"The Animal copy assignement called"<<std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout <<"The Animal destructor called" <<std::endl;
}

void Animal::makeSound(void) const
{
	std::cout <<"* Generic animal sound *"<<std::endl;
}

std::string Animal::getType() const
{
	return (type);
}