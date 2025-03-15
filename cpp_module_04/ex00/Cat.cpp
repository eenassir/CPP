/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:01:39 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/12 02:44:28 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Cat::Cat() : Animal()
{
	std::cout <<"The Cat_default constructor is called"<<std::endl;
	type = "Cat"; 
}

Cat::Cat(const Cat &mem) : Animal()
{
	std::cout <<"The Cat copy constructor is called"<<std::endl;
	*this = mem;
}

Cat &Cat::operator=(const Cat &mem)
{
	if (this == &mem)
		return (*this);
	this->type = mem.type;
	std::cout <<"The Cat copy assignement is called"<<std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout <<"The Cat destructor is called"<<std::endl;
}

void Cat::makeSound() const
{
	std::cout <<"Moew Moew"<<std::endl;
}