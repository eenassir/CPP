/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:01:18 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/18 11:14:53 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Dog::Dog() : Animal()
{
	std::cout <<"The Dog_default constructor is called" <<std::endl;
	ptr = new Brain;
	type = "Dog";
}

Dog::Dog(const Dog &mem) : Animal(mem)
{
	std::cout <<"The Dog copy constructor called"<<std::endl;
	this->ptr = NULL;
	this->ptr = new(Brain);
	// *this = mem;
	*(this->ptr) = *(mem.ptr);
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