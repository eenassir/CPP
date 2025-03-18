/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:01:18 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/17 14:14:51 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Dog::Dog() : Animal()
{
	std::cout <<"The Dog_default constructor is called" <<std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &mem) : Animal()
{
	std::cout <<"The Dog copy constructor called"<<std::endl;
	*this = mem;
}

Dog &Dog::operator=(const Dog &mem)
{
	if (this == &mem)
		return (*this);
	this->type = mem.type;
	std::cout <<"The Dog copy assignemet called"<<std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout <<"The Dog destructor is called"<<std::endl;
}

void Dog::makeSound() const
{
	std::cout <<"woof woof"<<std::endl;
}