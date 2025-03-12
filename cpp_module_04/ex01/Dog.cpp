/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:01:18 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/12 02:25:03 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Dog::Dog() : Animal()
{
	std::cout <<"The Dog_default constructor is called" <<std::endl;
	this->ptr = new Brain();
	type = "Dog";
}

Dog::Dog(const Dog &mem) : Animal(mem)
{
	std::cout <<"The Dog copy constructor called"<<std::endl;
	this->ptr = NULL;
	*this = mem;
}

Dog &Dog::operator=(const Dog &mem)
{
	if (this == &mem)
		return (*this);
	this->type = mem.type;
	Animal::operator=(mem);
	if (this->ptr)
		delete(this->ptr);
	this->ptr = new Brain(*mem.ptr);
	std::cout <<"The Dog copy assignemet called"<<std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout <<"The Dog destructor is called"<<std::endl;
	delete(this->ptr);
}

void Dog::makeSound() const
{
	std::cout <<"woof woof"<<std::endl;
}

Brain *Dog::getBrain() const
{
	return (this->ptr);
}